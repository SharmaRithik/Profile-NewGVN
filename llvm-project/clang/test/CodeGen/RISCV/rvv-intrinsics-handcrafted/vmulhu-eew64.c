// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -disable-O0-optnone -emit-llvm %s -o - | opt -S -passes=mem2reg | FileCheck --check-prefix=CHECK-RV64 %s
// NOTE: This test file contains eew=64 of vmulhu.
// NOTE: The purpose of separating this instructions from vmulhu.c is that
// eew=64 versions only enable when V extension is specified. (Not for zve)

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vmulhu_vv_u64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vmulhu.nxv1i64.nxv1i64.i64(<vscale x 1 x i64> poison, <vscale x 1 x i64> [[OP1:%.*]], <vscale x 1 x i64> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vmulhu_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2, size_t vl) {
  return __riscv_vmulhu_vv_u64m1(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vx_u64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vmulhu.nxv1i64.i64.i64(<vscale x 1 x i64> poison, <vscale x 1 x i64> [[OP1:%.*]], i64 [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vmulhu_vx_u64m1(vuint64m1_t op1, uint64_t op2, size_t vl) {
  return __riscv_vmulhu_vx_u64m1(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vv_u64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vmulhu.nxv2i64.nxv2i64.i64(<vscale x 2 x i64> poison, <vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vmulhu_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2, size_t vl) {
  return __riscv_vmulhu_vv_u64m2(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vx_u64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vmulhu.nxv2i64.i64.i64(<vscale x 2 x i64> poison, <vscale x 2 x i64> [[OP1:%.*]], i64 [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vmulhu_vx_u64m2(vuint64m2_t op1, uint64_t op2, size_t vl) {
  return __riscv_vmulhu_vx_u64m2(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vv_u64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vmulhu.nxv4i64.nxv4i64.i64(<vscale x 4 x i64> poison, <vscale x 4 x i64> [[OP1:%.*]], <vscale x 4 x i64> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vmulhu_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2, size_t vl) {
  return __riscv_vmulhu_vv_u64m4(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vx_u64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vmulhu.nxv4i64.i64.i64(<vscale x 4 x i64> poison, <vscale x 4 x i64> [[OP1:%.*]], i64 [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vmulhu_vx_u64m4(vuint64m4_t op1, uint64_t op2, size_t vl) {
  return __riscv_vmulhu_vx_u64m4(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vv_u64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vmulhu.nxv8i64.nxv8i64.i64(<vscale x 8 x i64> poison, <vscale x 8 x i64> [[OP1:%.*]], <vscale x 8 x i64> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vmulhu_vv_u64m8(vuint64m8_t op1, vuint64m8_t op2, size_t vl) {
  return __riscv_vmulhu_vv_u64m8(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vx_u64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vmulhu.nxv8i64.i64.i64(<vscale x 8 x i64> poison, <vscale x 8 x i64> [[OP1:%.*]], i64 [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vmulhu_vx_u64m8(vuint64m8_t op1, uint64_t op2, size_t vl) {
  return __riscv_vmulhu_vx_u64m8(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vv_u64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vmulhu.mask.nxv1i64.nxv1i64.i64(<vscale x 1 x i64> poison, <vscale x 1 x i64> [[OP1:%.*]], <vscale x 1 x i64> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vmulhu_vv_u64m1_m(vbool64_t mask, vuint64m1_t op1, vuint64m1_t op2, size_t vl) {
  return __riscv_vmulhu_vv_u64m1_m(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vx_u64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vmulhu.mask.nxv1i64.i64.i64(<vscale x 1 x i64> poison, <vscale x 1 x i64> [[OP1:%.*]], i64 [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vmulhu_vx_u64m1_m(vbool64_t mask, vuint64m1_t op1, uint64_t op2, size_t vl) {
  return __riscv_vmulhu_vx_u64m1_m(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vv_u64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vmulhu.mask.nxv2i64.nxv2i64.i64(<vscale x 2 x i64> poison, <vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vmulhu_vv_u64m2_m(vbool32_t mask, vuint64m2_t op1, vuint64m2_t op2, size_t vl) {
  return __riscv_vmulhu_vv_u64m2_m(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vx_u64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vmulhu.mask.nxv2i64.i64.i64(<vscale x 2 x i64> poison, <vscale x 2 x i64> [[OP1:%.*]], i64 [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vmulhu_vx_u64m2_m(vbool32_t mask, vuint64m2_t op1, uint64_t op2, size_t vl) {
  return __riscv_vmulhu_vx_u64m2_m(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vv_u64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vmulhu.mask.nxv4i64.nxv4i64.i64(<vscale x 4 x i64> poison, <vscale x 4 x i64> [[OP1:%.*]], <vscale x 4 x i64> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vmulhu_vv_u64m4_m(vbool16_t mask, vuint64m4_t op1, vuint64m4_t op2, size_t vl) {
  return __riscv_vmulhu_vv_u64m4_m(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vx_u64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vmulhu.mask.nxv4i64.i64.i64(<vscale x 4 x i64> poison, <vscale x 4 x i64> [[OP1:%.*]], i64 [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vmulhu_vx_u64m4_m(vbool16_t mask, vuint64m4_t op1, uint64_t op2, size_t vl) {
  return __riscv_vmulhu_vx_u64m4_m(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vv_u64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vmulhu.mask.nxv8i64.nxv8i64.i64(<vscale x 8 x i64> poison, <vscale x 8 x i64> [[OP1:%.*]], <vscale x 8 x i64> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vmulhu_vv_u64m8_m(vbool8_t mask, vuint64m8_t op1, vuint64m8_t op2, size_t vl) {
  return __riscv_vmulhu_vv_u64m8_m(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmulhu_vx_u64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vmulhu.mask.nxv8i64.i64.i64(<vscale x 8 x i64> poison, <vscale x 8 x i64> [[OP1:%.*]], i64 [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vmulhu_vx_u64m8_m(vbool8_t mask, vuint64m8_t op1, uint64_t op2, size_t vl) {
  return __riscv_vmulhu_vx_u64m8_m(mask, op1, op2, vl);
}
