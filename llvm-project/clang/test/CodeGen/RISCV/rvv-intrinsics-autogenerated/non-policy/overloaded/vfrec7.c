// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x half> @test_vfrec7_v_f16mf4
// CHECK-RV64-SAME: (<vscale x 1 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x half> @llvm.riscv.vfrec7.nxv1f16.i64(<vscale x 1 x half> poison, <vscale x 1 x half> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x half> [[TMP0]]
//
vfloat16mf4_t test_vfrec7_v_f16mf4(vfloat16mf4_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x half> @test_vfrec7_v_f16mf2
// CHECK-RV64-SAME: (<vscale x 2 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x half> @llvm.riscv.vfrec7.nxv2f16.i64(<vscale x 2 x half> poison, <vscale x 2 x half> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x half> [[TMP0]]
//
vfloat16mf2_t test_vfrec7_v_f16mf2(vfloat16mf2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x half> @test_vfrec7_v_f16m1
// CHECK-RV64-SAME: (<vscale x 4 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfrec7.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfrec7_v_f16m1(vfloat16m1_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x half> @test_vfrec7_v_f16m2
// CHECK-RV64-SAME: (<vscale x 8 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x half> @llvm.riscv.vfrec7.nxv8f16.i64(<vscale x 8 x half> poison, <vscale x 8 x half> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
vfloat16m2_t test_vfrec7_v_f16m2(vfloat16m2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x half> @test_vfrec7_v_f16m4
// CHECK-RV64-SAME: (<vscale x 16 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x half> @llvm.riscv.vfrec7.nxv16f16.i64(<vscale x 16 x half> poison, <vscale x 16 x half> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x half> [[TMP0]]
//
vfloat16m4_t test_vfrec7_v_f16m4(vfloat16m4_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x half> @test_vfrec7_v_f16m8
// CHECK-RV64-SAME: (<vscale x 32 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x half> @llvm.riscv.vfrec7.nxv32f16.i64(<vscale x 32 x half> poison, <vscale x 32 x half> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x half> [[TMP0]]
//
vfloat16m8_t test_vfrec7_v_f16m8(vfloat16m8_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfrec7_v_f32mf2
// CHECK-RV64-SAME: (<vscale x 1 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfrec7.nxv1f32.i64(<vscale x 1 x float> poison, <vscale x 1 x float> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfrec7_v_f32mf2(vfloat32mf2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfrec7_v_f32m1
// CHECK-RV64-SAME: (<vscale x 2 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfrec7.nxv2f32.i64(<vscale x 2 x float> poison, <vscale x 2 x float> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfrec7_v_f32m1(vfloat32m1_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfrec7_v_f32m2
// CHECK-RV64-SAME: (<vscale x 4 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfrec7.nxv4f32.i64(<vscale x 4 x float> poison, <vscale x 4 x float> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfrec7_v_f32m2(vfloat32m2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfrec7_v_f32m4
// CHECK-RV64-SAME: (<vscale x 8 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfrec7.nxv8f32.i64(<vscale x 8 x float> poison, <vscale x 8 x float> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfrec7_v_f32m4(vfloat32m4_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfrec7_v_f32m8
// CHECK-RV64-SAME: (<vscale x 16 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfrec7.nxv16f32.i64(<vscale x 16 x float> poison, <vscale x 16 x float> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfrec7_v_f32m8(vfloat32m8_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x double> @test_vfrec7_v_f64m1
// CHECK-RV64-SAME: (<vscale x 1 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfrec7.nxv1f64.i64(<vscale x 1 x double> poison, <vscale x 1 x double> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfrec7_v_f64m1(vfloat64m1_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x double> @test_vfrec7_v_f64m2
// CHECK-RV64-SAME: (<vscale x 2 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfrec7.nxv2f64.i64(<vscale x 2 x double> poison, <vscale x 2 x double> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfrec7_v_f64m2(vfloat64m2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x double> @test_vfrec7_v_f64m4
// CHECK-RV64-SAME: (<vscale x 4 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfrec7.nxv4f64.i64(<vscale x 4 x double> poison, <vscale x 4 x double> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfrec7_v_f64m4(vfloat64m4_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x double> @test_vfrec7_v_f64m8
// CHECK-RV64-SAME: (<vscale x 8 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfrec7.nxv8f64.i64(<vscale x 8 x double> poison, <vscale x 8 x double> [[OP1]], i64 7, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfrec7_v_f64m8(vfloat64m8_t op1, size_t vl) {
  return __riscv_vfrec7(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x half> @test_vfrec7_v_f16mf4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x half> @llvm.riscv.vfrec7.mask.nxv1f16.i64(<vscale x 1 x half> poison, <vscale x 1 x half> [[OP1]], <vscale x 1 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x half> [[TMP0]]
//
vfloat16mf4_t test_vfrec7_v_f16mf4_m(vbool64_t mask, vfloat16mf4_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x half> @test_vfrec7_v_f16mf2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x half> @llvm.riscv.vfrec7.mask.nxv2f16.i64(<vscale x 2 x half> poison, <vscale x 2 x half> [[OP1]], <vscale x 2 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x half> [[TMP0]]
//
vfloat16mf2_t test_vfrec7_v_f16mf2_m(vbool32_t mask, vfloat16mf2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x half> @test_vfrec7_v_f16m1_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfrec7.mask.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> [[OP1]], <vscale x 4 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfrec7_v_f16m1_m(vbool16_t mask, vfloat16m1_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x half> @test_vfrec7_v_f16m2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x half> @llvm.riscv.vfrec7.mask.nxv8f16.i64(<vscale x 8 x half> poison, <vscale x 8 x half> [[OP1]], <vscale x 8 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
vfloat16m2_t test_vfrec7_v_f16m2_m(vbool8_t mask, vfloat16m2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x half> @test_vfrec7_v_f16m4_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x half> @llvm.riscv.vfrec7.mask.nxv16f16.i64(<vscale x 16 x half> poison, <vscale x 16 x half> [[OP1]], <vscale x 16 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x half> [[TMP0]]
//
vfloat16m4_t test_vfrec7_v_f16m4_m(vbool4_t mask, vfloat16m4_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x half> @test_vfrec7_v_f16m8_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], <vscale x 32 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x half> @llvm.riscv.vfrec7.mask.nxv32f16.i64(<vscale x 32 x half> poison, <vscale x 32 x half> [[OP1]], <vscale x 32 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x half> [[TMP0]]
//
vfloat16m8_t test_vfrec7_v_f16m8_m(vbool2_t mask, vfloat16m8_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfrec7_v_f32mf2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfrec7.mask.nxv1f32.i64(<vscale x 1 x float> poison, <vscale x 1 x float> [[OP1]], <vscale x 1 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfrec7_v_f32mf2_m(vbool64_t mask, vfloat32mf2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfrec7_v_f32m1_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfrec7.mask.nxv2f32.i64(<vscale x 2 x float> poison, <vscale x 2 x float> [[OP1]], <vscale x 2 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfrec7_v_f32m1_m(vbool32_t mask, vfloat32m1_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfrec7_v_f32m2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfrec7.mask.nxv4f32.i64(<vscale x 4 x float> poison, <vscale x 4 x float> [[OP1]], <vscale x 4 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfrec7_v_f32m2_m(vbool16_t mask, vfloat32m2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfrec7_v_f32m4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfrec7.mask.nxv8f32.i64(<vscale x 8 x float> poison, <vscale x 8 x float> [[OP1]], <vscale x 8 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfrec7_v_f32m4_m(vbool8_t mask, vfloat32m4_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfrec7_v_f32m8_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfrec7.mask.nxv16f32.i64(<vscale x 16 x float> poison, <vscale x 16 x float> [[OP1]], <vscale x 16 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfrec7_v_f32m8_m(vbool4_t mask, vfloat32m8_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x double> @test_vfrec7_v_f64m1_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfrec7.mask.nxv1f64.i64(<vscale x 1 x double> poison, <vscale x 1 x double> [[OP1]], <vscale x 1 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfrec7_v_f64m1_m(vbool64_t mask, vfloat64m1_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x double> @test_vfrec7_v_f64m2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfrec7.mask.nxv2f64.i64(<vscale x 2 x double> poison, <vscale x 2 x double> [[OP1]], <vscale x 2 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfrec7_v_f64m2_m(vbool32_t mask, vfloat64m2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x double> @test_vfrec7_v_f64m4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfrec7.mask.nxv4f64.i64(<vscale x 4 x double> poison, <vscale x 4 x double> [[OP1]], <vscale x 4 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfrec7_v_f64m4_m(vbool16_t mask, vfloat64m4_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x double> @test_vfrec7_v_f64m8_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfrec7.mask.nxv8f64.i64(<vscale x 8 x double> poison, <vscale x 8 x double> [[OP1]], <vscale x 8 x i1> [[MASK]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfrec7_v_f64m8_m(vbool8_t mask, vfloat64m8_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x half> @test_vfrec7_v_f16mf4_rm
// CHECK-RV64-SAME: (<vscale x 1 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x half> @llvm.riscv.vfrec7.nxv1f16.i64(<vscale x 1 x half> poison, <vscale x 1 x half> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x half> [[TMP0]]
//
vfloat16mf4_t test_vfrec7_v_f16mf4_rm(vfloat16mf4_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x half> @test_vfrec7_v_f16mf2_rm
// CHECK-RV64-SAME: (<vscale x 2 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x half> @llvm.riscv.vfrec7.nxv2f16.i64(<vscale x 2 x half> poison, <vscale x 2 x half> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x half> [[TMP0]]
//
vfloat16mf2_t test_vfrec7_v_f16mf2_rm(vfloat16mf2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x half> @test_vfrec7_v_f16m1_rm
// CHECK-RV64-SAME: (<vscale x 4 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfrec7.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfrec7_v_f16m1_rm(vfloat16m1_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x half> @test_vfrec7_v_f16m2_rm
// CHECK-RV64-SAME: (<vscale x 8 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x half> @llvm.riscv.vfrec7.nxv8f16.i64(<vscale x 8 x half> poison, <vscale x 8 x half> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
vfloat16m2_t test_vfrec7_v_f16m2_rm(vfloat16m2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x half> @test_vfrec7_v_f16m4_rm
// CHECK-RV64-SAME: (<vscale x 16 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x half> @llvm.riscv.vfrec7.nxv16f16.i64(<vscale x 16 x half> poison, <vscale x 16 x half> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x half> [[TMP0]]
//
vfloat16m4_t test_vfrec7_v_f16m4_rm(vfloat16m4_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x half> @test_vfrec7_v_f16m8_rm
// CHECK-RV64-SAME: (<vscale x 32 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x half> @llvm.riscv.vfrec7.nxv32f16.i64(<vscale x 32 x half> poison, <vscale x 32 x half> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x half> [[TMP0]]
//
vfloat16m8_t test_vfrec7_v_f16m8_rm(vfloat16m8_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfrec7_v_f32mf2_rm
// CHECK-RV64-SAME: (<vscale x 1 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfrec7.nxv1f32.i64(<vscale x 1 x float> poison, <vscale x 1 x float> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfrec7_v_f32mf2_rm(vfloat32mf2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfrec7_v_f32m1_rm
// CHECK-RV64-SAME: (<vscale x 2 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfrec7.nxv2f32.i64(<vscale x 2 x float> poison, <vscale x 2 x float> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfrec7_v_f32m1_rm(vfloat32m1_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfrec7_v_f32m2_rm
// CHECK-RV64-SAME: (<vscale x 4 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfrec7.nxv4f32.i64(<vscale x 4 x float> poison, <vscale x 4 x float> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfrec7_v_f32m2_rm(vfloat32m2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfrec7_v_f32m4_rm
// CHECK-RV64-SAME: (<vscale x 8 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfrec7.nxv8f32.i64(<vscale x 8 x float> poison, <vscale x 8 x float> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfrec7_v_f32m4_rm(vfloat32m4_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfrec7_v_f32m8_rm
// CHECK-RV64-SAME: (<vscale x 16 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfrec7.nxv16f32.i64(<vscale x 16 x float> poison, <vscale x 16 x float> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfrec7_v_f32m8_rm(vfloat32m8_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x double> @test_vfrec7_v_f64m1_rm
// CHECK-RV64-SAME: (<vscale x 1 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfrec7.nxv1f64.i64(<vscale x 1 x double> poison, <vscale x 1 x double> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfrec7_v_f64m1_rm(vfloat64m1_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x double> @test_vfrec7_v_f64m2_rm
// CHECK-RV64-SAME: (<vscale x 2 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfrec7.nxv2f64.i64(<vscale x 2 x double> poison, <vscale x 2 x double> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfrec7_v_f64m2_rm(vfloat64m2_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x double> @test_vfrec7_v_f64m4_rm
// CHECK-RV64-SAME: (<vscale x 4 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfrec7.nxv4f64.i64(<vscale x 4 x double> poison, <vscale x 4 x double> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfrec7_v_f64m4_rm(vfloat64m4_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x double> @test_vfrec7_v_f64m8_rm
// CHECK-RV64-SAME: (<vscale x 8 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfrec7.nxv8f64.i64(<vscale x 8 x double> poison, <vscale x 8 x double> [[OP1]], i64 0, i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfrec7_v_f64m8_rm(vfloat64m8_t op1, size_t vl) {
  return __riscv_vfrec7(op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x half> @test_vfrec7_v_f16mf4_rm_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x half> @llvm.riscv.vfrec7.mask.nxv1f16.i64(<vscale x 1 x half> poison, <vscale x 1 x half> [[OP1]], <vscale x 1 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x half> [[TMP0]]
//
vfloat16mf4_t test_vfrec7_v_f16mf4_rm_m(vbool64_t mask, vfloat16mf4_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x half> @test_vfrec7_v_f16mf2_rm_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x half> @llvm.riscv.vfrec7.mask.nxv2f16.i64(<vscale x 2 x half> poison, <vscale x 2 x half> [[OP1]], <vscale x 2 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x half> [[TMP0]]
//
vfloat16mf2_t test_vfrec7_v_f16mf2_rm_m(vbool32_t mask, vfloat16mf2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x half> @test_vfrec7_v_f16m1_rm_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfrec7.mask.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> [[OP1]], <vscale x 4 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfrec7_v_f16m1_rm_m(vbool16_t mask, vfloat16m1_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x half> @test_vfrec7_v_f16m2_rm_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x half> @llvm.riscv.vfrec7.mask.nxv8f16.i64(<vscale x 8 x half> poison, <vscale x 8 x half> [[OP1]], <vscale x 8 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
vfloat16m2_t test_vfrec7_v_f16m2_rm_m(vbool8_t mask, vfloat16m2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x half> @test_vfrec7_v_f16m4_rm_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x half> @llvm.riscv.vfrec7.mask.nxv16f16.i64(<vscale x 16 x half> poison, <vscale x 16 x half> [[OP1]], <vscale x 16 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x half> [[TMP0]]
//
vfloat16m4_t test_vfrec7_v_f16m4_rm_m(vbool4_t mask, vfloat16m4_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x half> @test_vfrec7_v_f16m8_rm_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], <vscale x 32 x half> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x half> @llvm.riscv.vfrec7.mask.nxv32f16.i64(<vscale x 32 x half> poison, <vscale x 32 x half> [[OP1]], <vscale x 32 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x half> [[TMP0]]
//
vfloat16m8_t test_vfrec7_v_f16m8_rm_m(vbool2_t mask, vfloat16m8_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfrec7_v_f32mf2_rm_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfrec7.mask.nxv1f32.i64(<vscale x 1 x float> poison, <vscale x 1 x float> [[OP1]], <vscale x 1 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfrec7_v_f32mf2_rm_m(vbool64_t mask, vfloat32mf2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfrec7_v_f32m1_rm_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfrec7.mask.nxv2f32.i64(<vscale x 2 x float> poison, <vscale x 2 x float> [[OP1]], <vscale x 2 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfrec7_v_f32m1_rm_m(vbool32_t mask, vfloat32m1_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfrec7_v_f32m2_rm_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfrec7.mask.nxv4f32.i64(<vscale x 4 x float> poison, <vscale x 4 x float> [[OP1]], <vscale x 4 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfrec7_v_f32m2_rm_m(vbool16_t mask, vfloat32m2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfrec7_v_f32m4_rm_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfrec7.mask.nxv8f32.i64(<vscale x 8 x float> poison, <vscale x 8 x float> [[OP1]], <vscale x 8 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfrec7_v_f32m4_rm_m(vbool8_t mask, vfloat32m4_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfrec7_v_f32m8_rm_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x float> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfrec7.mask.nxv16f32.i64(<vscale x 16 x float> poison, <vscale x 16 x float> [[OP1]], <vscale x 16 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfrec7_v_f32m8_rm_m(vbool4_t mask, vfloat32m8_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x double> @test_vfrec7_v_f64m1_rm_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfrec7.mask.nxv1f64.i64(<vscale x 1 x double> poison, <vscale x 1 x double> [[OP1]], <vscale x 1 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfrec7_v_f64m1_rm_m(vbool64_t mask, vfloat64m1_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x double> @test_vfrec7_v_f64m2_rm_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfrec7.mask.nxv2f64.i64(<vscale x 2 x double> poison, <vscale x 2 x double> [[OP1]], <vscale x 2 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfrec7_v_f64m2_rm_m(vbool32_t mask, vfloat64m2_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x double> @test_vfrec7_v_f64m4_rm_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfrec7.mask.nxv4f64.i64(<vscale x 4 x double> poison, <vscale x 4 x double> [[OP1]], <vscale x 4 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfrec7_v_f64m4_rm_m(vbool16_t mask, vfloat64m4_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x double> @test_vfrec7_v_f64m8_rm_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x double> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfrec7.mask.nxv8f64.i64(<vscale x 8 x double> poison, <vscale x 8 x double> [[OP1]], <vscale x 8 x i1> [[MASK]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfrec7_v_f64m8_rm_m(vbool8_t mask, vfloat64m8_t op1, size_t vl) {
  return __riscv_vfrec7(mask, op1, __RISCV_FRM_RNE, vl);
}

