; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt -passes=instcombine -S -o - %s | FileCheck %s
; REQUIRES: amdgpu-registered-target

target triple = "amdgcn-amd-amdhsa"

%anon = type { i32, [8 x ptr], ptr }

define void @foo(ptr addrspace(4) byref(%anon) align 8 %0) {
; CHECK-LABEL: @foo(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP1:%.*]] = load ptr, ptr addrspace(4) [[TMP0:%.*]], align 8
; CHECK-NEXT:    br label [[FOR_COND10:%.*]]
; CHECK:       for.cond10:
; CHECK-NEXT:    [[TMP2:%.*]] = load i64, ptr [[TMP1]], align 8
; CHECK-NEXT:    store i64 [[TMP2]], ptr addrspace(1) null, align 8
; CHECK-NEXT:    br label [[FOR_COND10]]
;
entry:
  %coerce = alloca %anon, addrspace(5)
  call void @llvm.memcpy.p5.p4.i64(ptr addrspace(5) %coerce, ptr addrspace(4) %0, i64 0, i1 false)
  %asc = addrspacecast ptr addrspace(5) %coerce to ptr
  %load = load ptr, ptr addrspace(5) %coerce
  %retval.0.i = select i1 false, ptr %asc, ptr %load
  br label %for.cond10

for.cond10:                                       ; preds = %for.cond10, %entry
  %load.0 = load i64, ptr %retval.0.i
  store i64 %load.0, ptr addrspace(1) null
  br label %for.cond10
}

declare void @llvm.memcpy.p5.p4.i64(ptr addrspace(5), ptr addrspace(4), i64, i1 immarg)