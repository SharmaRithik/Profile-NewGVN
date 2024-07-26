// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -fclang-abi-compat=latest -triple aarch64 -target-feature +sve -target-feature +sve2 -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -fclang-abi-compat=latest -triple aarch64 -target-feature +sve -target-feature +sve2 -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -fclang-abi-compat=latest -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +sve2 -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -fclang-abi-compat=latest -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +sve2 -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK

// REQUIRES: aarch64-registered-target

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svqabs_s8_z(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.sqabs.nxv16i8(<vscale x 16 x i8> zeroinitializer, <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqabs_s8_zu10__SVBool_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.sqabs.nxv16i8(<vscale x 16 x i8> zeroinitializer, <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svint8_t test_svqabs_s8_z(svbool_t pg, svint8_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s8,_z,)(pg, op);
}

// CHECK-LABEL: @test_svqabs_s16_z(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqabs.nxv8i16(<vscale x 8 x i16> zeroinitializer, <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s16_zu10__SVBool_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqabs.nxv8i16(<vscale x 8 x i16> zeroinitializer, <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
svint16_t test_svqabs_s16_z(svbool_t pg, svint16_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s16,_z,)(pg, op);
}

// CHECK-LABEL: @test_svqabs_s32_z(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqabs.nxv4i32(<vscale x 4 x i32> zeroinitializer, <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s32_zu10__SVBool_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqabs.nxv4i32(<vscale x 4 x i32> zeroinitializer, <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
svint32_t test_svqabs_s32_z(svbool_t pg, svint32_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s32,_z,)(pg, op);
}

// CHECK-LABEL: @test_svqabs_s64_z(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqabs.nxv2i64(<vscale x 2 x i64> zeroinitializer, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s64_zu10__SVBool_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqabs.nxv2i64(<vscale x 2 x i64> zeroinitializer, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
svint64_t test_svqabs_s64_z(svbool_t pg, svint64_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s64,_z,)(pg, op);
}

// CHECK-LABEL: @test_svqabs_s8_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.sqabs.nxv16i8(<vscale x 16 x i8> [[INACTIVE:%.*]], <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqabs_s8_mu10__SVInt8_tu10__SVBool_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.sqabs.nxv16i8(<vscale x 16 x i8> [[INACTIVE:%.*]], <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svint8_t test_svqabs_s8_m(svint8_t inactive, svbool_t pg, svint8_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s8,_m,)(inactive, pg, op);
}

// CHECK-LABEL: @test_svqabs_s16_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqabs.nxv8i16(<vscale x 8 x i16> [[INACTIVE:%.*]], <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s16_mu11__SVInt16_tu10__SVBool_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqabs.nxv8i16(<vscale x 8 x i16> [[INACTIVE:%.*]], <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
svint16_t test_svqabs_s16_m(svint16_t inactive, svbool_t pg, svint16_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s16,_m,)(inactive, pg, op);
}

// CHECK-LABEL: @test_svqabs_s32_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqabs.nxv4i32(<vscale x 4 x i32> [[INACTIVE:%.*]], <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s32_mu11__SVInt32_tu10__SVBool_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqabs.nxv4i32(<vscale x 4 x i32> [[INACTIVE:%.*]], <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
svint32_t test_svqabs_s32_m(svint32_t inactive, svbool_t pg, svint32_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s32,_m,)(inactive, pg, op);
}

// CHECK-LABEL: @test_svqabs_s64_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqabs.nxv2i64(<vscale x 2 x i64> [[INACTIVE:%.*]], <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s64_mu11__SVInt64_tu10__SVBool_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqabs.nxv2i64(<vscale x 2 x i64> [[INACTIVE:%.*]], <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
svint64_t test_svqabs_s64_m(svint64_t inactive, svbool_t pg, svint64_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s64,_m,)(inactive, pg, op);
}

// CHECK-LABEL: @test_svqabs_s8_x(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.sqabs.nxv16i8(<vscale x 16 x i8> undef, <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqabs_s8_xu10__SVBool_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.sqabs.nxv16i8(<vscale x 16 x i8> undef, <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svint8_t test_svqabs_s8_x(svbool_t pg, svint8_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s8,_x,)(pg, op);
}

// CHECK-LABEL: @test_svqabs_s16_x(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqabs.nxv8i16(<vscale x 8 x i16> undef, <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s16_xu10__SVBool_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqabs.nxv8i16(<vscale x 8 x i16> undef, <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
svint16_t test_svqabs_s16_x(svbool_t pg, svint16_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s16,_x,)(pg, op);
}

// CHECK-LABEL: @test_svqabs_s32_x(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqabs.nxv4i32(<vscale x 4 x i32> undef, <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s32_xu10__SVBool_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqabs.nxv4i32(<vscale x 4 x i32> undef, <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
svint32_t test_svqabs_s32_x(svbool_t pg, svint32_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s32,_x,)(pg, op);
}

// CHECK-LABEL: @test_svqabs_s64_x(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqabs.nxv2i64(<vscale x 2 x i64> undef, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z17test_svqabs_s64_xu10__SVBool_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.sqabs.nxv2i64(<vscale x 2 x i64> undef, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
svint64_t test_svqabs_s64_x(svbool_t pg, svint64_t op)
{
  return SVE_ACLE_FUNC(svqabs,_s64,_x,)(pg, op);
}
