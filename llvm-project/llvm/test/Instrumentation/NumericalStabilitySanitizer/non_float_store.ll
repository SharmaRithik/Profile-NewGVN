; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt -passes=nsan -nsan-shadow-type-mapping=dqq -nsan-propagate-non-ft-const-stores-as-ft -S %s | FileCheck %s

target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"

define void @store_non_float(ptr %dst) sanitize_numerical_stability {
; CHECK-LABEL: @store_non_float(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    store i32 42, ptr [[DST:%.*]], align 1
; CHECK-NEXT:    [[TMP0:%.*]] = call ptr @__nsan_get_shadow_ptr_for_float_store(ptr [[DST]], i64 1)
; CHECK-NEXT:    store double 0x36F5000000000000, ptr [[TMP0]], align 1
; CHECK-NEXT:    ret void
;
entry:
  store i32 42, ptr %dst, align 1
  ret void
}

attributes #0 = { nounwind readonly uwtable sanitize_numerical_stability "correctly-rounded-divide-sqrt-fp-math"="false" "denormal-fp-math"="preserve-sign,preserve-sign" "denormal-fp-math-f32"="ieee,ieee" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="true" "no-jump-tables"="false" "no-nans-fp-math"="true" "no-signed-zeros-fp-math"="true" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="true" "use-soft-float"="false" }