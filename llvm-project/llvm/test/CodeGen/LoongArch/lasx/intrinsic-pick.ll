; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc --mtriple=loongarch64 --mattr=+lasx < %s | FileCheck %s

declare <32 x i8> @llvm.loongarch.lasx.xvpickev.b(<32 x i8>, <32 x i8>)

define <32 x i8> @lasx_xvpickev_b(<32 x i8> %va, <32 x i8> %vb) nounwind {
; CHECK-LABEL: lasx_xvpickev_b:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    xvpickev.b $xr0, $xr0, $xr1
; CHECK-NEXT:    ret
entry:
  %res = call <32 x i8> @llvm.loongarch.lasx.xvpickev.b(<32 x i8> %va, <32 x i8> %vb)
  ret <32 x i8> %res
}

declare <16 x i16> @llvm.loongarch.lasx.xvpickev.h(<16 x i16>, <16 x i16>)

define <16 x i16> @lasx_xvpickev_h(<16 x i16> %va, <16 x i16> %vb) nounwind {
; CHECK-LABEL: lasx_xvpickev_h:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    xvpickev.h $xr0, $xr0, $xr1
; CHECK-NEXT:    ret
entry:
  %res = call <16 x i16> @llvm.loongarch.lasx.xvpickev.h(<16 x i16> %va, <16 x i16> %vb)
  ret <16 x i16> %res
}

declare <8 x i32> @llvm.loongarch.lasx.xvpickev.w(<8 x i32>, <8 x i32>)

define <8 x i32> @lasx_xvpickev_w(<8 x i32> %va, <8 x i32> %vb) nounwind {
; CHECK-LABEL: lasx_xvpickev_w:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    xvpickev.w $xr0, $xr0, $xr1
; CHECK-NEXT:    ret
entry:
  %res = call <8 x i32> @llvm.loongarch.lasx.xvpickev.w(<8 x i32> %va, <8 x i32> %vb)
  ret <8 x i32> %res
}

declare <4 x i64> @llvm.loongarch.lasx.xvpickev.d(<4 x i64>, <4 x i64>)

define <4 x i64> @lasx_xvpickev_d(<4 x i64> %va, <4 x i64> %vb) nounwind {
; CHECK-LABEL: lasx_xvpickev_d:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    xvpickev.d $xr0, $xr0, $xr1
; CHECK-NEXT:    ret
entry:
  %res = call <4 x i64> @llvm.loongarch.lasx.xvpickev.d(<4 x i64> %va, <4 x i64> %vb)
  ret <4 x i64> %res
}

declare <32 x i8> @llvm.loongarch.lasx.xvpickod.b(<32 x i8>, <32 x i8>)

define <32 x i8> @lasx_xvpickod_b(<32 x i8> %va, <32 x i8> %vb) nounwind {
; CHECK-LABEL: lasx_xvpickod_b:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    xvpickod.b $xr0, $xr0, $xr1
; CHECK-NEXT:    ret
entry:
  %res = call <32 x i8> @llvm.loongarch.lasx.xvpickod.b(<32 x i8> %va, <32 x i8> %vb)
  ret <32 x i8> %res
}

declare <16 x i16> @llvm.loongarch.lasx.xvpickod.h(<16 x i16>, <16 x i16>)

define <16 x i16> @lasx_xvpickod_h(<16 x i16> %va, <16 x i16> %vb) nounwind {
; CHECK-LABEL: lasx_xvpickod_h:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    xvpickod.h $xr0, $xr0, $xr1
; CHECK-NEXT:    ret
entry:
  %res = call <16 x i16> @llvm.loongarch.lasx.xvpickod.h(<16 x i16> %va, <16 x i16> %vb)
  ret <16 x i16> %res
}

declare <8 x i32> @llvm.loongarch.lasx.xvpickod.w(<8 x i32>, <8 x i32>)

define <8 x i32> @lasx_xvpickod_w(<8 x i32> %va, <8 x i32> %vb) nounwind {
; CHECK-LABEL: lasx_xvpickod_w:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    xvpickod.w $xr0, $xr0, $xr1
; CHECK-NEXT:    ret
entry:
  %res = call <8 x i32> @llvm.loongarch.lasx.xvpickod.w(<8 x i32> %va, <8 x i32> %vb)
  ret <8 x i32> %res
}

declare <4 x i64> @llvm.loongarch.lasx.xvpickod.d(<4 x i64>, <4 x i64>)

define <4 x i64> @lasx_xvpickod_d(<4 x i64> %va, <4 x i64> %vb) nounwind {
; CHECK-LABEL: lasx_xvpickod_d:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    xvpickod.d $xr0, $xr0, $xr1
; CHECK-NEXT:    ret
entry:
  %res = call <4 x i64> @llvm.loongarch.lasx.xvpickod.d(<4 x i64> %va, <4 x i64> %vb)
  ret <4 x i64> %res
}