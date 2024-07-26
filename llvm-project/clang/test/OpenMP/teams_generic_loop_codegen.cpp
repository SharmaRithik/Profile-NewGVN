// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -emit-llvm %s -o - | FileCheck %s --check-prefix=IR

// Check same results after serialization round-trip
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -emit-pch -o %t %s
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -include-pch %t -emit-llvm %s -o - | FileCheck %s --check-prefix=IR-PCH

// expected-no-diagnostics

#ifndef HEADER
#define HEADER
int foo() {
  int i;
  int j;
  int sum[10][10];

  #pragma omp teams loop reduction(+:sum) collapse(2) bind(parallel) \
      order(concurrent) lastprivate(j)
  for(i=0; i<10; i++)
    for(j=0; j<10; j++)
      sum[i][j] += i;

  return 0;
}
#endif
// IR-LABEL: define {{[^@]+}}@_Z3foov
// IR-SAME: () #[[ATTR0:[0-9]+]] {
// IR-NEXT:  entry:
// IR-NEXT:    [[I:%.*]] = alloca i32, align 4
// IR-NEXT:    [[J:%.*]] = alloca i32, align 4
// IR-NEXT:    [[SUM:%.*]] = alloca [10 x [10 x i32]], align 16
// IR-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_teams(ptr @[[GLOB3:[0-9]+]], i32 2, ptr @_Z3foov.omp_outlined, ptr [[J]], ptr [[SUM]])
// IR-NEXT:    ret i32 0
//
//
// IR-LABEL: define {{[^@]+}}@_Z3foov.omp_outlined
// IR-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[J:%.*]], ptr noundef nonnull align 4 dereferenceable(400) [[SUM:%.*]]) #[[ATTR1:[0-9]+]] {
// IR-NEXT:  entry:
// IR-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// IR-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// IR-NEXT:    [[J_ADDR:%.*]] = alloca ptr, align 8
// IR-NEXT:    [[SUM_ADDR:%.*]] = alloca ptr, align 8
// IR-NEXT:    [[SUM1:%.*]] = alloca [10 x [10 x i32]], align 16
// IR-NEXT:    [[DOTOMP_IV:%.*]] = alloca i32, align 4
// IR-NEXT:    [[TMP:%.*]] = alloca i32, align 4
// IR-NEXT:    [[_TMP2:%.*]] = alloca i32, align 4
// IR-NEXT:    [[DOTOMP_COMB_LB:%.*]] = alloca i32, align 4
// IR-NEXT:    [[DOTOMP_COMB_UB:%.*]] = alloca i32, align 4
// IR-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i32, align 4
// IR-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4
// IR-NEXT:    [[J3:%.*]] = alloca i32, align 4
// IR-NEXT:    [[I:%.*]] = alloca i32, align 4
// IR-NEXT:    [[J4:%.*]] = alloca i32, align 4
// IR-NEXT:    [[DOTOMP_REDUCTION_RED_LIST:%.*]] = alloca [1 x ptr], align 8
// IR-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// IR-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// IR-NEXT:    store ptr [[J]], ptr [[J_ADDR]], align 8
// IR-NEXT:    store ptr [[SUM]], ptr [[SUM_ADDR]], align 8
// IR-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[J_ADDR]], align 8
// IR-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[SUM_ADDR]], align 8
// IR-NEXT:    [[ARRAY_BEGIN:%.*]] = getelementptr inbounds [10 x [10 x i32]], ptr [[SUM1]], i32 0, i32 0, i32 0
// IR-NEXT:    [[TMP2:%.*]] = getelementptr i32, ptr [[ARRAY_BEGIN]], i64 100
// IR-NEXT:    [[OMP_ARRAYINIT_ISEMPTY:%.*]] = icmp eq ptr [[ARRAY_BEGIN]], [[TMP2]]
// IR-NEXT:    br i1 [[OMP_ARRAYINIT_ISEMPTY]], label [[OMP_ARRAYINIT_DONE:%.*]], label [[OMP_ARRAYINIT_BODY:%.*]]
// IR:       omp.arrayinit.body:
// IR-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST:%.*]] = phi ptr [ [[ARRAY_BEGIN]], [[ENTRY:%.*]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT:%.*]], [[OMP_ARRAYINIT_BODY]] ]
// IR-NEXT:    store i32 0, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 4
// IR-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT]] = getelementptr i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], i32 1
// IR-NEXT:    [[OMP_ARRAYCPY_DONE:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT]], [[TMP2]]
// IR-NEXT:    br i1 [[OMP_ARRAYCPY_DONE]], label [[OMP_ARRAYINIT_DONE]], label [[OMP_ARRAYINIT_BODY]]
// IR:       omp.arrayinit.done:
// IR-NEXT:    store i32 0, ptr [[DOTOMP_COMB_LB]], align 4
// IR-NEXT:    store i32 99, ptr [[DOTOMP_COMB_UB]], align 4
// IR-NEXT:    store i32 1, ptr [[DOTOMP_STRIDE]], align 4
// IR-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST]], align 4
// IR-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// IR-NEXT:    [[TMP4:%.*]] = load i32, ptr [[TMP3]], align 4
// IR-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB1:[0-9]+]], i32 [[TMP4]], i32 92, ptr [[DOTOMP_IS_LAST]], ptr [[DOTOMP_COMB_LB]], ptr [[DOTOMP_COMB_UB]], ptr [[DOTOMP_STRIDE]], i32 1, i32 1)
// IR-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// IR-NEXT:    [[CMP:%.*]] = icmp sgt i32 [[TMP5]], 99
// IR-NEXT:    br i1 [[CMP]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// IR:       cond.true:
// IR-NEXT:    br label [[COND_END:%.*]]
// IR:       cond.false:
// IR-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// IR-NEXT:    br label [[COND_END]]
// IR:       cond.end:
// IR-NEXT:    [[COND:%.*]] = phi i32 [ 99, [[COND_TRUE]] ], [ [[TMP6]], [[COND_FALSE]] ]
// IR-NEXT:    store i32 [[COND]], ptr [[DOTOMP_COMB_UB]], align 4
// IR-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTOMP_COMB_LB]], align 4
// IR-NEXT:    store i32 [[TMP7]], ptr [[DOTOMP_IV]], align 4
// IR-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// IR:       omp.inner.for.cond:
// IR-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// IR-NEXT:    [[CMP5:%.*]] = icmp sle i32 [[TMP8]], [[TMP9]]
// IR-NEXT:    br i1 [[CMP5]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// IR:       omp.inner.for.body:
// IR-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-NEXT:    [[DIV:%.*]] = sdiv i32 [[TMP10]], 10
// IR-NEXT:    [[MUL:%.*]] = mul nsw i32 [[DIV]], 1
// IR-NEXT:    [[ADD:%.*]] = add nsw i32 0, [[MUL]]
// IR-NEXT:    store i32 [[ADD]], ptr [[I]], align 4
// IR-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-NEXT:    [[TMP12:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-NEXT:    [[DIV6:%.*]] = sdiv i32 [[TMP12]], 10
// IR-NEXT:    [[MUL7:%.*]] = mul nsw i32 [[DIV6]], 10
// IR-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP11]], [[MUL7]]
// IR-NEXT:    [[MUL8:%.*]] = mul nsw i32 [[SUB]], 1
// IR-NEXT:    [[ADD9:%.*]] = add nsw i32 0, [[MUL8]]
// IR-NEXT:    store i32 [[ADD9]], ptr [[J3]], align 4
// IR-NEXT:    [[TMP13:%.*]] = load i32, ptr [[I]], align 4
// IR-NEXT:    [[TMP14:%.*]] = load i32, ptr [[I]], align 4
// IR-NEXT:    [[IDXPROM:%.*]] = sext i32 [[TMP14]] to i64
// IR-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [10 x [10 x i32]], ptr [[SUM1]], i64 0, i64 [[IDXPROM]]
// IR-NEXT:    [[TMP15:%.*]] = load i32, ptr [[J3]], align 4
// IR-NEXT:    [[IDXPROM10:%.*]] = sext i32 [[TMP15]] to i64
// IR-NEXT:    [[ARRAYIDX11:%.*]] = getelementptr inbounds [10 x i32], ptr [[ARRAYIDX]], i64 0, i64 [[IDXPROM10]]
// IR-NEXT:    [[TMP16:%.*]] = load i32, ptr [[ARRAYIDX11]], align 4
// IR-NEXT:    [[ADD12:%.*]] = add nsw i32 [[TMP16]], [[TMP13]]
// IR-NEXT:    store i32 [[ADD12]], ptr [[ARRAYIDX11]], align 4
// IR-NEXT:    br label [[OMP_BODY_CONTINUE:%.*]]
// IR:       omp.body.continue:
// IR-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// IR:       omp.inner.for.inc:
// IR-NEXT:    [[TMP17:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-NEXT:    [[ADD13:%.*]] = add nsw i32 [[TMP17]], 1
// IR-NEXT:    store i32 [[ADD13]], ptr [[DOTOMP_IV]], align 4
// IR-NEXT:    br label [[OMP_INNER_FOR_COND]]
// IR:       omp.inner.for.end:
// IR-NEXT:    br label [[OMP_LOOP_EXIT:%.*]]
// IR:       omp.loop.exit:
// IR-NEXT:    [[TMP18:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// IR-NEXT:    [[TMP19:%.*]] = load i32, ptr [[TMP18]], align 4
// IR-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP19]])
// IR-NEXT:    [[TMP20:%.*]] = load i32, ptr [[DOTOMP_IS_LAST]], align 4
// IR-NEXT:    [[TMP21:%.*]] = icmp ne i32 [[TMP20]], 0
// IR-NEXT:    br i1 [[TMP21]], label [[DOTOMP_LASTPRIVATE_THEN:%.*]], label [[DOTOMP_LASTPRIVATE_DONE:%.*]]
// IR:       .omp.lastprivate.then:
// IR-NEXT:    store i32 10, ptr [[J3]], align 4
// IR-NEXT:    [[TMP22:%.*]] = load i32, ptr [[J3]], align 4
// IR-NEXT:    store i32 [[TMP22]], ptr [[TMP0]], align 4
// IR-NEXT:    br label [[DOTOMP_LASTPRIVATE_DONE]]
// IR:       .omp.lastprivate.done:
// IR-NEXT:    [[TMP23:%.*]] = getelementptr inbounds [1 x ptr], ptr [[DOTOMP_REDUCTION_RED_LIST]], i64 0, i64 0
// IR-NEXT:    store ptr [[SUM1]], ptr [[TMP23]], align 8
// IR-NEXT:    [[TMP24:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// IR-NEXT:    [[TMP25:%.*]] = load i32, ptr [[TMP24]], align 4
// IR-NEXT:    [[TMP26:%.*]] = call i32 @__kmpc_reduce_nowait(ptr @[[GLOB2:[0-9]+]], i32 [[TMP25]], i32 1, i64 8, ptr [[DOTOMP_REDUCTION_RED_LIST]], ptr @_Z3foov.omp_outlined.omp.reduction.reduction_func, ptr @.gomp_critical_user_.reduction.var)
// IR-NEXT:    switch i32 [[TMP26]], label [[DOTOMP_REDUCTION_DEFAULT:%.*]] [
// IR-NEXT:      i32 1, label [[DOTOMP_REDUCTION_CASE1:%.*]]
// IR-NEXT:      i32 2, label [[DOTOMP_REDUCTION_CASE2:%.*]]
// IR-NEXT:    ]
// IR:       .omp.reduction.case1:
// IR-NEXT:    [[TMP27:%.*]] = getelementptr i32, ptr [[TMP1]], i64 100
// IR-NEXT:    [[OMP_ARRAYCPY_ISEMPTY:%.*]] = icmp eq ptr [[TMP1]], [[TMP27]]
// IR-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY]], label [[OMP_ARRAYCPY_DONE18:%.*]], label [[OMP_ARRAYCPY_BODY:%.*]]
// IR:       omp.arraycpy.body:
// IR-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST:%.*]] = phi ptr [ [[SUM1]], [[DOTOMP_REDUCTION_CASE1]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// IR-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST14:%.*]] = phi ptr [ [[TMP1]], [[DOTOMP_REDUCTION_CASE1]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT16:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// IR-NEXT:    [[TMP28:%.*]] = load i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST14]], align 4
// IR-NEXT:    [[TMP29:%.*]] = load i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], align 4
// IR-NEXT:    [[ADD15:%.*]] = add nsw i32 [[TMP28]], [[TMP29]]
// IR-NEXT:    store i32 [[ADD15]], ptr [[OMP_ARRAYCPY_DESTELEMENTPAST14]], align 4
// IR-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT16]] = getelementptr i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST14]], i32 1
// IR-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT]] = getelementptr i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], i32 1
// IR-NEXT:    [[OMP_ARRAYCPY_DONE17:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT16]], [[TMP27]]
// IR-NEXT:    br i1 [[OMP_ARRAYCPY_DONE17]], label [[OMP_ARRAYCPY_DONE18]], label [[OMP_ARRAYCPY_BODY]]
// IR:       omp.arraycpy.done18:
// IR-NEXT:    call void @__kmpc_end_reduce_nowait(ptr @[[GLOB2]], i32 [[TMP25]], ptr @.gomp_critical_user_.reduction.var)
// IR-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// IR:       .omp.reduction.case2:
// IR-NEXT:    [[TMP30:%.*]] = getelementptr i32, ptr [[TMP1]], i64 100
// IR-NEXT:    [[OMP_ARRAYCPY_ISEMPTY19:%.*]] = icmp eq ptr [[TMP1]], [[TMP30]]
// IR-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY19]], label [[OMP_ARRAYCPY_DONE26:%.*]], label [[OMP_ARRAYCPY_BODY20:%.*]]
// IR:       omp.arraycpy.body20:
// IR-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST21:%.*]] = phi ptr [ [[SUM1]], [[DOTOMP_REDUCTION_CASE2]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT24:%.*]], [[OMP_ARRAYCPY_BODY20]] ]
// IR-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST22:%.*]] = phi ptr [ [[TMP1]], [[DOTOMP_REDUCTION_CASE2]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT23:%.*]], [[OMP_ARRAYCPY_BODY20]] ]
// IR-NEXT:    [[TMP31:%.*]] = load i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST21]], align 4
// IR-NEXT:    [[TMP32:%.*]] = atomicrmw add ptr [[OMP_ARRAYCPY_DESTELEMENTPAST22]], i32 [[TMP31]] monotonic, align 4
// IR-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT23]] = getelementptr i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST22]], i32 1
// IR-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT24]] = getelementptr i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST21]], i32 1
// IR-NEXT:    [[OMP_ARRAYCPY_DONE25:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT23]], [[TMP30]]
// IR-NEXT:    br i1 [[OMP_ARRAYCPY_DONE25]], label [[OMP_ARRAYCPY_DONE26]], label [[OMP_ARRAYCPY_BODY20]]
// IR:       omp.arraycpy.done26:
// IR-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// IR:       .omp.reduction.default:
// IR-NEXT:    ret void
//
//
// IR-LABEL: define {{[^@]+}}@_Z3foov.omp_outlined.omp.reduction.reduction_func
// IR-SAME: (ptr noundef [[TMP0:%.*]], ptr noundef [[TMP1:%.*]]) #[[ATTR3:[0-9]+]] {
// IR-NEXT:  entry:
// IR-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// IR-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// IR-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// IR-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// IR-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// IR-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// IR-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [1 x ptr], ptr [[TMP3]], i64 0, i64 0
// IR-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[TMP4]], align 8
// IR-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [1 x ptr], ptr [[TMP2]], i64 0, i64 0
// IR-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[TMP6]], align 8
// IR-NEXT:    [[TMP8:%.*]] = getelementptr i32, ptr [[TMP7]], i64 100
// IR-NEXT:    [[OMP_ARRAYCPY_ISEMPTY:%.*]] = icmp eq ptr [[TMP7]], [[TMP8]]
// IR-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY]], label [[OMP_ARRAYCPY_DONE2:%.*]], label [[OMP_ARRAYCPY_BODY:%.*]]
// IR:       omp.arraycpy.body:
// IR-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST:%.*]] = phi ptr [ [[TMP5]], [[ENTRY:%.*]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// IR-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST:%.*]] = phi ptr [ [[TMP7]], [[ENTRY]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// IR-NEXT:    [[TMP9:%.*]] = load i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 4
// IR-NEXT:    [[TMP10:%.*]] = load i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], align 4
// IR-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP9]], [[TMP10]]
// IR-NEXT:    store i32 [[ADD]], ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 4
// IR-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT]] = getelementptr i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], i32 1
// IR-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT]] = getelementptr i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], i32 1
// IR-NEXT:    [[OMP_ARRAYCPY_DONE:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT]], [[TMP8]]
// IR-NEXT:    br i1 [[OMP_ARRAYCPY_DONE]], label [[OMP_ARRAYCPY_DONE2]], label [[OMP_ARRAYCPY_BODY]]
// IR:       omp.arraycpy.done2:
// IR-NEXT:    ret void
//
//
// IR-PCH-LABEL: define {{[^@]+}}@_Z3foov
// IR-PCH-SAME: () #[[ATTR0:[0-9]+]] {
// IR-PCH-NEXT:  entry:
// IR-PCH-NEXT:    [[I:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[J:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[SUM:%.*]] = alloca [10 x [10 x i32]], align 16
// IR-PCH-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_teams(ptr @[[GLOB3:[0-9]+]], i32 2, ptr @_Z3foov.omp_outlined, ptr [[J]], ptr [[SUM]])
// IR-PCH-NEXT:    ret i32 0
//
//
// IR-PCH-LABEL: define {{[^@]+}}@_Z3foov.omp_outlined
// IR-PCH-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[J:%.*]], ptr noundef nonnull align 4 dereferenceable(400) [[SUM:%.*]]) #[[ATTR1:[0-9]+]] {
// IR-PCH-NEXT:  entry:
// IR-PCH-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// IR-PCH-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// IR-PCH-NEXT:    [[J_ADDR:%.*]] = alloca ptr, align 8
// IR-PCH-NEXT:    [[SUM_ADDR:%.*]] = alloca ptr, align 8
// IR-PCH-NEXT:    [[SUM1:%.*]] = alloca [10 x [10 x i32]], align 16
// IR-PCH-NEXT:    [[DOTOMP_IV:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[TMP:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[_TMP2:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[DOTOMP_COMB_LB:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[DOTOMP_COMB_UB:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[J3:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[I:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[J4:%.*]] = alloca i32, align 4
// IR-PCH-NEXT:    [[DOTOMP_REDUCTION_RED_LIST:%.*]] = alloca [1 x ptr], align 8
// IR-PCH-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// IR-PCH-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// IR-PCH-NEXT:    store ptr [[J]], ptr [[J_ADDR]], align 8
// IR-PCH-NEXT:    store ptr [[SUM]], ptr [[SUM_ADDR]], align 8
// IR-PCH-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[J_ADDR]], align 8
// IR-PCH-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[SUM_ADDR]], align 8
// IR-PCH-NEXT:    [[ARRAY_BEGIN:%.*]] = getelementptr inbounds [10 x [10 x i32]], ptr [[SUM1]], i32 0, i32 0, i32 0
// IR-PCH-NEXT:    [[TMP2:%.*]] = getelementptr i32, ptr [[ARRAY_BEGIN]], i64 100
// IR-PCH-NEXT:    [[OMP_ARRAYINIT_ISEMPTY:%.*]] = icmp eq ptr [[ARRAY_BEGIN]], [[TMP2]]
// IR-PCH-NEXT:    br i1 [[OMP_ARRAYINIT_ISEMPTY]], label [[OMP_ARRAYINIT_DONE:%.*]], label [[OMP_ARRAYINIT_BODY:%.*]]
// IR-PCH:       omp.arrayinit.body:
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST:%.*]] = phi ptr [ [[ARRAY_BEGIN]], [[ENTRY:%.*]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT:%.*]], [[OMP_ARRAYINIT_BODY]] ]
// IR-PCH-NEXT:    store i32 0, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 4
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT]] = getelementptr i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], i32 1
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DONE:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT]], [[TMP2]]
// IR-PCH-NEXT:    br i1 [[OMP_ARRAYCPY_DONE]], label [[OMP_ARRAYINIT_DONE]], label [[OMP_ARRAYINIT_BODY]]
// IR-PCH:       omp.arrayinit.done:
// IR-PCH-NEXT:    store i32 0, ptr [[DOTOMP_COMB_LB]], align 4
// IR-PCH-NEXT:    store i32 99, ptr [[DOTOMP_COMB_UB]], align 4
// IR-PCH-NEXT:    store i32 1, ptr [[DOTOMP_STRIDE]], align 4
// IR-PCH-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST]], align 4
// IR-PCH-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// IR-PCH-NEXT:    [[TMP4:%.*]] = load i32, ptr [[TMP3]], align 4
// IR-PCH-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB1:[0-9]+]], i32 [[TMP4]], i32 92, ptr [[DOTOMP_IS_LAST]], ptr [[DOTOMP_COMB_LB]], ptr [[DOTOMP_COMB_UB]], ptr [[DOTOMP_STRIDE]], i32 1, i32 1)
// IR-PCH-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// IR-PCH-NEXT:    [[CMP:%.*]] = icmp sgt i32 [[TMP5]], 99
// IR-PCH-NEXT:    br i1 [[CMP]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// IR-PCH:       cond.true:
// IR-PCH-NEXT:    br label [[COND_END:%.*]]
// IR-PCH:       cond.false:
// IR-PCH-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// IR-PCH-NEXT:    br label [[COND_END]]
// IR-PCH:       cond.end:
// IR-PCH-NEXT:    [[COND:%.*]] = phi i32 [ 99, [[COND_TRUE]] ], [ [[TMP6]], [[COND_FALSE]] ]
// IR-PCH-NEXT:    store i32 [[COND]], ptr [[DOTOMP_COMB_UB]], align 4
// IR-PCH-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTOMP_COMB_LB]], align 4
// IR-PCH-NEXT:    store i32 [[TMP7]], ptr [[DOTOMP_IV]], align 4
// IR-PCH-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// IR-PCH:       omp.inner.for.cond:
// IR-PCH-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-PCH-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTOMP_COMB_UB]], align 4
// IR-PCH-NEXT:    [[CMP5:%.*]] = icmp sle i32 [[TMP8]], [[TMP9]]
// IR-PCH-NEXT:    br i1 [[CMP5]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// IR-PCH:       omp.inner.for.body:
// IR-PCH-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-PCH-NEXT:    [[DIV:%.*]] = sdiv i32 [[TMP10]], 10
// IR-PCH-NEXT:    [[MUL:%.*]] = mul nsw i32 [[DIV]], 1
// IR-PCH-NEXT:    [[ADD:%.*]] = add nsw i32 0, [[MUL]]
// IR-PCH-NEXT:    store i32 [[ADD]], ptr [[I]], align 4
// IR-PCH-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-PCH-NEXT:    [[TMP12:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-PCH-NEXT:    [[DIV6:%.*]] = sdiv i32 [[TMP12]], 10
// IR-PCH-NEXT:    [[MUL7:%.*]] = mul nsw i32 [[DIV6]], 10
// IR-PCH-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP11]], [[MUL7]]
// IR-PCH-NEXT:    [[MUL8:%.*]] = mul nsw i32 [[SUB]], 1
// IR-PCH-NEXT:    [[ADD9:%.*]] = add nsw i32 0, [[MUL8]]
// IR-PCH-NEXT:    store i32 [[ADD9]], ptr [[J3]], align 4
// IR-PCH-NEXT:    [[TMP13:%.*]] = load i32, ptr [[I]], align 4
// IR-PCH-NEXT:    [[TMP14:%.*]] = load i32, ptr [[I]], align 4
// IR-PCH-NEXT:    [[IDXPROM:%.*]] = sext i32 [[TMP14]] to i64
// IR-PCH-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [10 x [10 x i32]], ptr [[SUM1]], i64 0, i64 [[IDXPROM]]
// IR-PCH-NEXT:    [[TMP15:%.*]] = load i32, ptr [[J3]], align 4
// IR-PCH-NEXT:    [[IDXPROM10:%.*]] = sext i32 [[TMP15]] to i64
// IR-PCH-NEXT:    [[ARRAYIDX11:%.*]] = getelementptr inbounds [10 x i32], ptr [[ARRAYIDX]], i64 0, i64 [[IDXPROM10]]
// IR-PCH-NEXT:    [[TMP16:%.*]] = load i32, ptr [[ARRAYIDX11]], align 4
// IR-PCH-NEXT:    [[ADD12:%.*]] = add nsw i32 [[TMP16]], [[TMP13]]
// IR-PCH-NEXT:    store i32 [[ADD12]], ptr [[ARRAYIDX11]], align 4
// IR-PCH-NEXT:    br label [[OMP_BODY_CONTINUE:%.*]]
// IR-PCH:       omp.body.continue:
// IR-PCH-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// IR-PCH:       omp.inner.for.inc:
// IR-PCH-NEXT:    [[TMP17:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// IR-PCH-NEXT:    [[ADD13:%.*]] = add nsw i32 [[TMP17]], 1
// IR-PCH-NEXT:    store i32 [[ADD13]], ptr [[DOTOMP_IV]], align 4
// IR-PCH-NEXT:    br label [[OMP_INNER_FOR_COND]]
// IR-PCH:       omp.inner.for.end:
// IR-PCH-NEXT:    br label [[OMP_LOOP_EXIT:%.*]]
// IR-PCH:       omp.loop.exit:
// IR-PCH-NEXT:    [[TMP18:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// IR-PCH-NEXT:    [[TMP19:%.*]] = load i32, ptr [[TMP18]], align 4
// IR-PCH-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP19]])
// IR-PCH-NEXT:    [[TMP20:%.*]] = load i32, ptr [[DOTOMP_IS_LAST]], align 4
// IR-PCH-NEXT:    [[TMP21:%.*]] = icmp ne i32 [[TMP20]], 0
// IR-PCH-NEXT:    br i1 [[TMP21]], label [[DOTOMP_LASTPRIVATE_THEN:%.*]], label [[DOTOMP_LASTPRIVATE_DONE:%.*]]
// IR-PCH:       .omp.lastprivate.then:
// IR-PCH-NEXT:    store i32 10, ptr [[J3]], align 4
// IR-PCH-NEXT:    [[TMP22:%.*]] = load i32, ptr [[J3]], align 4
// IR-PCH-NEXT:    store i32 [[TMP22]], ptr [[TMP0]], align 4
// IR-PCH-NEXT:    br label [[DOTOMP_LASTPRIVATE_DONE]]
// IR-PCH:       .omp.lastprivate.done:
// IR-PCH-NEXT:    [[TMP23:%.*]] = getelementptr inbounds [1 x ptr], ptr [[DOTOMP_REDUCTION_RED_LIST]], i64 0, i64 0
// IR-PCH-NEXT:    store ptr [[SUM1]], ptr [[TMP23]], align 8
// IR-PCH-NEXT:    [[TMP24:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// IR-PCH-NEXT:    [[TMP25:%.*]] = load i32, ptr [[TMP24]], align 4
// IR-PCH-NEXT:    [[TMP26:%.*]] = call i32 @__kmpc_reduce_nowait(ptr @[[GLOB2:[0-9]+]], i32 [[TMP25]], i32 1, i64 8, ptr [[DOTOMP_REDUCTION_RED_LIST]], ptr @_Z3foov.omp_outlined.omp.reduction.reduction_func, ptr @.gomp_critical_user_.reduction.var)
// IR-PCH-NEXT:    switch i32 [[TMP26]], label [[DOTOMP_REDUCTION_DEFAULT:%.*]] [
// IR-PCH-NEXT:      i32 1, label [[DOTOMP_REDUCTION_CASE1:%.*]]
// IR-PCH-NEXT:      i32 2, label [[DOTOMP_REDUCTION_CASE2:%.*]]
// IR-PCH-NEXT:    ]
// IR-PCH:       .omp.reduction.case1:
// IR-PCH-NEXT:    [[TMP27:%.*]] = getelementptr i32, ptr [[TMP1]], i64 100
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_ISEMPTY:%.*]] = icmp eq ptr [[TMP1]], [[TMP27]]
// IR-PCH-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY]], label [[OMP_ARRAYCPY_DONE18:%.*]], label [[OMP_ARRAYCPY_BODY:%.*]]
// IR-PCH:       omp.arraycpy.body:
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST:%.*]] = phi ptr [ [[SUM1]], [[DOTOMP_REDUCTION_CASE1]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST14:%.*]] = phi ptr [ [[TMP1]], [[DOTOMP_REDUCTION_CASE1]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT16:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// IR-PCH-NEXT:    [[TMP28:%.*]] = load i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST14]], align 4
// IR-PCH-NEXT:    [[TMP29:%.*]] = load i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], align 4
// IR-PCH-NEXT:    [[ADD15:%.*]] = add nsw i32 [[TMP28]], [[TMP29]]
// IR-PCH-NEXT:    store i32 [[ADD15]], ptr [[OMP_ARRAYCPY_DESTELEMENTPAST14]], align 4
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT16]] = getelementptr i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST14]], i32 1
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT]] = getelementptr i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], i32 1
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DONE17:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT16]], [[TMP27]]
// IR-PCH-NEXT:    br i1 [[OMP_ARRAYCPY_DONE17]], label [[OMP_ARRAYCPY_DONE18]], label [[OMP_ARRAYCPY_BODY]]
// IR-PCH:       omp.arraycpy.done18:
// IR-PCH-NEXT:    call void @__kmpc_end_reduce_nowait(ptr @[[GLOB2]], i32 [[TMP25]], ptr @.gomp_critical_user_.reduction.var)
// IR-PCH-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// IR-PCH:       .omp.reduction.case2:
// IR-PCH-NEXT:    [[TMP30:%.*]] = getelementptr i32, ptr [[TMP1]], i64 100
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_ISEMPTY19:%.*]] = icmp eq ptr [[TMP1]], [[TMP30]]
// IR-PCH-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY19]], label [[OMP_ARRAYCPY_DONE26:%.*]], label [[OMP_ARRAYCPY_BODY20:%.*]]
// IR-PCH:       omp.arraycpy.body20:
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST21:%.*]] = phi ptr [ [[SUM1]], [[DOTOMP_REDUCTION_CASE2]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT24:%.*]], [[OMP_ARRAYCPY_BODY20]] ]
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST22:%.*]] = phi ptr [ [[TMP1]], [[DOTOMP_REDUCTION_CASE2]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT23:%.*]], [[OMP_ARRAYCPY_BODY20]] ]
// IR-PCH-NEXT:    [[TMP31:%.*]] = load i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST21]], align 4
// IR-PCH-NEXT:    [[TMP32:%.*]] = atomicrmw add ptr [[OMP_ARRAYCPY_DESTELEMENTPAST22]], i32 [[TMP31]] monotonic, align 4
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT23]] = getelementptr i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST22]], i32 1
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT24]] = getelementptr i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST21]], i32 1
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DONE25:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT23]], [[TMP30]]
// IR-PCH-NEXT:    br i1 [[OMP_ARRAYCPY_DONE25]], label [[OMP_ARRAYCPY_DONE26]], label [[OMP_ARRAYCPY_BODY20]]
// IR-PCH:       omp.arraycpy.done26:
// IR-PCH-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// IR-PCH:       .omp.reduction.default:
// IR-PCH-NEXT:    ret void
//
//
// IR-PCH-LABEL: define {{[^@]+}}@_Z3foov.omp_outlined.omp.reduction.reduction_func
// IR-PCH-SAME: (ptr noundef [[TMP0:%.*]], ptr noundef [[TMP1:%.*]]) #[[ATTR3:[0-9]+]] {
// IR-PCH-NEXT:  entry:
// IR-PCH-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// IR-PCH-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// IR-PCH-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// IR-PCH-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// IR-PCH-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// IR-PCH-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// IR-PCH-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [1 x ptr], ptr [[TMP3]], i64 0, i64 0
// IR-PCH-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[TMP4]], align 8
// IR-PCH-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [1 x ptr], ptr [[TMP2]], i64 0, i64 0
// IR-PCH-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[TMP6]], align 8
// IR-PCH-NEXT:    [[TMP8:%.*]] = getelementptr i32, ptr [[TMP7]], i64 100
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_ISEMPTY:%.*]] = icmp eq ptr [[TMP7]], [[TMP8]]
// IR-PCH-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY]], label [[OMP_ARRAYCPY_DONE2:%.*]], label [[OMP_ARRAYCPY_BODY:%.*]]
// IR-PCH:       omp.arraycpy.body:
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST:%.*]] = phi ptr [ [[TMP5]], [[ENTRY:%.*]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST:%.*]] = phi ptr [ [[TMP7]], [[ENTRY]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// IR-PCH-NEXT:    [[TMP9:%.*]] = load i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 4
// IR-PCH-NEXT:    [[TMP10:%.*]] = load i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], align 4
// IR-PCH-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP9]], [[TMP10]]
// IR-PCH-NEXT:    store i32 [[ADD]], ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 4
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT]] = getelementptr i32, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], i32 1
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT]] = getelementptr i32, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], i32 1
// IR-PCH-NEXT:    [[OMP_ARRAYCPY_DONE:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT]], [[TMP8]]
// IR-PCH-NEXT:    br i1 [[OMP_ARRAYCPY_DONE]], label [[OMP_ARRAYCPY_DONE2]], label [[OMP_ARRAYCPY_BODY]]
// IR-PCH:       omp.arraycpy.done2:
// IR-PCH-NEXT:    ret void
//
