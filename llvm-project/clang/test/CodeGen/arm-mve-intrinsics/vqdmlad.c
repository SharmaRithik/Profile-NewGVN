// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve.fp -mfloat-abi hard -O0 -disable-O0-optnone -emit-llvm -o - %s | opt -S -passes=mem2reg | FileCheck %s
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve.fp -mfloat-abi hard -O0 -disable-O0-optnone -DPOLYMORPHIC -emit-llvm -o - %s | opt -S -passes=mem2reg | FileCheck %s

// REQUIRES: aarch64-registered-target || arm-registered-target

#include <arm_mve.h>

// CHECK-LABEL: @test_vqdmladhq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.v16i8(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 0, i32 0, i32 0)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vqdmladhq_s8(int8x16_t inactive, int8x16_t a, int8x16_t b) {
#ifdef POLYMORPHIC
  return vqdmladhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmladhq_s8(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.v8i16(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 0, i32 0, i32 0)
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vqdmladhq_s16(int16x8_t inactive, int16x8_t a, int16x8_t b) {
#ifdef POLYMORPHIC
  return vqdmladhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmladhq_s16(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.v4i32(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 0, i32 0, i32 0)
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vqdmladhq_s32(int32x4_t inactive, int32x4_t a, int32x4_t b) {
#ifdef POLYMORPHIC
  return vqdmladhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmladhq_s32(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhxq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.v16i8(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 1, i32 0, i32 0)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vqdmladhxq_s8(int8x16_t inactive, int8x16_t a, int8x16_t b) {
#ifdef POLYMORPHIC
  return vqdmladhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmladhxq_s8(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhxq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.v8i16(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 1, i32 0, i32 0)
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vqdmladhxq_s16(int16x8_t inactive, int16x8_t a, int16x8_t b) {
#ifdef POLYMORPHIC
  return vqdmladhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmladhxq_s16(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhxq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.v4i32(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 1, i32 0, i32 0)
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vqdmladhxq_s32(int32x4_t inactive, int32x4_t a, int32x4_t b) {
#ifdef POLYMORPHIC
  return vqdmladhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmladhxq_s32(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.v16i8(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 0, i32 0, i32 1)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vqdmlsdhq_s8(int8x16_t inactive, int8x16_t a, int8x16_t b) {
#ifdef POLYMORPHIC
  return vqdmlsdhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmlsdhq_s8(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.v8i16(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 0, i32 0, i32 1)
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vqdmlsdhq_s16(int16x8_t inactive, int16x8_t a, int16x8_t b) {
#ifdef POLYMORPHIC
  return vqdmlsdhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmlsdhq_s16(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.v4i32(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 0, i32 0, i32 1)
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vqdmlsdhq_s32(int32x4_t inactive, int32x4_t a, int32x4_t b) {
#ifdef POLYMORPHIC
  return vqdmlsdhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmlsdhq_s32(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhxq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.v16i8(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 1, i32 0, i32 1)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vqdmlsdhxq_s8(int8x16_t inactive, int8x16_t a, int8x16_t b) {
#ifdef POLYMORPHIC
  return vqdmlsdhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmlsdhxq_s8(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhxq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.v8i16(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 1, i32 0, i32 1)
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vqdmlsdhxq_s16(int16x8_t inactive, int16x8_t a, int16x8_t b) {
#ifdef POLYMORPHIC
  return vqdmlsdhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmlsdhxq_s16(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhxq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.v4i32(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 1, i32 0, i32 1)
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vqdmlsdhxq_s32(int32x4_t inactive, int32x4_t a, int32x4_t b) {
#ifdef POLYMORPHIC
  return vqdmlsdhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqdmlsdhxq_s32(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.v16i8(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 0, i32 1, i32 0)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vqrdmladhq_s8(int8x16_t inactive, int8x16_t a, int8x16_t b) {
#ifdef POLYMORPHIC
  return vqrdmladhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmladhq_s8(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.v8i16(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 0, i32 1, i32 0)
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vqrdmladhq_s16(int16x8_t inactive, int16x8_t a, int16x8_t b) {
#ifdef POLYMORPHIC
  return vqrdmladhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmladhq_s16(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.v4i32(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 0, i32 1, i32 0)
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vqrdmladhq_s32(int32x4_t inactive, int32x4_t a, int32x4_t b) {
#ifdef POLYMORPHIC
  return vqrdmladhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmladhq_s32(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhxq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.v16i8(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 1, i32 1, i32 0)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vqrdmladhxq_s8(int8x16_t inactive, int8x16_t a, int8x16_t b) {
#ifdef POLYMORPHIC
  return vqrdmladhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmladhxq_s8(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhxq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.v8i16(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 1, i32 1, i32 0)
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vqrdmladhxq_s16(int16x8_t inactive, int16x8_t a, int16x8_t b) {
#ifdef POLYMORPHIC
  return vqrdmladhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmladhxq_s16(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhxq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.v4i32(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 1, i32 1, i32 0)
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vqrdmladhxq_s32(int32x4_t inactive, int32x4_t a, int32x4_t b) {
#ifdef POLYMORPHIC
  return vqrdmladhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmladhxq_s32(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.v16i8(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 0, i32 1, i32 1)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vqrdmlsdhq_s8(int8x16_t inactive, int8x16_t a, int8x16_t b) {
#ifdef POLYMORPHIC
  return vqrdmlsdhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmlsdhq_s8(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.v8i16(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 0, i32 1, i32 1)
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vqrdmlsdhq_s16(int16x8_t inactive, int16x8_t a, int16x8_t b) {
#ifdef POLYMORPHIC
  return vqrdmlsdhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmlsdhq_s16(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.v4i32(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 0, i32 1, i32 1)
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vqrdmlsdhq_s32(int32x4_t inactive, int32x4_t a, int32x4_t b) {
#ifdef POLYMORPHIC
  return vqrdmlsdhq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmlsdhq_s32(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhxq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.v16i8(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 1, i32 1, i32 1)
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vqrdmlsdhxq_s8(int8x16_t inactive, int8x16_t a, int8x16_t b) {
#ifdef POLYMORPHIC
  return vqrdmlsdhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmlsdhxq_s8(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhxq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.v8i16(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 1, i32 1, i32 1)
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vqrdmlsdhxq_s16(int16x8_t inactive, int16x8_t a, int16x8_t b) {
#ifdef POLYMORPHIC
  return vqrdmlsdhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmlsdhxq_s16(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhxq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.v4i32(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 1, i32 1, i32 1)
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vqrdmlsdhxq_s32(int32x4_t inactive, int32x4_t a, int32x4_t b) {
#ifdef POLYMORPHIC
  return vqrdmlsdhxq(inactive, a, b);
#else  /* POLYMORPHIC */
  return vqrdmlsdhxq_s32(inactive, a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 0, i32 0, i32 0, <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vqdmladhq_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmladhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmladhq_m_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.predicated.v8i16.v8i1(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 0, i32 0, i32 0, <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vqdmladhq_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmladhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmladhq_m_s16(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhq_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.predicated.v4i32.v4i1(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 0, i32 0, i32 0, <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vqdmladhq_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmladhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmladhq_m_s32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhxq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 1, i32 0, i32 0, <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vqdmladhxq_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmladhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmladhxq_m_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhxq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.predicated.v8i16.v8i1(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 1, i32 0, i32 0, <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vqdmladhxq_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmladhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmladhxq_m_s16(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmladhxq_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.predicated.v4i32.v4i1(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 1, i32 0, i32 0, <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vqdmladhxq_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmladhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmladhxq_m_s32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 0, i32 0, i32 1, <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vqdmlsdhq_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmlsdhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmlsdhq_m_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.predicated.v8i16.v8i1(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 0, i32 0, i32 1, <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vqdmlsdhq_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmlsdhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmlsdhq_m_s16(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhq_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.predicated.v4i32.v4i1(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 0, i32 0, i32 1, <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vqdmlsdhq_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmlsdhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmlsdhq_m_s32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhxq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 1, i32 0, i32 1, <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vqdmlsdhxq_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmlsdhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmlsdhxq_m_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhxq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.predicated.v8i16.v8i1(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 1, i32 0, i32 1, <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vqdmlsdhxq_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmlsdhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmlsdhxq_m_s16(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqdmlsdhxq_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.predicated.v4i32.v4i1(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 1, i32 0, i32 1, <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vqdmlsdhxq_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqdmlsdhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqdmlsdhxq_m_s32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 0, i32 1, i32 0, <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vqrdmladhq_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmladhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmladhq_m_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.predicated.v8i16.v8i1(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 0, i32 1, i32 0, <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vqrdmladhq_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmladhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmladhq_m_s16(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhq_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.predicated.v4i32.v4i1(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 0, i32 1, i32 0, <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vqrdmladhq_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmladhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmladhq_m_s32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhxq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 1, i32 1, i32 0, <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vqrdmladhxq_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmladhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmladhxq_m_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhxq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.predicated.v8i16.v8i1(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 1, i32 1, i32 0, <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vqrdmladhxq_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmladhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmladhxq_m_s16(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmladhxq_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.predicated.v4i32.v4i1(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 1, i32 1, i32 0, <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vqrdmladhxq_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmladhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmladhxq_m_s32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 0, i32 1, i32 1, <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vqrdmlsdhq_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmlsdhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmlsdhq_m_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.predicated.v8i16.v8i1(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 0, i32 1, i32 1, <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vqrdmlsdhq_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmlsdhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmlsdhq_m_s16(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhq_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.predicated.v4i32.v4i1(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 0, i32 1, i32 1, <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vqrdmlsdhq_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmlsdhq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmlsdhq_m_s32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhxq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vqdmlad.predicated.v16i8.v16i1(<16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], i32 1, i32 1, i32 1, <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vqrdmlsdhxq_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmlsdhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmlsdhxq_m_s8(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhxq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vqdmlad.predicated.v8i16.v8i1(<8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], i32 1, i32 1, i32 1, <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vqrdmlsdhxq_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmlsdhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmlsdhxq_m_s16(inactive, a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vqrdmlsdhxq_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vqdmlad.predicated.v4i32.v4i1(<4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], i32 1, i32 1, i32 1, <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vqrdmlsdhxq_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p) {
#ifdef POLYMORPHIC
  return vqrdmlsdhxq_m(inactive, a, b, p);
#else  /* POLYMORPHIC */
  return vqrdmlsdhxq_m_s32(inactive, a, b, p);
#endif /* POLYMORPHIC */
}
