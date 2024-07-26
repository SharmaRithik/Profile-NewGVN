// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve.fp -mfloat-abi hard -O0 -disable-O0-optnone -emit-llvm -o - %s | opt -S -passes=mem2reg | FileCheck %s
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve.fp -mfloat-abi hard -O0 -disable-O0-optnone -DPOLYMORPHIC -emit-llvm -o - %s | opt -S -passes=mem2reg | FileCheck %s

// REQUIRES: aarch64-registered-target || arm-registered-target

#include <arm_mve.h>

// CHECK-LABEL: @test_vbrsrq_n_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vbrsr.v4i32(<4 x i32> [[A:%.*]], i32 [[B:%.*]])
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
uint32x4_t test_vbrsrq_n_u32(uint32x4_t a, int32_t b) {
#ifdef POLYMORPHIC
  return vbrsrq(a, b);
#else  /* POLYMORPHIC */
  return vbrsrq_n_u32(a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vbrsrq_n_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x half> @llvm.arm.mve.vbrsr.v8f16(<8 x half> [[A:%.*]], i32 [[B:%.*]])
// CHECK-NEXT:    ret <8 x half> [[TMP0]]
//
float16x8_t test_vbrsrq_n_f16(float16x8_t a, int32_t b) {
#ifdef POLYMORPHIC
  return vbrsrq(a, b);
#else  /* POLYMORPHIC */
  return vbrsrq_n_f16(a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vbrsrq_m_n_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vbrsr.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], i32 [[B:%.*]], <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vbrsrq_m_n_s8(int8x16_t inactive, int8x16_t a, int32_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vbrsrq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vbrsrq_m_n_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vbrsrq_m_n_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x float> @llvm.arm.mve.vbrsr.predicated.v4f32.v4i1(<4 x float> [[INACTIVE:%.*]], <4 x float> [[A:%.*]], i32 [[B:%.*]], <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x float> [[TMP2]]
//
float32x4_t test_vbrsrq_m_n_f32(float32x4_t inactive, float32x4_t a, int32_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vbrsrq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vbrsrq_m_n_f32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vbrsrq_x_n_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vbrsr.predicated.v8i16.v8i1(<8 x i16> undef, <8 x i16> [[A:%.*]], i32 [[B:%.*]], <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
uint16x8_t test_vbrsrq_x_n_u16(uint16x8_t a, int32_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vbrsrq_x(a, b, p);
#else  /* POLYMORPHIC */
  return vbrsrq_x_n_u16(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vbrsrq_x_n_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x half> @llvm.arm.mve.vbrsr.predicated.v8f16.v8i1(<8 x half> undef, <8 x half> [[A:%.*]], i32 [[B:%.*]], <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x half> [[TMP2]]
//
float16x8_t test_vbrsrq_x_n_f16(float16x8_t a, int32_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vbrsrq_x(a, b, p);
#else  /* POLYMORPHIC */
  return vbrsrq_x_n_f16(a, b, p);
#endif /* POLYMORPHIC */
}

