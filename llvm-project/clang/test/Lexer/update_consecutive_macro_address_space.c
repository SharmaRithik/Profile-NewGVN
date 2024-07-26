// RUN: %clang -cc1 -print-stats %s 2>&1 | FileCheck %s
// CHECK: 7 local SLocEntries allocated
//
// Verify that the macro arg expansion is split to two file ids, we have 7 file
// ids rather than 6:
//   0: invalid file id
//   1: main file
//   2: builtin file
//   3: scratch space for __GCC_[CON|DE]STRUCTIVE_SIZE macros
//   4: macro expansion for X
//   5: macro arg expansions for 1
//   6: macro arg expansions for == 2
#define X(x) (int)(x);
void func() {
  X(1
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
== 2);
}