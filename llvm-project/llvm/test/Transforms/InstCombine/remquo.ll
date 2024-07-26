; NOTE: Assertions have been autogenerated by utils/update_test_checks.py UTC_ARGS: --version 5
; RUN: opt < %s -passes=instcombine -S | FileCheck %s

define float @remquo_f32(ptr %quo) {
; CHECK-LABEL: define float @remquo_f32(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    store i32 -2, ptr [[QUO]], align 4
; CHECK-NEXT:    ret float 1.000000e+00
;
entry:
  %call = call float @remquof(float -5.000000e+00, float 3.000000e+00, ptr %quo)
  ret float %call
}

define float @remquo_f32_quo_sign(ptr %quo) {
; CHECK-LABEL: define float @remquo_f32_quo_sign(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    store i32 2, ptr [[QUO]], align 4
; CHECK-NEXT:    ret float -1.000000e+00
;
entry:
  %call = call float @remquof(float 5.000000e+00, float 3.000000e+00, ptr %quo)
  ret float %call
}

define float @remquo_f32_round(ptr %quo) {
; CHECK-LABEL: define float @remquo_f32_round(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    store i32 -6, ptr [[QUO]], align 4
; CHECK-NEXT:    ret float 0xBFC9999900000000
;
entry:
  %call = call float @remquof(float -5.000000e+00, float 0x3FE99999A0000000, ptr %quo)
  ret float %call
}

define double @remquo_f64(ptr %quo) {
; CHECK-LABEL: define double @remquo_f64(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    store i32 -5, ptr [[QUO]], align 4
; CHECK-NEXT:    ret double -0.000000e+00
;
entry:
  %call = call double @remquo(double -5.000000e+00, double 1.000000e+00, ptr %quo)
  ret double %call
}

; Negative tests

define float @remquo_f32_inf_x(ptr %quo) {
; CHECK-LABEL: define float @remquo_f32_inf_x(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    [[CALL:%.*]] = call float @remquof(float 0x7FF0000000000000, float 1.000000e+00, ptr [[QUO]])
; CHECK-NEXT:    ret float [[CALL]]
;
entry:
  %call = call float @remquof(float 0x7FF0000000000000, float 1.000000e+00, ptr %quo)
  ret float %call
}

define float @remquo_f32_zero_y(ptr %quo) {
; CHECK-LABEL: define float @remquo_f32_zero_y(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    [[CALL:%.*]] = call float @remquof(float -5.000000e+00, float 0.000000e+00, ptr [[QUO]])
; CHECK-NEXT:    ret float [[CALL]]
;
entry:
  %call = call float @remquof(float -5.000000e+00, float 0.000000e+00, ptr %quo)
  ret float %call
}

define float @remquo_f32_nzero_y(ptr %quo) {
; CHECK-LABEL: define float @remquo_f32_nzero_y(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    [[CALL:%.*]] = call float @remquof(float -5.000000e+00, float -0.000000e+00, ptr [[QUO]])
; CHECK-NEXT:    ret float [[CALL]]
;
entry:
  %call = call float @remquof(float -5.000000e+00, float -0.000000e+00, ptr %quo)
  ret float %call
}

define float @remquo_f32_nan_x(ptr %quo) {
; CHECK-LABEL: define float @remquo_f32_nan_x(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    [[CALL:%.*]] = call float @remquof(float 0x7FF8000000000000, float 1.000000e+00, ptr [[QUO]])
; CHECK-NEXT:    ret float [[CALL]]
;
entry:
  %call = call float @remquof(float 0x7FF8000000000000, float 1.000000e+00, ptr %quo)
  ret float %call
}

define float @remquo_f32_nan_y(ptr %quo) {
; CHECK-LABEL: define float @remquo_f32_nan_y(
; CHECK-SAME: ptr [[QUO:%.*]]) {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    [[CALL:%.*]] = call float @remquof(float 1.000000e+00, float 0x7FF8000000000000, ptr [[QUO]])
; CHECK-NEXT:    ret float [[CALL]]
;
entry:
  %call = call float @remquof(float 1.000000e+00, float 0x7FF8000000000000, ptr %quo)
  ret float %call
}

define float @remquo_f32_strictfp(ptr %quo) strictfp {
; CHECK-LABEL: define float @remquo_f32_strictfp(
; CHECK-SAME: ptr [[QUO:%.*]]) #[[ATTR0:[0-9]+]] {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    [[CALL:%.*]] = call float @remquof(float -5.000000e+00, float 3.000000e+00, ptr [[QUO]]) #[[ATTR0]]
; CHECK-NEXT:    ret float [[CALL]]
;
entry:
  %call = call float @remquof(float -5.000000e+00, float 3.000000e+00, ptr %quo) strictfp
  ret float %call
}

define float @remquo_f32_zero_y_strictfp(ptr %quo) strictfp {
; CHECK-LABEL: define float @remquo_f32_zero_y_strictfp(
; CHECK-SAME: ptr [[QUO:%.*]]) #[[ATTR0]] {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    [[CALL:%.*]] = call float @remquof(float -5.000000e+00, float 0.000000e+00, ptr [[QUO]]) #[[ATTR0]]
; CHECK-NEXT:    ret float [[CALL]]
;
entry:
  %call = call float @remquof(float -5.000000e+00, float 0.000000e+00, ptr %quo) strictfp
  ret float %call
}

declare float @remquof(float, float, ptr)
declare double @remquo(double, double, ptr)