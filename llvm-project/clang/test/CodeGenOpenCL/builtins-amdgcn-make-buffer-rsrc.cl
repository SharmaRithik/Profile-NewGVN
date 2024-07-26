// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: amdgpu-registered-target
// RUN: %clang_cc1 -triple amdgcn-unknown-unknown -cl-std=CL2.0 -target-cpu verde -emit-llvm -o - %s | FileCheck %s

// CHECK-LABEL: @test_amdgcn_make_buffer_rsrc_p0(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p0(ptr [[P:%.*]], i16 [[STRIDE:%.*]], i32 [[NUM:%.*]], i32 [[FLAGS:%.*]])
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_rsrc_p0(void *p, short stride, int num, int flags) {
  return __builtin_amdgcn_make_buffer_rsrc(p, stride, num, flags);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_rsrc_p0_stride_constant(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p0(ptr [[P:%.*]], i16 4, i32 [[NUM:%.*]], i32 [[FLAGS:%.*]])
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_rsrc_p0_stride_constant(void *p, int num, int flags) {
  return __builtin_amdgcn_make_buffer_rsrc(p, /*stride=*/4, num, flags);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_rsrc_p0_num_constant(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p0(ptr [[P:%.*]], i16 [[STRIDE:%.*]], i32 1234, i32 [[FLAGS:%.*]])
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_rsrc_p0_num_constant(void *p, short stride, int flags) {
  return __builtin_amdgcn_make_buffer_rsrc(p, stride, /*num=*/1234, flags);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_rsrc_p0_flags_constant(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p0(ptr [[P:%.*]], i16 [[STRIDE:%.*]], i32 [[NUM:%.*]], i32 5678)
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_rsrc_p0_flags_constant(void *p, short stride, int num) {
  return __builtin_amdgcn_make_buffer_rsrc(p, stride, num, /*flags=*/5678);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_rsrc_p1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p1(ptr addrspace(1) [[P:%.*]], i16 [[STRIDE:%.*]], i32 [[NUM:%.*]], i32 [[FLAGS:%.*]])
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_rsrc_p1(global void *p, short stride, int num, int flags) {
  return __builtin_amdgcn_make_buffer_rsrc(p, stride, num, flags);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_rsrc_p1_stride_constant(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p1(ptr addrspace(1) [[P:%.*]], i16 4, i32 [[NUM:%.*]], i32 [[FLAGS:%.*]])
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_rsrc_p1_stride_constant(global void *p, int num, int flags) {
  return __builtin_amdgcn_make_buffer_rsrc(p, /*stride=*/4, num, flags);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_rsrc_p1_num_constant(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p1(ptr addrspace(1) [[P:%.*]], i16 [[STRIDE:%.*]], i32 1234, i32 [[FLAGS:%.*]])
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_rsrc_p1_num_constant(global void *p, short stride, int flags) {
  return __builtin_amdgcn_make_buffer_rsrc(p, stride, /*num=*/1234, flags);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_rsrc_p1_flags_constant(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p1(ptr addrspace(1) [[P:%.*]], i16 [[STRIDE:%.*]], i32 [[NUM:%.*]], i32 5678)
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_rsrc_p1_flags_constant(global void *p, short stride, int num) {
  return __builtin_amdgcn_make_buffer_rsrc(p, stride, num, /*flags=*/5678);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_p0_nullptr(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p0(ptr null, i16 [[STRIDE:%.*]], i32 [[NUM:%.*]], i32 [[FLAGS:%.*]])
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_p0_nullptr(short stride, int num, int flags) {
  return __builtin_amdgcn_make_buffer_rsrc((void *)0LL, stride, num, flags);
}

// CHECK-LABEL: @test_amdgcn_make_buffer_p1_nullptr(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call ptr addrspace(8) @llvm.amdgcn.make.buffer.rsrc.p1(ptr addrspace(1) null, i16 [[STRIDE:%.*]], i32 [[NUM:%.*]], i32 [[FLAGS:%.*]])
// CHECK-NEXT:    ret ptr addrspace(8) [[TMP0]]
//
__amdgpu_buffer_rsrc_t test_amdgcn_make_buffer_p1_nullptr(short stride, int num, int flags) {
  return __builtin_amdgcn_make_buffer_rsrc((global void *)0LL, stride, num, flags);
}