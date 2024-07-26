// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e64_v_f64m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv1f64.i64(<vscale x 1 x double> [[TMP0]], <vscale x 1 x double> [[TMP1]], <vscale x 1 x double> [[TMP2]], <vscale x 1 x double> [[TMP3]], <vscale x 1 x double> [[TMP4]], <vscale x 1 x double> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e64_v_f64m1x6(double *base, ptrdiff_t bstride, vfloat64m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e64_v_f64m1x6(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e64_v_i64m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], <vscale x 1 x i64> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e64_v_i64m1x6(int64_t *base, ptrdiff_t bstride, vint64m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e64_v_i64m1x6(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e64_v_u64m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], <vscale x 1 x i64> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e64_v_u64m1x6(uint64_t *base, ptrdiff_t bstride, vuint64m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e64_v_u64m1x6(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e64_v_f64m1x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv1f64.i64(<vscale x 1 x double> [[TMP0]], <vscale x 1 x double> [[TMP1]], <vscale x 1 x double> [[TMP2]], <vscale x 1 x double> [[TMP3]], <vscale x 1 x double> [[TMP4]], <vscale x 1 x double> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e64_v_f64m1x6_m(vbool64_t mask, double *base, ptrdiff_t bstride, vfloat64m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e64_v_f64m1x6_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e64_v_i64m1x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], <vscale x 1 x i64> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e64_v_i64m1x6_m(vbool64_t mask, int64_t *base, ptrdiff_t bstride, vint64m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e64_v_i64m1x6_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e64_v_u64m1x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[V_TUPLE]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv1i64.i64(<vscale x 1 x i64> [[TMP0]], <vscale x 1 x i64> [[TMP1]], <vscale x 1 x i64> [[TMP2]], <vscale x 1 x i64> [[TMP3]], <vscale x 1 x i64> [[TMP4]], <vscale x 1 x i64> [[TMP5]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e64_v_u64m1x6_m(vbool64_t mask, uint64_t *base, ptrdiff_t bstride, vuint64m1x6_t v_tuple, size_t vl) {
  return __riscv_vssseg6e64_v_u64m1x6_m(mask, base, bstride, v_tuple, vl);
}

