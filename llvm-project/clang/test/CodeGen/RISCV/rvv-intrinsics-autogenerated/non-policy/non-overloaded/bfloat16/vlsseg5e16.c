// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @test_vlsseg5e16_v_bf16mf4x5(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @llvm.riscv.vlsseg5.nxv1bf16.i64(<vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP0]]
//
vbfloat16mf4x5_t test_vlsseg5e16_v_bf16mf4x5(const __bf16 *rs1, ptrdiff_t rs2,
                                             size_t vl) {
  return __riscv_vlsseg5e16_v_bf16mf4x5(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @test_vlsseg5e16_v_bf16mf2x5(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @llvm.riscv.vlsseg5.nxv2bf16.i64(<vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP0]]
//
vbfloat16mf2x5_t test_vlsseg5e16_v_bf16mf2x5(const __bf16 *rs1, ptrdiff_t rs2,
                                             size_t vl) {
  return __riscv_vlsseg5e16_v_bf16mf2x5(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @test_vlsseg5e16_v_bf16m1x5(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @llvm.riscv.vlsseg5.nxv4bf16.i64(<vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP0]]
//
vbfloat16m1x5_t test_vlsseg5e16_v_bf16m1x5(const __bf16 *rs1, ptrdiff_t rs2,
                                           size_t vl) {
  return __riscv_vlsseg5e16_v_bf16m1x5(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @test_vlsseg5e16_v_bf16mf4x5_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @llvm.riscv.vlsseg5.mask.nxv1bf16.i64(<vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP0]]
//
vbfloat16mf4x5_t test_vlsseg5e16_v_bf16mf4x5_m(vbool64_t vm, const __bf16 *rs1,
                                               ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg5e16_v_bf16mf4x5_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @test_vlsseg5e16_v_bf16mf2x5_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @llvm.riscv.vlsseg5.mask.nxv2bf16.i64(<vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP0]]
//
vbfloat16mf2x5_t test_vlsseg5e16_v_bf16mf2x5_m(vbool32_t vm, const __bf16 *rs1,
                                               ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg5e16_v_bf16mf2x5_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @test_vlsseg5e16_v_bf16m1x5_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @llvm.riscv.vlsseg5.mask.nxv4bf16.i64(<vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP0]]
//
vbfloat16m1x5_t test_vlsseg5e16_v_bf16m1x5_m(vbool16_t vm, const __bf16 *rs1,
                                             ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg5e16_v_bf16m1x5_m(vm, rs1, rs2, vl);
}
