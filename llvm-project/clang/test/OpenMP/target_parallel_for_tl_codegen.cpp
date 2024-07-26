// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_  size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _ --version 2
// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fopenmp -fopenmp-version=51 -emit-llvm %s -o - | FileCheck --check-prefix=OMP51 %s
// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fopenmp -fopenmp-version=51 -x c++ -std=c++11 -emit-pch -o %t %s
// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fopenmp -fopenmp-version=51 -x c++ -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s --check-prefix=OMP51

// expected-no-diagnostics

#ifndef HEADER
#define HEADER

int thread_limit_target_parallel_for() {

// Check that the offloading function is called after setting thread_limit in the task entry function
#pragma omp target parallel for thread_limit(2)
    for(int i=0; i<2; i++) {}

  return 0;
}

#endif
// OMP51-LABEL: define dso_local noundef i32 @_Z32thread_limit_target_parallel_forv
// OMP51-SAME: () #[[ATTR0:[0-9]+]] {
// OMP51-NEXT:  entry:
// OMP51-NEXT:    [[AGG_CAPTURED:%.*]] = alloca [[STRUCT_ANON:%.*]], align 1
// OMP51-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB2:[0-9]+]])
// OMP51-NEXT:    [[TMP1:%.*]] = call ptr @__kmpc_omp_task_alloc(ptr @[[GLOB2]], i32 [[TMP0]], i32 1, i64 40, i64 1, ptr @.omp_task_entry.)
// OMP51-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T_WITH_PRIVATES:%.*]], ptr [[TMP1]], i32 0, i32 0
// OMP51-NEXT:    call void @__kmpc_omp_task_begin_if0(ptr @[[GLOB2]], i32 [[TMP0]], ptr [[TMP1]])
// OMP51-NEXT:    [[TMP3:%.*]] = call i32 @.omp_task_entry.(i32 [[TMP0]], ptr [[TMP1]]) #[[ATTR2:[0-9]+]]
// OMP51-NEXT:    call void @__kmpc_omp_task_complete_if0(ptr @[[GLOB2]], i32 [[TMP0]], ptr [[TMP1]])
// OMP51-NEXT:    ret i32 0
//
//
// OMP51-LABEL: define internal void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z32thread_limit_target_parallel_forv_l14
// OMP51-SAME: () #[[ATTR1:[0-9]+]] {
// OMP51-NEXT:  entry:
// OMP51-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @[[GLOB2]], i32 0, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z32thread_limit_target_parallel_forv_l14.omp_outlined)
// OMP51-NEXT:    ret void
//
//
// OMP51-LABEL: define internal void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z32thread_limit_target_parallel_forv_l14.omp_outlined
// OMP51-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]]) #[[ATTR1]] {
// OMP51-NEXT:  entry:
// OMP51-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// OMP51-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// OMP51-NEXT:    [[DOTOMP_IV:%.*]] = alloca i32, align 4
// OMP51-NEXT:    [[TMP:%.*]] = alloca i32, align 4
// OMP51-NEXT:    [[DOTOMP_LB:%.*]] = alloca i32, align 4
// OMP51-NEXT:    [[DOTOMP_UB:%.*]] = alloca i32, align 4
// OMP51-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i32, align 4
// OMP51-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4
// OMP51-NEXT:    [[I:%.*]] = alloca i32, align 4
// OMP51-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// OMP51-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// OMP51-NEXT:    store i32 0, ptr [[DOTOMP_LB]], align 4
// OMP51-NEXT:    store i32 1, ptr [[DOTOMP_UB]], align 4
// OMP51-NEXT:    store i32 1, ptr [[DOTOMP_STRIDE]], align 4
// OMP51-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST]], align 4
// OMP51-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// OMP51-NEXT:    [[TMP1:%.*]] = load i32, ptr [[TMP0]], align 4
// OMP51-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB1:[0-9]+]], i32 [[TMP1]], i32 34, ptr [[DOTOMP_IS_LAST]], ptr [[DOTOMP_LB]], ptr [[DOTOMP_UB]], ptr [[DOTOMP_STRIDE]], i32 1, i32 1)
// OMP51-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4
// OMP51-NEXT:    [[CMP:%.*]] = icmp sgt i32 [[TMP2]], 1
// OMP51-NEXT:    br i1 [[CMP]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// OMP51:       cond.true:
// OMP51-NEXT:    br label [[COND_END:%.*]]
// OMP51:       cond.false:
// OMP51-NEXT:    [[TMP3:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4
// OMP51-NEXT:    br label [[COND_END]]
// OMP51:       cond.end:
// OMP51-NEXT:    [[COND:%.*]] = phi i32 [ 1, [[COND_TRUE]] ], [ [[TMP3]], [[COND_FALSE]] ]
// OMP51-NEXT:    store i32 [[COND]], ptr [[DOTOMP_UB]], align 4
// OMP51-NEXT:    [[TMP4:%.*]] = load i32, ptr [[DOTOMP_LB]], align 4
// OMP51-NEXT:    store i32 [[TMP4]], ptr [[DOTOMP_IV]], align 4
// OMP51-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// OMP51:       omp.inner.for.cond:
// OMP51-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// OMP51-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTOMP_UB]], align 4
// OMP51-NEXT:    [[CMP1:%.*]] = icmp sle i32 [[TMP5]], [[TMP6]]
// OMP51-NEXT:    br i1 [[CMP1]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// OMP51:       omp.inner.for.body:
// OMP51-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// OMP51-NEXT:    [[MUL:%.*]] = mul nsw i32 [[TMP7]], 1
// OMP51-NEXT:    [[ADD:%.*]] = add nsw i32 0, [[MUL]]
// OMP51-NEXT:    store i32 [[ADD]], ptr [[I]], align 4
// OMP51-NEXT:    br label [[OMP_BODY_CONTINUE:%.*]]
// OMP51:       omp.body.continue:
// OMP51-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// OMP51:       omp.inner.for.inc:
// OMP51-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTOMP_IV]], align 4
// OMP51-NEXT:    [[ADD2:%.*]] = add nsw i32 [[TMP8]], 1
// OMP51-NEXT:    store i32 [[ADD2]], ptr [[DOTOMP_IV]], align 4
// OMP51-NEXT:    br label [[OMP_INNER_FOR_COND]]
// OMP51:       omp.inner.for.end:
// OMP51-NEXT:    br label [[OMP_LOOP_EXIT:%.*]]
// OMP51:       omp.loop.exit:
// OMP51-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP1]])
// OMP51-NEXT:    ret void
//
//
// OMP51-LABEL: define internal noundef i32 @.omp_task_entry.
// OMP51-SAME: (i32 noundef [[TMP0:%.*]], ptr noalias noundef [[TMP1:%.*]]) #[[ATTR3:[0-9]+]] {
// OMP51-NEXT:  entry:
// OMP51-NEXT:    [[DOTGLOBAL_TID__ADDR_I:%.*]] = alloca i32, align 4
// OMP51-NEXT:    [[DOTPART_ID__ADDR_I:%.*]] = alloca ptr, align 8
// OMP51-NEXT:    [[DOTPRIVATES__ADDR_I:%.*]] = alloca ptr, align 8
// OMP51-NEXT:    [[DOTCOPY_FN__ADDR_I:%.*]] = alloca ptr, align 8
// OMP51-NEXT:    [[DOTTASK_T__ADDR_I:%.*]] = alloca ptr, align 8
// OMP51-NEXT:    [[__CONTEXT_ADDR_I:%.*]] = alloca ptr, align 8
// OMP51-NEXT:    [[DOTADDR:%.*]] = alloca i32, align 4
// OMP51-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// OMP51-NEXT:    store i32 [[TMP0]], ptr [[DOTADDR]], align 4
// OMP51-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// OMP51-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTADDR]], align 4
// OMP51-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// OMP51-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T_WITH_PRIVATES:%.*]], ptr [[TMP3]], i32 0, i32 0
// OMP51-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T:%.*]], ptr [[TMP4]], i32 0, i32 2
// OMP51-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T]], ptr [[TMP4]], i32 0, i32 0
// OMP51-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[TMP6]], align 8
// OMP51-NEXT:    call void @llvm.experimental.noalias.scope.decl(metadata [[META5:![0-9]+]])
// OMP51-NEXT:    call void @llvm.experimental.noalias.scope.decl(metadata [[META8:![0-9]+]])
// OMP51-NEXT:    call void @llvm.experimental.noalias.scope.decl(metadata [[META10:![0-9]+]])
// OMP51-NEXT:    call void @llvm.experimental.noalias.scope.decl(metadata [[META12:![0-9]+]])
// OMP51-NEXT:    store i32 [[TMP2]], ptr [[DOTGLOBAL_TID__ADDR_I]], align 4, !noalias !14
// OMP51-NEXT:    store ptr [[TMP5]], ptr [[DOTPART_ID__ADDR_I]], align 8, !noalias !14
// OMP51-NEXT:    store ptr null, ptr [[DOTPRIVATES__ADDR_I]], align 8, !noalias !14
// OMP51-NEXT:    store ptr null, ptr [[DOTCOPY_FN__ADDR_I]], align 8, !noalias !14
// OMP51-NEXT:    store ptr [[TMP3]], ptr [[DOTTASK_T__ADDR_I]], align 8, !noalias !14
// OMP51-NEXT:    store ptr [[TMP7]], ptr [[__CONTEXT_ADDR_I]], align 8, !noalias !14
// OMP51-NEXT:    [[TMP8:%.*]] = load ptr, ptr [[__CONTEXT_ADDR_I]], align 8, !noalias !14
// OMP51-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTGLOBAL_TID__ADDR_I]], align 4, !noalias !14
// OMP51-NEXT:    call void @__kmpc_set_thread_limit(ptr @[[GLOB2]], i32 [[TMP9]], i32 2)
// OMP51-NEXT:    call void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z32thread_limit_target_parallel_forv_l14() #[[ATTR2]]
// OMP51-NEXT:    ret i32 0
//
