// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i8> @test_vle8_v_i8mf8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vle.mask.nxv1i8.i64(<vscale x 1 x i8> poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP0]]
//
vint8mf8_t test_vle8_v_i8mf8_m(vbool64_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i8> @test_vle8_v_i8mf4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vle.mask.nxv2i8.i64(<vscale x 2 x i8> poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP0]]
//
vint8mf4_t test_vle8_v_i8mf4_m(vbool32_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i8> @test_vle8_v_i8mf2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vle.mask.nxv4i8.i64(<vscale x 4 x i8> poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP0]]
//
vint8mf2_t test_vle8_v_i8mf2_m(vbool16_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i8> @test_vle8_v_i8m1_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vle.mask.nxv8i8.i64(<vscale x 8 x i8> poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vint8m1_t test_vle8_v_i8m1_m(vbool8_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i8> @test_vle8_v_i8m2_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vle.mask.nxv16i8.i64(<vscale x 16 x i8> poison, ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vint8m2_t test_vle8_v_i8m2_m(vbool4_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x i8> @test_vle8_v_i8m4_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vle.mask.nxv32i8.i64(<vscale x 32 x i8> poison, ptr [[BASE]], <vscale x 32 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vint8m4_t test_vle8_v_i8m4_m(vbool2_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 64 x i8> @test_vle8_v_i8m8_m
// CHECK-RV64-SAME: (<vscale x 64 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vle.mask.nxv64i8.i64(<vscale x 64 x i8> poison, ptr [[BASE]], <vscale x 64 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP0]]
//
vint8m8_t test_vle8_v_i8m8_m(vbool1_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i8> @test_vle8_v_u8mf8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vle.mask.nxv1i8.i64(<vscale x 1 x i8> poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP0]]
//
vuint8mf8_t test_vle8_v_u8mf8_m(vbool64_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i8> @test_vle8_v_u8mf4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vle.mask.nxv2i8.i64(<vscale x 2 x i8> poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP0]]
//
vuint8mf4_t test_vle8_v_u8mf4_m(vbool32_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i8> @test_vle8_v_u8mf2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vle.mask.nxv4i8.i64(<vscale x 4 x i8> poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP0]]
//
vuint8mf2_t test_vle8_v_u8mf2_m(vbool16_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i8> @test_vle8_v_u8m1_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vle.mask.nxv8i8.i64(<vscale x 8 x i8> poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vuint8m1_t test_vle8_v_u8m1_m(vbool8_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i8> @test_vle8_v_u8m2_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vle.mask.nxv16i8.i64(<vscale x 16 x i8> poison, ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vuint8m2_t test_vle8_v_u8m2_m(vbool4_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x i8> @test_vle8_v_u8m4_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vle.mask.nxv32i8.i64(<vscale x 32 x i8> poison, ptr [[BASE]], <vscale x 32 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vuint8m4_t test_vle8_v_u8m4_m(vbool2_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 64 x i8> @test_vle8_v_u8m8_m
// CHECK-RV64-SAME: (<vscale x 64 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vle.mask.nxv64i8.i64(<vscale x 64 x i8> poison, ptr [[BASE]], <vscale x 64 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP0]]
//
vuint8m8_t test_vle8_v_u8m8_m(vbool1_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8(mask, base, vl);
}

