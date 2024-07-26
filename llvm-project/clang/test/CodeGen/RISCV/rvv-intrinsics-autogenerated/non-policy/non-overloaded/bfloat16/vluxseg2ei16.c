// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @test_vluxseg2ei16_v_bf16mf4x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 1 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @llvm.riscv.vluxseg2.nxv1bf16.nxv1i16.i64(<vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, ptr [[RS1]], <vscale x 1 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP0]]
//
vbfloat16mf4x2_t test_vluxseg2ei16_v_bf16mf4x2(const __bf16 *rs1,
                                               vuint16mf4_t rs2, size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16mf4x2(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @test_vluxseg2ei16_v_bf16mf2x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 2 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @llvm.riscv.vluxseg2.nxv2bf16.nxv2i16.i64(<vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, ptr [[RS1]], <vscale x 2 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP0]]
//
vbfloat16mf2x2_t test_vluxseg2ei16_v_bf16mf2x2(const __bf16 *rs1,
                                               vuint16mf2_t rs2, size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16mf2x2(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @test_vluxseg2ei16_v_bf16m1x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 4 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @llvm.riscv.vluxseg2.nxv4bf16.nxv4i16.i64(<vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, ptr [[RS1]], <vscale x 4 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP0]]
//
vbfloat16m1x2_t test_vluxseg2ei16_v_bf16m1x2(const __bf16 *rs1, vuint16m1_t rs2,
                                             size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16m1x2(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } @test_vluxseg2ei16_v_bf16m2x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 8 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } @llvm.riscv.vluxseg2.nxv8bf16.nxv8i16.i64(<vscale x 8 x bfloat> poison, <vscale x 8 x bfloat> poison, ptr [[RS1]], <vscale x 8 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP0]]
//
vbfloat16m2x2_t test_vluxseg2ei16_v_bf16m2x2(const __bf16 *rs1, vuint16m2_t rs2,
                                             size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16m2x2(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 16 x bfloat>, <vscale x 16 x bfloat> } @test_vluxseg2ei16_v_bf16m4x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 16 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x bfloat>, <vscale x 16 x bfloat> } @llvm.riscv.vluxseg2.nxv16bf16.nxv16i16.i64(<vscale x 16 x bfloat> poison, <vscale x 16 x bfloat> poison, ptr [[RS1]], <vscale x 16 x i16> [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret { <vscale x 16 x bfloat>, <vscale x 16 x bfloat> } [[TMP0]]
//
vbfloat16m4x2_t test_vluxseg2ei16_v_bf16m4x2(const __bf16 *rs1, vuint16m4_t rs2,
                                             size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16m4x2(rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @test_vluxseg2ei16_v_bf16mf4x2_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 1 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @llvm.riscv.vluxseg2.mask.nxv1bf16.nxv1i16.i64(<vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, ptr [[RS1]], <vscale x 1 x i16> [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP0]]
//
vbfloat16mf4x2_t test_vluxseg2ei16_v_bf16mf4x2_m(vbool64_t vm,
                                                 const __bf16 *rs1,
                                                 vuint16mf4_t rs2, size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16mf4x2_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @test_vluxseg2ei16_v_bf16mf2x2_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 2 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @llvm.riscv.vluxseg2.mask.nxv2bf16.nxv2i16.i64(<vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, ptr [[RS1]], <vscale x 2 x i16> [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP0]]
//
vbfloat16mf2x2_t test_vluxseg2ei16_v_bf16mf2x2_m(vbool32_t vm,
                                                 const __bf16 *rs1,
                                                 vuint16mf2_t rs2, size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16mf2x2_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @test_vluxseg2ei16_v_bf16m1x2_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 4 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @llvm.riscv.vluxseg2.mask.nxv4bf16.nxv4i16.i64(<vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, ptr [[RS1]], <vscale x 4 x i16> [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP0]]
//
vbfloat16m1x2_t test_vluxseg2ei16_v_bf16m1x2_m(vbool16_t vm, const __bf16 *rs1,
                                               vuint16m1_t rs2, size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16m1x2_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } @test_vluxseg2ei16_v_bf16m2x2_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 8 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } @llvm.riscv.vluxseg2.mask.nxv8bf16.nxv8i16.i64(<vscale x 8 x bfloat> poison, <vscale x 8 x bfloat> poison, ptr [[RS1]], <vscale x 8 x i16> [[RS2]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP0]]
//
vbfloat16m2x2_t test_vluxseg2ei16_v_bf16m2x2_m(vbool8_t vm, const __bf16 *rs1,
                                               vuint16m2_t rs2, size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16m2x2_m(vm, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 16 x bfloat>, <vscale x 16 x bfloat> } @test_vluxseg2ei16_v_bf16m4x2_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 16 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x bfloat>, <vscale x 16 x bfloat> } @llvm.riscv.vluxseg2.mask.nxv16bf16.nxv16i16.i64(<vscale x 16 x bfloat> poison, <vscale x 16 x bfloat> poison, ptr [[RS1]], <vscale x 16 x i16> [[RS2]], <vscale x 16 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 16 x bfloat>, <vscale x 16 x bfloat> } [[TMP0]]
//
vbfloat16m4x2_t test_vluxseg2ei16_v_bf16m4x2_m(vbool4_t vm, const __bf16 *rs1,
                                               vuint16m4_t rs2, size_t vl) {
  return __riscv_vluxseg2ei16_v_bf16m4x2_m(vm, rs1, rs2, vl);
}
