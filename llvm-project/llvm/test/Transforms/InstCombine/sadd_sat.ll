; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s -passes=instcombine -S | FileCheck %s

target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"

define i32 @sadd_sat32(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[B:%.*]], i32 [[A:%.*]])
; CHECK-NEXT:    ret i32 [[TMP0]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp slt i64 %add, 2147483647
  %spec.store.select = select i1 %0, i64 %add, i64 2147483647
  %1 = icmp sgt i64 %spec.store.select, -2147483648
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -2147483648
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @sadd_sat32_mm(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[B:%.*]], i32 [[A:%.*]])
; CHECK-NEXT:    ret i32 [[TMP0]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %spec.store.select = call i64 @llvm.smin.i64(i64 %add, i64 2147483647)
  %spec.store.select8 = call i64 @llvm.smax.i64(i64 %spec.store.select, i64 -2147483648)
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @ssub_sat32(i32 %a, i32 %b) {
; CHECK-LABEL: @ssub_sat32(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.ssub.sat.i32(i32 [[A:%.*]], i32 [[B:%.*]])
; CHECK-NEXT:    ret i32 [[TMP0]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %sub = sub i64 %conv, %conv1
  %0 = icmp slt i64 %sub, 2147483647
  %spec.store.select = select i1 %0, i64 %sub, i64 2147483647
  %1 = icmp sgt i64 %spec.store.select, -2147483648
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -2147483648
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @ssub_sat32_mm(i32 %a, i32 %b) {
; CHECK-LABEL: @ssub_sat32_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.ssub.sat.i32(i32 [[A:%.*]], i32 [[B:%.*]])
; CHECK-NEXT:    ret i32 [[TMP0]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %sub = sub i64 %conv, %conv1
  %spec.store.select = call i64 @llvm.smin.i64(i64 %sub, i64 2147483647)
  %spec.store.select8 = call i64 @llvm.smax.i64(i64 %spec.store.select, i64 -2147483648)
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @smul_sat32(i32 %a, i32 %b) {
; CHECK-LABEL: @smul_sat32(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[A:%.*]] to i64
; CHECK-NEXT:    [[CONV1:%.*]] = sext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = mul nsw i64 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.smin.i64(i64 [[ADD]], i64 2147483647)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i64 @llvm.smax.i64(i64 [[SPEC_STORE_SELECT]], i64 -2147483648)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i64 [[SPEC_STORE_SELECT8]] to i32
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = mul i64 %conv1, %conv
  %0 = icmp slt i64 %add, 2147483647
  %spec.store.select = select i1 %0, i64 %add, i64 2147483647
  %1 = icmp sgt i64 %spec.store.select, -2147483648
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -2147483648
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @smul_sat32_mm(i32 %a, i32 %b) {
; CHECK-LABEL: @smul_sat32_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[A:%.*]] to i64
; CHECK-NEXT:    [[CONV1:%.*]] = sext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = mul nsw i64 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.smin.i64(i64 [[ADD]], i64 2147483647)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i64 @llvm.smax.i64(i64 [[SPEC_STORE_SELECT]], i64 -2147483648)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i64 [[SPEC_STORE_SELECT8]] to i32
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = mul i64 %conv1, %conv
  %spec.store.select = call i64 @llvm.smin.i64(i64 %add, i64 2147483647)
  %spec.store.select8 = call i64 @llvm.smax.i64(i64 %spec.store.select, i64 -2147483648)
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define signext i16 @sadd_sat16(i16 signext %a, i16 signext %b) {
; CHECK-LABEL: @sadd_sat16(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i16 @llvm.sadd.sat.i16(i16 [[B:%.*]], i16 [[A:%.*]])
; CHECK-NEXT:    ret i16 [[TMP0]]
;
entry:
  %conv = sext i16 %a to i32
  %conv1 = sext i16 %b to i32
  %add = add i32 %conv1, %conv
  %0 = icmp slt i32 %add, 32767
  %spec.store.select = select i1 %0, i32 %add, i32 32767
  %1 = icmp sgt i32 %spec.store.select, -32768
  %spec.store.select10 = select i1 %1, i32 %spec.store.select, i32 -32768
  %conv9 = trunc i32 %spec.store.select10 to i16
  ret i16 %conv9
}

define signext i16 @sadd_sat16_mm(i16 signext %a, i16 signext %b) {
; CHECK-LABEL: @sadd_sat16_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i16 @llvm.sadd.sat.i16(i16 [[B:%.*]], i16 [[A:%.*]])
; CHECK-NEXT:    ret i16 [[TMP0]]
;
entry:
  %conv = sext i16 %a to i32
  %conv1 = sext i16 %b to i32
  %add = add i32 %conv1, %conv
  %spec.store.select = call i32 @llvm.smin.i32(i32 %add, i32 32767)
  %spec.store.select10 = call i32 @llvm.smax.i32(i32 %spec.store.select, i32 -32768)
  %conv9 = trunc i32 %spec.store.select10 to i16
  ret i16 %conv9
}

define signext i16 @ssub_sat16(i16 signext %a, i16 signext %b) {
; CHECK-LABEL: @ssub_sat16(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i16 @llvm.ssub.sat.i16(i16 [[A:%.*]], i16 [[B:%.*]])
; CHECK-NEXT:    ret i16 [[TMP0]]
;
entry:
  %conv = sext i16 %a to i32
  %conv1 = sext i16 %b to i32
  %sub = sub i32 %conv, %conv1
  %0 = icmp slt i32 %sub, 32767
  %spec.store.select = select i1 %0, i32 %sub, i32 32767
  %1 = icmp sgt i32 %spec.store.select, -32768
  %spec.store.select10 = select i1 %1, i32 %spec.store.select, i32 -32768
  %conv9 = trunc i32 %spec.store.select10 to i16
  ret i16 %conv9
}

define signext i16 @ssub_sat16_mm(i16 signext %a, i16 signext %b) {
; CHECK-LABEL: @ssub_sat16_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i16 @llvm.ssub.sat.i16(i16 [[A:%.*]], i16 [[B:%.*]])
; CHECK-NEXT:    ret i16 [[TMP0]]
;
entry:
  %conv = sext i16 %a to i32
  %conv1 = sext i16 %b to i32
  %sub = sub i32 %conv, %conv1
  %spec.store.select = call i32 @llvm.smin.i32(i32 %sub, i32 32767)
  %spec.store.select10 = call i32 @llvm.smax.i32(i32 %spec.store.select, i32 -32768)
  %conv9 = trunc i32 %spec.store.select10 to i16
  ret i16 %conv9
}

define signext i8 @sadd_sat8(i8 signext %a, i8 signext %b) {
; CHECK-LABEL: @sadd_sat8(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i8 @llvm.sadd.sat.i8(i8 [[B:%.*]], i8 [[A:%.*]])
; CHECK-NEXT:    ret i8 [[TMP0]]
;
entry:
  %conv = sext i8 %a to i32
  %conv1 = sext i8 %b to i32
  %add = add i32 %conv1, %conv
  %0 = icmp slt i32 %add, 127
  %spec.store.select = select i1 %0, i32 %add, i32 127
  %1 = icmp sgt i32 %spec.store.select, -128
  %spec.store.select10 = select i1 %1, i32 %spec.store.select, i32 -128
  %conv9 = trunc i32 %spec.store.select10 to i8
  ret i8 %conv9
}

define signext i8 @sadd_sat8_mm(i8 signext %a, i8 signext %b) {
; CHECK-LABEL: @sadd_sat8_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i8 @llvm.sadd.sat.i8(i8 [[B:%.*]], i8 [[A:%.*]])
; CHECK-NEXT:    ret i8 [[TMP0]]
;
entry:
  %conv = sext i8 %a to i32
  %conv1 = sext i8 %b to i32
  %add = add i32 %conv1, %conv
  %spec.store.select = call i32 @llvm.smin.i32(i32 %add, i32 127)
  %spec.store.select10 = call i32 @llvm.smax.i32(i32 %spec.store.select, i32 -128)
  %conv9 = trunc i32 %spec.store.select10 to i8
  ret i8 %conv9
}

define signext i8 @ssub_sat8(i8 signext %a, i8 signext %b) {
; CHECK-LABEL: @ssub_sat8(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i8 @llvm.ssub.sat.i8(i8 [[A:%.*]], i8 [[B:%.*]])
; CHECK-NEXT:    ret i8 [[TMP0]]
;
entry:
  %conv = sext i8 %a to i32
  %conv1 = sext i8 %b to i32
  %sub = sub i32 %conv, %conv1
  %0 = icmp slt i32 %sub, 127
  %spec.store.select = select i1 %0, i32 %sub, i32 127
  %1 = icmp sgt i32 %spec.store.select, -128
  %spec.store.select10 = select i1 %1, i32 %spec.store.select, i32 -128
  %conv9 = trunc i32 %spec.store.select10 to i8
  ret i8 %conv9
}

define signext i8 @ssub_sat8_mm(i8 signext %a, i8 signext %b) {
; CHECK-LABEL: @ssub_sat8_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i8 @llvm.ssub.sat.i8(i8 [[A:%.*]], i8 [[B:%.*]])
; CHECK-NEXT:    ret i8 [[TMP0]]
;
entry:
  %conv = sext i8 %a to i32
  %conv1 = sext i8 %b to i32
  %sub = sub i32 %conv, %conv1
  %spec.store.select = call i32 @llvm.smin.i32(i32 %sub, i32 127)
  %spec.store.select10 = call i32 @llvm.smax.i32(i32 %spec.store.select, i32 -128)
  %conv9 = trunc i32 %spec.store.select10 to i8
  ret i8 %conv9
}

define signext i64 @sadd_sat64(i64 signext %a, i64 signext %b) {
; CHECK-LABEL: @sadd_sat64(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i64 @llvm.sadd.sat.i64(i64 [[B:%.*]], i64 [[A:%.*]])
; CHECK-NEXT:    ret i64 [[TMP0]]
;
entry:
  %conv = sext i64 %a to i65
  %conv1 = sext i64 %b to i65
  %add = add i65 %conv1, %conv
  %0 = icmp slt i65 %add, 9223372036854775807
  %spec.store.select = select i1 %0, i65 %add, i65 9223372036854775807
  %1 = icmp sgt i65 %spec.store.select, -9223372036854775808
  %spec.store.select10 = select i1 %1, i65 %spec.store.select, i65 -9223372036854775808
  %conv9 = trunc i65 %spec.store.select10 to i64
  ret i64 %conv9
}

define signext i64 @ssub_sat64(i64 signext %a, i64 signext %b) {
; CHECK-LABEL: @ssub_sat64(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i64 @llvm.ssub.sat.i64(i64 [[A:%.*]], i64 [[B:%.*]])
; CHECK-NEXT:    ret i64 [[TMP0]]
;
entry:
  %conv = sext i64 %a to i65
  %conv1 = sext i64 %b to i65
  %sub = sub i65 %conv, %conv1
  %0 = icmp slt i65 %sub, 9223372036854775807
  %spec.store.select = select i1 %0, i65 %sub, i65 9223372036854775807
  %1 = icmp sgt i65 %spec.store.select, -9223372036854775808
  %spec.store.select10 = select i1 %1, i65 %spec.store.select, i65 -9223372036854775808
  %conv9 = trunc i65 %spec.store.select10 to i64
  ret i64 %conv9
}

define signext i4 @sadd_sat4(i4 signext %a, i4 signext %b) {
; CHECK-LABEL: @sadd_sat4(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i4 [[A:%.*]] to i32
; CHECK-NEXT:    [[CONV1:%.*]] = sext i4 [[B:%.*]] to i32
; CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i32 @llvm.smin.i32(i32 [[ADD]], i32 7)
; CHECK-NEXT:    [[SPEC_STORE_SELECT10:%.*]] = call i32 @llvm.smax.i32(i32 [[SPEC_STORE_SELECT]], i32 -8)
; CHECK-NEXT:    [[CONV9:%.*]] = trunc nsw i32 [[SPEC_STORE_SELECT10]] to i4
; CHECK-NEXT:    ret i4 [[CONV9]]
;
entry:
  %conv = sext i4 %a to i32
  %conv1 = sext i4 %b to i32
  %add = add i32 %conv1, %conv
  %0 = icmp slt i32 %add, 7
  %spec.store.select = select i1 %0, i32 %add, i32 7
  %1 = icmp sgt i32 %spec.store.select, -8
  %spec.store.select10 = select i1 %1, i32 %spec.store.select, i32 -8
  %conv9 = trunc i32 %spec.store.select10 to i4
  ret i4 %conv9
}

define signext i4 @ssub_sat4(i4 signext %a, i4 signext %b) {
; CHECK-LABEL: @ssub_sat4(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i4 [[A:%.*]] to i32
; CHECK-NEXT:    [[CONV1:%.*]] = sext i4 [[B:%.*]] to i32
; CHECK-NEXT:    [[SUB:%.*]] = sub nsw i32 [[CONV]], [[CONV1]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i32 @llvm.smin.i32(i32 [[SUB]], i32 7)
; CHECK-NEXT:    [[SPEC_STORE_SELECT10:%.*]] = call i32 @llvm.smax.i32(i32 [[SPEC_STORE_SELECT]], i32 -8)
; CHECK-NEXT:    [[CONV9:%.*]] = trunc nsw i32 [[SPEC_STORE_SELECT10]] to i4
; CHECK-NEXT:    ret i4 [[CONV9]]
;
entry:
  %conv = sext i4 %a to i32
  %conv1 = sext i4 %b to i32
  %sub = sub i32 %conv, %conv1
  %0 = icmp slt i32 %sub, 7
  %spec.store.select = select i1 %0, i32 %sub, i32 7
  %1 = icmp sgt i32 %spec.store.select, -8
  %spec.store.select10 = select i1 %1, i32 %spec.store.select, i32 -8
  %conv9 = trunc i32 %spec.store.select10 to i4
  ret i4 %conv9
}

define <4 x i32> @sadd_satv4i32(<4 x i32> %a, <4 x i32> %b) {
; CHECK-LABEL: @sadd_satv4i32(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.sadd.sat.v4i32(<4 x i32> [[B:%.*]], <4 x i32> [[A:%.*]])
; CHECK-NEXT:    ret <4 x i32> [[TMP0]]
;
entry:
  %conv = sext <4 x i32> %a to <4 x i64>
  %conv1 = sext <4 x i32> %b to <4 x i64>
  %add = add <4 x i64> %conv1, %conv
  %0 = icmp slt <4 x i64> %add, <i64 2147483647, i64 2147483647, i64 2147483647, i64 2147483647>
  %spec.store.select = select <4 x i1> %0, <4 x i64> %add, <4 x i64> <i64 2147483647, i64 2147483647, i64 2147483647, i64 2147483647>
  %1 = icmp sgt <4 x i64> %spec.store.select, <i64 -2147483648, i64 -2147483648, i64 -2147483648, i64 -2147483648>
  %spec.store.select8 = select <4 x i1> %1, <4 x i64> %spec.store.select, <4 x i64> <i64 -2147483648, i64 -2147483648, i64 -2147483648, i64 -2147483648>
  %conv7 = trunc <4 x i64> %spec.store.select8 to <4 x i32>
  ret <4 x i32> %conv7
}

define <4 x i32> @sadd_satv4i32_mm(<4 x i32> %a, <4 x i32> %b) {
; CHECK-LABEL: @sadd_satv4i32_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.sadd.sat.v4i32(<4 x i32> [[B:%.*]], <4 x i32> [[A:%.*]])
; CHECK-NEXT:    ret <4 x i32> [[TMP0]]
;
entry:
  %conv = sext <4 x i32> %a to <4 x i64>
  %conv1 = sext <4 x i32> %b to <4 x i64>
  %add = add <4 x i64> %conv1, %conv
  %spec.store.select = call <4 x i64> @llvm.smin.v4i64(<4 x i64> %add, <4 x i64> <i64 2147483647, i64 2147483647, i64 2147483647, i64 2147483647>)
  %spec.store.select8 = call <4 x i64> @llvm.smax.v4i64(<4 x i64> %spec.store.select, <4 x i64> <i64 -2147483648, i64 -2147483648, i64 -2147483648, i64 -2147483648>)
  %conv7 = trunc <4 x i64> %spec.store.select8 to <4 x i32>
  ret <4 x i32> %conv7
}

define <4 x i32> @ssub_satv4i32(<4 x i32> %a, <4 x i32> %b) {
; CHECK-LABEL: @ssub_satv4i32(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.ssub.sat.v4i32(<4 x i32> [[B:%.*]], <4 x i32> [[A:%.*]])
; CHECK-NEXT:    ret <4 x i32> [[TMP0]]
;
entry:
  %conv = sext <4 x i32> %a to <4 x i64>
  %conv1 = sext <4 x i32> %b to <4 x i64>
  %add = sub <4 x i64> %conv1, %conv
  %0 = icmp slt <4 x i64> %add, <i64 2147483647, i64 2147483647, i64 2147483647, i64 2147483647>
  %spec.store.select = select <4 x i1> %0, <4 x i64> %add, <4 x i64> <i64 2147483647, i64 2147483647, i64 2147483647, i64 2147483647>
  %1 = icmp sgt <4 x i64> %spec.store.select, <i64 -2147483648, i64 -2147483648, i64 -2147483648, i64 -2147483648>
  %spec.store.select8 = select <4 x i1> %1, <4 x i64> %spec.store.select, <4 x i64> <i64 -2147483648, i64 -2147483648, i64 -2147483648, i64 -2147483648>
  %conv7 = trunc <4 x i64> %spec.store.select8 to <4 x i32>
  ret <4 x i32> %conv7
}

define <4 x i32> @ssub_satv4i32_mm(<4 x i32> %a, <4 x i32> %b) {
; CHECK-LABEL: @ssub_satv4i32_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.ssub.sat.v4i32(<4 x i32> [[B:%.*]], <4 x i32> [[A:%.*]])
; CHECK-NEXT:    ret <4 x i32> [[TMP0]]
;
entry:
  %conv = sext <4 x i32> %a to <4 x i64>
  %conv1 = sext <4 x i32> %b to <4 x i64>
  %add = sub <4 x i64> %conv1, %conv
  %spec.store.select = call <4 x i64> @llvm.smin.v4i64(<4 x i64> %add, <4 x i64> <i64 2147483647, i64 2147483647, i64 2147483647, i64 2147483647>)
  %spec.store.select8 = call <4 x i64> @llvm.smax.v4i64(<4 x i64> %spec.store.select, <4 x i64> <i64 -2147483648, i64 -2147483648, i64 -2147483648, i64 -2147483648>)
  %conv7 = trunc <4 x i64> %spec.store.select8 to <4 x i32>
  ret <4 x i32> %conv7
}

define <4 x i32> @sadd_satv4i4(<4 x i32> %a, <4 x i32> %b) {
; CHECK-LABEL: @sadd_satv4i4(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[ADD:%.*]] = add <4 x i32> [[A:%.*]], [[B:%.*]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call <4 x i32> @llvm.smin.v4i32(<4 x i32> [[ADD]], <4 x i32> <i32 15, i32 15, i32 15, i32 15>)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call <4 x i32> @llvm.smax.v4i32(<4 x i32> [[SPEC_STORE_SELECT]], <4 x i32> <i32 -16, i32 -16, i32 -16, i32 -16>)
; CHECK-NEXT:    ret <4 x i32> [[SPEC_STORE_SELECT8]]
;
entry:
  %add = add <4 x i32> %a, %b
  %0 = icmp slt <4 x i32> %add, <i32 15, i32 15, i32 15, i32 15>
  %spec.store.select = select <4 x i1> %0, <4 x i32> %add, <4 x i32> <i32 15, i32 15, i32 15, i32 15>
  %1 = icmp sgt <4 x i32> %spec.store.select, <i32 -16, i32 -16, i32 -16, i32 -16>
  %spec.store.select8 = select <4 x i1> %1, <4 x i32> %spec.store.select, <4 x i32> <i32 -16, i32 -16, i32 -16, i32 -16>
  ret <4 x i32> %spec.store.select8
}

define <4 x i32> @ssub_satv4i4(<4 x i32> %a, <4 x i32> %b) {
; CHECK-LABEL: @ssub_satv4i4(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[ADD:%.*]] = sub <4 x i32> [[A:%.*]], [[B:%.*]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call <4 x i32> @llvm.smin.v4i32(<4 x i32> [[ADD]], <4 x i32> <i32 15, i32 15, i32 15, i32 15>)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call <4 x i32> @llvm.smax.v4i32(<4 x i32> [[SPEC_STORE_SELECT]], <4 x i32> <i32 -16, i32 -16, i32 -16, i32 -16>)
; CHECK-NEXT:    ret <4 x i32> [[SPEC_STORE_SELECT8]]
;
entry:
  %add = sub <4 x i32> %a, %b
  %0 = icmp slt <4 x i32> %add, <i32 15, i32 15, i32 15, i32 15>
  %spec.store.select = select <4 x i1> %0, <4 x i32> %add, <4 x i32> <i32 15, i32 15, i32 15, i32 15>
  %1 = icmp sgt <4 x i32> %spec.store.select, <i32 -16, i32 -16, i32 -16, i32 -16>
  %spec.store.select8 = select <4 x i1> %1, <4 x i32> %spec.store.select, <4 x i32> <i32 -16, i32 -16, i32 -16, i32 -16>
  ret <4 x i32> %spec.store.select8
}


define i32 @sadd_sat32_extrause_1(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_extrause_1(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[B:%.*]], i32 [[A:%.*]])
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = sext i32 [[TMP0]] to i64
; CHECK-NEXT:    call void @use64(i64 [[SPEC_STORE_SELECT8]])
; CHECK-NEXT:    ret i32 [[TMP0]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp slt i64 %add, 2147483647
  %spec.store.select = select i1 %0, i64 %add, i64 2147483647
  %1 = icmp sgt i64 %spec.store.select, -2147483648
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -2147483648
  %conv7 = trunc i64 %spec.store.select8 to i32
  call void @use64(i64 %spec.store.select8)
  ret i32 %conv7
}

define i32 @sadd_sat32_extrause_2(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_extrause_2(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[A:%.*]] to i64
; CHECK-NEXT:    [[CONV1:%.*]] = sext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = add nsw i64 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.smin.i64(i64 [[ADD]], i64 2147483647)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i64 @llvm.smax.i64(i64 [[SPEC_STORE_SELECT]], i64 -2147483648)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i64 [[SPEC_STORE_SELECT8]] to i32
; CHECK-NEXT:    call void @use64(i64 [[SPEC_STORE_SELECT]])
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp slt i64 %add, 2147483647
  %spec.store.select = select i1 %0, i64 %add, i64 2147483647
  %1 = icmp sgt i64 %spec.store.select, -2147483648
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -2147483648
  %conv7 = trunc i64 %spec.store.select8 to i32
  call void @use64(i64 %spec.store.select)
  ret i32 %conv7
}

define i32 @sadd_sat32_extrause_2_mm(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_extrause_2_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[A:%.*]] to i64
; CHECK-NEXT:    [[CONV1:%.*]] = sext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = add nsw i64 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.smin.i64(i64 [[ADD]], i64 2147483647)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i64 @llvm.smax.i64(i64 [[SPEC_STORE_SELECT]], i64 -2147483648)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i64 [[SPEC_STORE_SELECT8]] to i32
; CHECK-NEXT:    call void @use64(i64 [[SPEC_STORE_SELECT]])
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %spec.store.select = call i64 @llvm.smin.i64(i64 %add, i64 2147483647)
  %spec.store.select8 = call i64 @llvm.smax.i64(i64 %spec.store.select, i64 -2147483648)
  %conv7 = trunc i64 %spec.store.select8 to i32
  call void @use64(i64 %spec.store.select)
  ret i32 %conv7
}

define i32 @sadd_sat32_extrause_3(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_extrause_3(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[A:%.*]] to i64
; CHECK-NEXT:    [[CONV1:%.*]] = sext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = add nsw i64 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.smin.i64(i64 [[ADD]], i64 2147483647)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i64 @llvm.smax.i64(i64 [[SPEC_STORE_SELECT]], i64 -2147483648)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i64 [[SPEC_STORE_SELECT8]] to i32
; CHECK-NEXT:    call void @use64(i64 [[ADD]])
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp slt i64 %add, 2147483647
  %spec.store.select = select i1 %0, i64 %add, i64 2147483647
  %1 = icmp sgt i64 %spec.store.select, -2147483648
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -2147483648
  %conv7 = trunc i64 %spec.store.select8 to i32
  call void @use64(i64 %add)
  ret i32 %conv7
}

define i32 @sadd_sat32_extrause_3_mm(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_extrause_3_mm(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[A:%.*]] to i64
; CHECK-NEXT:    [[CONV1:%.*]] = sext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = add nsw i64 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.smin.i64(i64 [[ADD]], i64 2147483647)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i64 @llvm.smax.i64(i64 [[SPEC_STORE_SELECT]], i64 -2147483648)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i64 [[SPEC_STORE_SELECT8]] to i32
; CHECK-NEXT:    call void @use64(i64 [[ADD]])
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %spec.store.select = call i64 @llvm.smin.i64(i64 %add, i64 2147483647)
  %spec.store.select8 = call i64 @llvm.smax.i64(i64 %spec.store.select, i64 -2147483648)
  %conv7 = trunc i64 %spec.store.select8 to i32
  call void @use64(i64 %add)
  ret i32 %conv7
}

define i32 @sadd_sat32_trunc(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_trunc(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[A:%.*]] to i64
; CHECK-NEXT:    [[CONV1:%.*]] = sext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = add nsw i64 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.smin.i64(i64 [[ADD]], i64 32767)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i64 @llvm.smax.i64(i64 [[SPEC_STORE_SELECT]], i64 -32768)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i64 [[SPEC_STORE_SELECT8]] to i32
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp slt i64 %add, 32767
  %spec.store.select = select i1 %0, i64 %add, i64 32767
  %1 = icmp sgt i64 %spec.store.select, -32768
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -32768
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @sadd_sat32_ext16(i32 %a, i16 %b) {
; CHECK-LABEL: @sadd_sat32_ext16(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = sext i16 [[B:%.*]] to i32
; CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[TMP0]], i32 [[A:%.*]])
; CHECK-NEXT:    ret i32 [[TMP1]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i16 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp slt i64 %add, 2147483647
  %spec.store.select = select i1 %0, i64 %add, i64 2147483647
  %1 = icmp sgt i64 %spec.store.select, -2147483648
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -2147483648
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i8 @sadd_sat8_ext8(i8 %a, i16 %b) {
; CHECK-LABEL: @sadd_sat8_ext8(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = sext i8 [[A:%.*]] to i32
; CHECK-NEXT:    [[CONV1:%.*]] = sext i16 [[B:%.*]] to i32
; CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i32 @llvm.smin.i32(i32 [[ADD]], i32 127)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i32 @llvm.smax.i32(i32 [[SPEC_STORE_SELECT]], i32 -128)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i32 [[SPEC_STORE_SELECT8]] to i8
; CHECK-NEXT:    ret i8 [[CONV7]]
;
entry:
  %conv = sext i8 %a to i32
  %conv1 = sext i16 %b to i32
  %add = add i32 %conv1, %conv
  %0 = icmp slt i32 %add, 127
  %spec.store.select = select i1 %0, i32 %add, i32 127
  %1 = icmp sgt i32 %spec.store.select, -128
  %spec.store.select8 = select i1 %1, i32 %spec.store.select, i32 -128
  %conv7 = trunc i32 %spec.store.select8 to i8
  ret i8 %conv7
}

define i32 @sadd_sat32_zext(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_zext(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = zext i32 [[A:%.*]] to i64
; CHECK-NEXT:    [[CONV1:%.*]] = zext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = add nuw nsw i64 [[CONV1]], [[CONV]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.umin.i64(i64 [[ADD]], i64 2147483647)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nuw nsw i64 [[SPEC_STORE_SELECT]] to i32
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = zext i32 %a to i64
  %conv1 = zext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp slt i64 %add, 2147483647
  %spec.store.select = select i1 %0, i64 %add, i64 2147483647
  %1 = icmp sgt i64 %spec.store.select, -2147483648
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 -2147483648
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @sadd_sat32_maxmin(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_maxmin(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[B:%.*]], i32 [[A:%.*]])
; CHECK-NEXT:    ret i32 [[TMP0]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp sgt i64 %add, -2147483648
  %spec.store.select = select i1 %0, i64 %add, i64 -2147483648
  %1 = icmp slt i64 %spec.store.select, 2147483647
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 2147483647
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i64 @sadd_sat32_notrunc(i32 %a, i32 %b) {
; CHECK-LABEL: @sadd_sat32_notrunc(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[B:%.*]], i32 [[A:%.*]])
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = sext i32 [[TMP0]] to i64
; CHECK-NEXT:    ret i64 [[SPEC_STORE_SELECT8]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp sgt i64 %add, -2147483648
  %spec.store.select = select i1 %0, i64 %add, i64 -2147483648
  %1 = icmp slt i64 %spec.store.select, 2147483647
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 2147483647
  ret i64 %spec.store.select8
}

define i32 @ashrA(i64 %a, i32 %b) {
; CHECK-LABEL: @ashrA(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = lshr i64 [[A:%.*]], 32
; CHECK-NEXT:    [[TMP1:%.*]] = trunc nuw i64 [[TMP0]] to i32
; CHECK-NEXT:    [[TMP2:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[TMP1]], i32 [[B:%.*]])
; CHECK-NEXT:    ret i32 [[TMP2]]
;
entry:
  %conv = ashr i64 %a, 32
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %spec.store.select = call i64 @llvm.smin.i64(i64 %add, i64 2147483647)
  %spec.store.select8 = call i64 @llvm.smax.i64(i64 %spec.store.select, i64 -2147483648)
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @ashrB(i32 %a, i64 %b) {
; CHECK-LABEL: @ashrB(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = lshr i64 [[B:%.*]], 32
; CHECK-NEXT:    [[TMP1:%.*]] = trunc nuw i64 [[TMP0]] to i32
; CHECK-NEXT:    [[TMP2:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[TMP1]], i32 [[A:%.*]])
; CHECK-NEXT:    ret i32 [[TMP2]]
;
entry:
  %conv = sext i32 %a to i64
  %conv1 = ashr i64 %b, 32
  %add = add i64 %conv1, %conv
  %0 = icmp sgt i64 %add, -2147483648
  %spec.store.select = select i1 %0, i64 %add, i64 -2147483648
  %1 = icmp slt i64 %spec.store.select, 2147483647
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 2147483647
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @ashrAB(i64 %a, i64 %b) {
; CHECK-LABEL: @ashrAB(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = lshr i64 [[A:%.*]], 32
; CHECK-NEXT:    [[TMP1:%.*]] = lshr i64 [[B:%.*]], 32
; CHECK-NEXT:    [[TMP2:%.*]] = trunc nuw i64 [[TMP1]] to i32
; CHECK-NEXT:    [[TMP3:%.*]] = trunc nuw i64 [[TMP0]] to i32
; CHECK-NEXT:    [[TMP4:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[TMP2]], i32 [[TMP3]])
; CHECK-NEXT:    ret i32 [[TMP4]]
;
entry:
  %conv = ashr i64 %a, 32
  %conv1 = ashr i64 %b, 32
  %add = add i64 %conv1, %conv
  %0 = icmp sgt i64 %add, -2147483648
  %spec.store.select = select i1 %0, i64 %add, i64 -2147483648
  %1 = icmp slt i64 %spec.store.select, 2147483647
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 2147483647
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @ashrA31(i64 %a, i32 %b) {
; CHECK-LABEL: @ashrA31(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = ashr i64 [[A:%.*]], 31
; CHECK-NEXT:    [[CONV1:%.*]] = sext i32 [[B:%.*]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = add nsw i64 [[CONV]], [[CONV1]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call i64 @llvm.smax.i64(i64 [[ADD]], i64 -2147483648)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call i64 @llvm.smin.i64(i64 [[SPEC_STORE_SELECT]], i64 2147483647)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw i64 [[SPEC_STORE_SELECT8]] to i32
; CHECK-NEXT:    ret i32 [[CONV7]]
;
entry:
  %conv = ashr i64 %a, 31
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp sgt i64 %add, -2147483648
  %spec.store.select = select i1 %0, i64 %add, i64 -2147483648
  %1 = icmp slt i64 %spec.store.select, 2147483647
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 2147483647
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define i32 @ashrA33(i64 %a, i32 %b) {
; CHECK-LABEL: @ashrA33(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = ashr i64 [[A:%.*]], 33
; CHECK-NEXT:    [[TMP0:%.*]] = trunc nsw i64 [[CONV]] to i32
; CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.sadd.sat.i32(i32 [[TMP0]], i32 [[B:%.*]])
; CHECK-NEXT:    ret i32 [[TMP1]]
;
entry:
  %conv = ashr i64 %a, 33
  %conv1 = sext i32 %b to i64
  %add = add i64 %conv1, %conv
  %0 = icmp sgt i64 %add, -2147483648
  %spec.store.select = select i1 %0, i64 %add, i64 -2147483648
  %1 = icmp slt i64 %spec.store.select, 2147483647
  %spec.store.select8 = select i1 %1, i64 %spec.store.select, i64 2147483647
  %conv7 = trunc i64 %spec.store.select8 to i32
  ret i32 %conv7
}

define <2 x i8> @ashrv2i8(<2 x i16> %a, <2 x i8> %b) {
; CHECK-LABEL: @ashrv2i8(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[CONV:%.*]] = ashr <2 x i16> [[A:%.*]], <i16 8, i16 12>
; CHECK-NEXT:    [[CONV1:%.*]] = sext <2 x i8> [[B:%.*]] to <2 x i16>
; CHECK-NEXT:    [[ADD:%.*]] = add <2 x i16> [[CONV]], [[CONV1]]
; CHECK-NEXT:    [[SPEC_STORE_SELECT:%.*]] = call <2 x i16> @llvm.smax.v2i16(<2 x i16> [[ADD]], <2 x i16> <i16 -128, i16 -128>)
; CHECK-NEXT:    [[SPEC_STORE_SELECT8:%.*]] = call <2 x i16> @llvm.smin.v2i16(<2 x i16> [[SPEC_STORE_SELECT]], <2 x i16> <i16 127, i16 127>)
; CHECK-NEXT:    [[CONV7:%.*]] = trunc nsw <2 x i16> [[SPEC_STORE_SELECT8]] to <2 x i8>
; CHECK-NEXT:    ret <2 x i8> [[CONV7]]
;
entry:
  %conv = ashr <2 x i16> %a, <i16 8, i16 12>
  %conv1 = sext <2 x i8> %b to <2 x i16>
  %add = add <2 x i16> %conv1, %conv
  %0 = icmp sgt <2 x i16> %add, <i16 -128, i16 -128>
  %spec.store.select = select <2 x i1> %0, <2 x i16> %add, <2 x i16> <i16 -128, i16 -128>
  %1 = icmp slt <2 x i16> %spec.store.select, <i16 127, i16 127>
  %spec.store.select8 = select <2 x i1> %1, <2 x i16> %spec.store.select, <2 x i16> <i16 127, i16 127>
  %conv7 = trunc <2 x i16> %spec.store.select8 to <2 x i8>
  ret <2 x i8> %conv7
}

define <2 x i8> @ashrv2i8_s(<2 x i16> %a, <2 x i8> %b) {
; CHECK-LABEL: @ashrv2i8_s(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = lshr <2 x i16> [[A:%.*]], <i16 8, i16 8>
; CHECK-NEXT:    [[TMP1:%.*]] = trunc nuw <2 x i16> [[TMP0]] to <2 x i8>
; CHECK-NEXT:    [[TMP2:%.*]] = call <2 x i8> @llvm.sadd.sat.v2i8(<2 x i8> [[TMP1]], <2 x i8> [[B:%.*]])
; CHECK-NEXT:    ret <2 x i8> [[TMP2]]
;
entry:
  %conv = ashr <2 x i16> %a, <i16 8, i16 8>
  %conv1 = sext <2 x i8> %b to <2 x i16>
  %add = add <2 x i16> %conv1, %conv
  %0 = icmp sgt <2 x i16> %add, <i16 -128, i16 -128>
  %spec.store.select = select <2 x i1> %0, <2 x i16> %add, <2 x i16> <i16 -128, i16 -128>
  %1 = icmp slt <2 x i16> %spec.store.select, <i16 127, i16 127>
  %spec.store.select8 = select <2 x i1> %1, <2 x i16> %spec.store.select, <2 x i16> <i16 127, i16 127>
  %conv7 = trunc <2 x i16> %spec.store.select8 to <2 x i8>
  ret <2 x i8> %conv7
}

define i16 @or(i8 %X, i16 %Y) {
; CHECK-LABEL: @or(
; CHECK-NEXT:    [[TMP1:%.*]] = trunc i16 [[Y:%.*]] to i8
; CHECK-NEXT:    [[TMP2:%.*]] = or i8 [[TMP1]], -16
; CHECK-NEXT:    [[TMP3:%.*]] = call i8 @llvm.ssub.sat.i8(i8 [[X:%.*]], i8 [[TMP2]])
; CHECK-NEXT:    [[L12:%.*]] = sext i8 [[TMP3]] to i16
; CHECK-NEXT:    ret i16 [[L12]]
;
  %conv10 = sext i8 %X to i16
  %conv14 = or i16 %Y, 65520
  %sub = sub nsw i16 %conv10, %conv14
  %l9 = icmp sgt i16 %sub, -128
  %l10 = select i1 %l9, i16 %sub, i16 -128
  %l11 = icmp slt i16 %l10, 127
  %l12 = select i1 %l11, i16 %l10, i16 127
  ret i16 %l12
}

define i16 @const(i8 %X) {
; CHECK-LABEL: @const(
; CHECK-NEXT:    [[TMP1:%.*]] = call i8 @llvm.smin.i8(i8 [[X:%.*]], i8 117)
; CHECK-NEXT:    [[NARROW:%.*]] = add nsw i8 [[TMP1]], 10
; CHECK-NEXT:    [[L12:%.*]] = sext i8 [[NARROW]] to i16
; CHECK-NEXT:    ret i16 [[L12]]
;
  %conv10 = sext i8 %X to i16
  %sub = add i16 %conv10, 10
  %l9 = icmp sgt i16 %sub, -128
  %l10 = select i1 %l9, i16 %sub, i16 -128
  %l11 = icmp slt i16 %l10, 127
  %l12 = select i1 %l11, i16 %l10, i16 127
  ret i16 %l12
}

declare void @use64(i64)
declare i64 @llvm.smin.i64(i64, i64)
declare i64 @llvm.smax.i64(i64, i64)
declare i32 @llvm.smin.i32(i32, i32)
declare i32 @llvm.smax.i32(i32, i32)
declare <4 x i64> @llvm.smin.v4i64(<4 x i64>, <4 x i64>)
declare <4 x i64> @llvm.smax.v4i64(<4 x i64>, <4 x i64>)