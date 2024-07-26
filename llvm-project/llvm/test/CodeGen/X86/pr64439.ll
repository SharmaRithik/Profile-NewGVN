; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py UTC_ARGS: --version 2
; RUN: llc < %s -mtriple=x86_64-- -mcpu=x86-64-v4 | FileCheck %s

define void @f(ptr %0, <32 x i1> %1, i32 %2) nounwind {
; CHECK-LABEL: f:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vpsllw $7, %ymm0, %ymm1
; CHECK-NEXT:    vpmovb2m %ymm1, %k0
; CHECK-NEXT:    vpextrb $3, %xmm0, %eax
; CHECK-NEXT:    vpbroadcastb %esi, %ymm0
; CHECK-NEXT:    vpcmpeqb {{\.?LCPI[0-9]+_[0-9]+}}(%rip), %ymm0, %k1
; CHECK-NEXT:    vpmovm2b %k0, %ymm0
; CHECK-NEXT:    vpbroadcastb %eax, %ymm0 {%k1}
; CHECK-NEXT:    vpsllw $7, %ymm0, %ymm0
; CHECK-NEXT:    vpmovb2m %ymm0, %k0
; CHECK-NEXT:    kmovd %k0, (%rdi)
; CHECK-NEXT:    vzeroupper
; CHECK-NEXT:    retq
  %E = extractelement <32 x i1> %1, i32 3
  %I = insertelement <32 x i1> %1, i1 %E, i32 %2
  store <32 x i1> %I, ptr %0
  ret void
}