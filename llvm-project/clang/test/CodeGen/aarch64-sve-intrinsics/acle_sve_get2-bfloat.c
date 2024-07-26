// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sve -target-feature +sme -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

#ifdef __ARM_FEATURE_SME
#define ATTR __arm_streaming
#else
#define ATTR
#endif

// CHECK-LABEL: @test_svget2_bf16_0(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv16bf16(<vscale x 16 x bfloat> [[TUPLE:%.*]], i64 0)
// CHECK-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svget2_bf16_014svbfloat16x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv16bf16(<vscale x 16 x bfloat> [[TUPLE:%.*]], i64 0)
// CPP-CHECK-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
svbfloat16_t test_svget2_bf16_0(svbfloat16x2_t tuple) ATTR
{
  return SVE_ACLE_FUNC(svget2,_bf16,,)(tuple, 0);
}

// CHECK-LABEL: @test_svget2_bf16_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv16bf16(<vscale x 16 x bfloat> [[TUPLE:%.*]], i64 8)
// CHECK-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svget2_bf16_114svbfloat16x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv16bf16(<vscale x 16 x bfloat> [[TUPLE:%.*]], i64 8)
// CPP-CHECK-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
svbfloat16_t test_svget2_bf16_1(svbfloat16x2_t tuple) ATTR
{
  return SVE_ACLE_FUNC(svget2,_bf16,,)(tuple, 1);
}
