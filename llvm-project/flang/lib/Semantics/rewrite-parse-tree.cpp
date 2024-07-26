//===-- lib/Semantics/rewrite-parse-tree.cpp ------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "rewrite-parse-tree.h"
#include "rewrite-directives.h"
#include "flang/Common/indirection.h"
#include "flang/Parser/parse-tree-visitor.h"
#include "flang/Parser/parse-tree.h"
#include "flang/Parser/tools.h"
#include "flang/Semantics/scope.h"
#include "flang/Semantics/semantics.h"
#include "flang/Semantics/symbol.h"
#include "flang/Semantics/tools.h"
#include <list>

namespace Fortran::semantics {

using namespace parser::literals;

/// Convert misidentified statement functions to array element assignments
/// or pointer-valued function result assignments.
/// Convert misidentified format expressions to namelist group names.
/// Convert misidentified character variables in I/O units to integer
/// unit number expressions.
/// Convert misidentified named constants in data statement values to
/// initial data targets
class RewriteMutator {
public:
  RewriteMutator(SemanticsContext &context)
      : errorOnUnresolvedName_{!context.AnyFatalError()},
        messages_{context.messages()} {}

  // Default action for a parse tree node is to visit children.
  template <typename T> bool Pre(T &) { return true; }
  template <typename T> void Post(T &) {}

  void Post(parser::Name &);
  void Post(parser::SpecificationPart &);
  bool Pre(parser::ExecutionPart &);
  void Post(parser::ReadStmt &);
  void Post(parser::WriteStmt &);

  // Name resolution yet implemented:
  // TODO: Can some/all of these now be enabled?
  bool Pre(parser::EquivalenceStmt &) { return false; }
  bool Pre(parser::Keyword &) { return false; }
  bool Pre(parser::EntryStmt &) { return false; }
  bool Pre(parser::CompilerDirective &) { return false; }

  // Don't bother resolving names in end statements.
  bool Pre(parser::EndBlockDataStmt &) { return false; }
  bool Pre(parser::EndFunctionStmt &) { return false; }
  bool Pre(parser::EndInterfaceStmt &) { return false; }
  bool Pre(parser::EndModuleStmt &) { return false; }
  bool Pre(parser::EndMpSubprogramStmt &) { return false; }
  bool Pre(parser::EndProgramStmt &) { return false; }
  bool Pre(parser::EndSubmoduleStmt &) { return false; }
  bool Pre(parser::EndSubroutineStmt &) { return false; }
  bool Pre(parser::EndTypeStmt &) { return false; }

private:
  using stmtFuncType =
      parser::Statement<common::Indirection<parser::StmtFunctionStmt>>;
  bool errorOnUnresolvedName_{true};
  parser::Messages &messages_;
  std::list<stmtFuncType> stmtFuncsToConvert_;
};

// Check that name has been resolved to a symbol
void RewriteMutator::Post(parser::Name &name) {
  if (!name.symbol && errorOnUnresolvedName_) {
    messages_.Say(name.source, "Internal: no symbol found for '%s'"_err_en_US,
        name.source);
  }
}

static bool ReturnsDataPointer(const Symbol &symbol) {
  if (const Symbol * funcRes{FindFunctionResult(symbol)}) {
    return IsPointer(*funcRes) && !IsProcedure(*funcRes);
  } else if (const auto *generic{symbol.detailsIf<GenericDetails>()}) {
    for (auto ref : generic->specificProcs()) {
      if (ReturnsDataPointer(*ref)) {
        return true;
      }
    }
  }
  return false;
}

// Find mis-parsed statement functions and move to stmtFuncsToConvert_ list.
void RewriteMutator::Post(parser::SpecificationPart &x) {
  auto &list{std::get<std::list<parser::DeclarationConstruct>>(x.t)};
  for (auto it{list.begin()}; it != list.end();) {
    bool isAssignment{false};
    if (auto *stmt{std::get_if<stmtFuncType>(&it->u)}) {
      if (const Symbol *
          symbol{std::get<parser::Name>(stmt->statement.value().t).symbol}) {
        const Symbol &ultimate{symbol->GetUltimate()};
        isAssignment =
            ultimate.has<ObjectEntityDetails>() || ReturnsDataPointer(ultimate);
        if (isAssignment) {
          stmtFuncsToConvert_.emplace_back(std::move(*stmt));
        }
      }
    }
    if (isAssignment) {
      it = list.erase(it);
    } else {
      ++it;
    }
  }
}

// Insert converted assignments at start of ExecutionPart.
bool RewriteMutator::Pre(parser::ExecutionPart &x) {
  auto origFirst{x.v.begin()}; // insert each elem before origFirst
  for (stmtFuncType &sf : stmtFuncsToConvert_) {
    auto stmt{sf.statement.value().ConvertToAssignment()};
    stmt.source = sf.source;
    x.v.insert(origFirst,
        parser::ExecutionPartConstruct{
            parser::ExecutableConstruct{std::move(stmt)}});
  }
  stmtFuncsToConvert_.clear();
  return true;
}

// When a namelist group name appears (without NML=) in a READ or WRITE
// statement in such a way that it can be misparsed as a format expression,
// rewrite the I/O statement's parse tree node as if the namelist group
// name had appeared with NML=.
template <typename READ_OR_WRITE>
void FixMisparsedUntaggedNamelistName(READ_OR_WRITE &x) {
  if (x.iounit && x.format &&
      std::holds_alternative<parser::Expr>(x.format->u)) {
    if (const parser::Name * name{parser::Unwrap<parser::Name>(x.format)}) {
      if (name->symbol && name->symbol->GetUltimate().has<NamelistDetails>()) {
        x.controls.emplace_front(parser::IoControlSpec{std::move(*name)});
        x.format.reset();
      }
    }
  }
}

// READ(CVAR) [, ...] will be misparsed as UNIT=CVAR; correct
// it to READ CVAR [,...] with CVAR as a format rather than as
// an internal I/O unit for unformatted I/O, which Fortran does
// not support.
void RewriteMutator::Post(parser::ReadStmt &x) {
  if (x.iounit && !x.format && x.controls.empty()) {
    if (auto *var{std::get_if<parser::Variable>(&x.iounit->u)}) {
      const parser::Name &last{parser::GetLastName(*var)};
      DeclTypeSpec *type{last.symbol ? last.symbol->GetType() : nullptr};
      if (type && type->category() == DeclTypeSpec::Character) {
        x.format = common::visit(
            [](auto &&indirection) {
              return parser::Expr{std::move(indirection)};
            },
            std::move(var->u));
        x.iounit.reset();
      }
    }
  }
  FixMisparsedUntaggedNamelistName(x);
}

void RewriteMutator::Post(parser::WriteStmt &x) {
  FixMisparsedUntaggedNamelistName(x);
}

bool RewriteParseTree(SemanticsContext &context, parser::Program &program) {
  RewriteMutator mutator{context};
  parser::Walk(program, mutator);
  return !context.AnyFatalError() && RewriteOmpParts(context, program);
}

} // namespace Fortran::semantics
