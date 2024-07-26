; NOTE: Assertions have been autogenerated by utils/update_analyze_test_checks.py UTC_ARGS: --version 4
; RUN: opt -passes='print<access-info>' -disable-output %s 2>&1 | FileCheck %s

target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"

declare void @llvm.assume(i1)

define void @different_non_constant_strides_known_backward(ptr %A) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep.mul.2, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_backward_distance_larger_than_trip_count(ptr %A) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward_distance_larger_than_trip_count'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep.mul.2, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.1024 = getelementptr inbounds i8, ptr %A, i64 1024
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.1024, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_backward_min_distance_16(ptr %A) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward_min_distance_16'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep.mul.2, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.16 = getelementptr inbounds i8, ptr %A, i64 16
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.16, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_backward_min_distance_15(ptr %A) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward_min_distance_15'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep.mul.2, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.15 = getelementptr inbounds i8, ptr %A, i64 15
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.15, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_backward_min_distance_8(ptr %A) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward_min_distance_8'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep.mul.2, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.8 = getelementptr inbounds i8, ptr %A, i64 8
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.8, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_backward_min_distance_3(ptr %A) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward_min_distance_3'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep.mul.2, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.3 = getelementptr inbounds i8, ptr %A, i64 3
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.3, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_backward_via_assume(ptr %A, i64 %scale) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward_via_assume'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: cannot identify array bounds
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %c = icmp sgt i64 %scale, 0
  call void @llvm.assume(i1 %c)
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, %scale
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_backward_via_assume_distance_larger_than_trip_count(ptr %A, i64 %scale) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward_via_assume_distance_larger_than_trip_count'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: cannot identify array bounds
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.1024 = getelementptr inbounds i8, ptr %A, i64 1024
  %c = icmp sgt i64 %scale, 0
  call void @llvm.assume(i1 %c)
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, %scale
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.1024, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_backward_via_assume_min_distance_3(ptr %A, i64 %scale) {
; CHECK-LABEL: 'different_non_constant_strides_known_backward_via_assume_min_distance_3'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: cannot identify array bounds
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.3 = getelementptr inbounds i8, ptr %A, i64 3
  %c = icmp sgt i64 %scale, 0
  call void @llvm.assume(i1 %c)
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, %scale
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.3, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_not_known_backward(ptr %A, i64 %scale) {
; CHECK-LABEL: 'different_non_constant_strides_not_known_backward'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: cannot identify array bounds
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  %l = load i32, ptr %gep, align 4
  %add = add nsw i32 %l, 5
  %iv.mul.2 = shl nuw nsw i64 %iv, %scale
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.mul.2
  store i32 %add, ptr %gep.mul.2, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}