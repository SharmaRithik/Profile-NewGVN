// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e16_v_bf16mf4x6(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv1bf16.i64(<vscale x 1 x bfloat> [[TMP0]], <vscale x 1 x bfloat> [[TMP1]], <vscale x 1 x bfloat> [[TMP2]], <vscale x 1 x bfloat> [[TMP3]], <vscale x 1 x bfloat> [[TMP4]], <vscale x 1 x bfloat> [[TMP5]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e16_v_bf16mf4x6(__bf16 *rs1, ptrdiff_t rs2,
                                 vbfloat16mf4x6_t vs3, size_t vl) {
  return __riscv_vssseg6e16_v_bf16mf4x6(rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e16_v_bf16mf2x6(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv2bf16.i64(<vscale x 2 x bfloat> [[TMP0]], <vscale x 2 x bfloat> [[TMP1]], <vscale x 2 x bfloat> [[TMP2]], <vscale x 2 x bfloat> [[TMP3]], <vscale x 2 x bfloat> [[TMP4]], <vscale x 2 x bfloat> [[TMP5]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e16_v_bf16mf2x6(__bf16 *rs1, ptrdiff_t rs2,
                                 vbfloat16mf2x6_t vs3, size_t vl) {
  return __riscv_vssseg6e16_v_bf16mf2x6(rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e16_v_bf16m1x6(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.nxv4bf16.i64(<vscale x 4 x bfloat> [[TMP0]], <vscale x 4 x bfloat> [[TMP1]], <vscale x 4 x bfloat> [[TMP2]], <vscale x 4 x bfloat> [[TMP3]], <vscale x 4 x bfloat> [[TMP4]], <vscale x 4 x bfloat> [[TMP5]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e16_v_bf16m1x6(__bf16 *rs1, ptrdiff_t rs2, vbfloat16m1x6_t vs3,
                                size_t vl) {
  return __riscv_vssseg6e16_v_bf16m1x6(rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e16_v_bf16mf4x6_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[VS3]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv1bf16.i64(<vscale x 1 x bfloat> [[TMP0]], <vscale x 1 x bfloat> [[TMP1]], <vscale x 1 x bfloat> [[TMP2]], <vscale x 1 x bfloat> [[TMP3]], <vscale x 1 x bfloat> [[TMP4]], <vscale x 1 x bfloat> [[TMP5]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e16_v_bf16mf4x6_m(vbool64_t vm, __bf16 *rs1, ptrdiff_t rs2,
                                   vbfloat16mf4x6_t vs3, size_t vl) {
  return __riscv_vssseg6e16_v_bf16mf4x6_m(vm, rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e16_v_bf16mf2x6_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[VS3]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv2bf16.i64(<vscale x 2 x bfloat> [[TMP0]], <vscale x 2 x bfloat> [[TMP1]], <vscale x 2 x bfloat> [[TMP2]], <vscale x 2 x bfloat> [[TMP3]], <vscale x 2 x bfloat> [[TMP4]], <vscale x 2 x bfloat> [[TMP5]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e16_v_bf16mf2x6_m(vbool32_t vm, __bf16 *rs1, ptrdiff_t rs2,
                                   vbfloat16mf2x6_t vs3, size_t vl) {
  return __riscv_vssseg6e16_v_bf16mf2x6_m(vm, rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg6e16_v_bf16m1x6_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 1
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 3
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 4
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[VS3]], 5
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg6.mask.nxv4bf16.i64(<vscale x 4 x bfloat> [[TMP0]], <vscale x 4 x bfloat> [[TMP1]], <vscale x 4 x bfloat> [[TMP2]], <vscale x 4 x bfloat> [[TMP3]], <vscale x 4 x bfloat> [[TMP4]], <vscale x 4 x bfloat> [[TMP5]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg6e16_v_bf16m1x6_m(vbool16_t vm, __bf16 *rs1, ptrdiff_t rs2,
                                  vbfloat16m1x6_t vs3, size_t vl) {
  return __riscv_vssseg6e16_v_bf16m1x6_m(vm, rs1, rs2, vs3, vl);
}
