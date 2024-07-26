; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -mtriple=aarch64 -mattr=+sve | FileCheck %s

; Float

declare <vscale x 2 x i32> @llvm.fptoui.sat.nxv2f32.nxv2i32(<vscale x 2 x float>)
declare <vscale x 4 x i32> @llvm.fptoui.sat.nxv4f32.nxv4i32(<vscale x 4 x float>)
declare <vscale x 8 x i32> @llvm.fptoui.sat.nxv8f32.nxv8i32(<vscale x 8 x float>)
declare <vscale x 4 x i16> @llvm.fptoui.sat.nxv4f32.nxv4i16(<vscale x 4 x float>)
declare <vscale x 8 x i16> @llvm.fptoui.sat.nxv8f32.nxv8i16(<vscale x 8 x float>)
declare <vscale x 2 x i64> @llvm.fptoui.sat.nxv2f32.nxv2i64(<vscale x 2 x float>)
declare <vscale x 4 x i64> @llvm.fptoui.sat.nxv4f32.nxv4i64(<vscale x 4 x float>)

define <vscale x 2 x i32> @test_signed_v2f32_v2i32(<vscale x 2 x float> %f) {
; CHECK-LABEL: test_signed_v2f32_v2i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov w8, #1333788671 // =0x4f7fffff
; CHECK-NEXT:    mov z1.s, w8
; CHECK-NEXT:    fcmge p1.s, p0/z, z0.s, #0.0
; CHECK-NEXT:    movprfx z2, z0
; CHECK-NEXT:    fcvtzu z2.d, p0/m, z0.s
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.s, p0/z, z0.s, z1.s
; CHECK-NEXT:    mov z0.d, #0xffffffff
; CHECK-NEXT:    mov z2.d, p1/m, #0 // =0x0
; CHECK-NEXT:    sel z0.d, p0, z0.d, z2.d
; CHECK-NEXT:    ret
    %x = call <vscale x 2 x i32> @llvm.fptoui.sat.nxv2f32.nxv2i32(<vscale x 2 x float> %f)
    ret <vscale x 2 x i32> %x
}

define <vscale x 4 x i32> @test_signed_v4f32_v4i32(<vscale x 4 x float> %f) {
; CHECK-LABEL: test_signed_v4f32_v4i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.s
; CHECK-NEXT:    mov w8, #1333788671 // =0x4f7fffff
; CHECK-NEXT:    mov z2.s, w8
; CHECK-NEXT:    fcmge p1.s, p0/z, z0.s, #0.0
; CHECK-NEXT:    movprfx z1, z0
; CHECK-NEXT:    fcvtzu z1.s, p0/m, z0.s
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.s, p0/z, z0.s, z2.s
; CHECK-NEXT:    mov z1.s, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.s, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z0.d, z1.d
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i32> @llvm.fptoui.sat.nxv4f32.nxv4i32(<vscale x 4 x float> %f)
    ret <vscale x 4 x i32> %x
}

define <vscale x 8 x i32> @test_signed_v8f32_v8i32(<vscale x 8 x float> %f) {
; CHECK-LABEL: test_signed_v8f32_v8i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.s
; CHECK-NEXT:    mov w8, #1333788671 // =0x4f7fffff
; CHECK-NEXT:    mov z4.s, w8
; CHECK-NEXT:    fcmge p1.s, p0/z, z0.s, #0.0
; CHECK-NEXT:    fcmge p2.s, p0/z, z1.s, #0.0
; CHECK-NEXT:    movprfx z2, z0
; CHECK-NEXT:    fcvtzu z2.s, p0/m, z0.s
; CHECK-NEXT:    movprfx z3, z1
; CHECK-NEXT:    fcvtzu z3.s, p0/m, z1.s
; CHECK-NEXT:    fcmgt p3.s, p0/z, z0.s, z4.s
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    fcmgt p0.s, p0/z, z1.s, z4.s
; CHECK-NEXT:    mov z2.s, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z3.s, p2/m, #0 // =0x0
; CHECK-NEXT:    mov z2.s, p3/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z3.s, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z0.d, z2.d
; CHECK-NEXT:    mov z1.d, z3.d
; CHECK-NEXT:    ret
    %x = call <vscale x 8 x i32> @llvm.fptoui.sat.nxv8f32.nxv8i32(<vscale x 8 x float> %f)
    ret <vscale x 8 x i32> %x
}

define <vscale x 4 x i16> @test_signed_v4f32_v4i16(<vscale x 4 x float> %f) {
; CHECK-LABEL: test_signed_v4f32_v4i16:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.s
; CHECK-NEXT:    mov w8, #65280 // =0xff00
; CHECK-NEXT:    movk w8, #18303, lsl #16
; CHECK-NEXT:    fcmge p1.s, p0/z, z0.s, #0.0
; CHECK-NEXT:    mov z1.s, w8
; CHECK-NEXT:    movprfx z2, z0
; CHECK-NEXT:    fcvtzu z2.s, p0/m, z0.s
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.s, p0/z, z0.s, z1.s
; CHECK-NEXT:    mov z0.s, #65535 // =0xffff
; CHECK-NEXT:    mov z2.s, p1/m, #0 // =0x0
; CHECK-NEXT:    sel z0.s, p0, z0.s, z2.s
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i16> @llvm.fptoui.sat.nxv4f32.nxv4i16(<vscale x 4 x float> %f)
    ret <vscale x 4 x i16> %x
}

define <vscale x 8 x i16> @test_signed_v8f32_v8i16(<vscale x 8 x float> %f) {
; CHECK-LABEL: test_signed_v8f32_v8i16:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.s
; CHECK-NEXT:    mov w8, #65280 // =0xff00
; CHECK-NEXT:    movk w8, #18303, lsl #16
; CHECK-NEXT:    fcmge p1.s, p0/z, z1.s, #0.0
; CHECK-NEXT:    fcmge p2.s, p0/z, z0.s, #0.0
; CHECK-NEXT:    mov z2.s, w8
; CHECK-NEXT:    movprfx z3, z1
; CHECK-NEXT:    fcvtzu z3.s, p0/m, z1.s
; CHECK-NEXT:    movprfx z4, z0
; CHECK-NEXT:    fcvtzu z4.s, p0/m, z0.s
; CHECK-NEXT:    fcmgt p3.s, p0/z, z1.s, z2.s
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    fcmgt p0.s, p0/z, z0.s, z2.s
; CHECK-NEXT:    mov z0.s, #65535 // =0xffff
; CHECK-NEXT:    mov z3.s, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z4.s, p2/m, #0 // =0x0
; CHECK-NEXT:    sel z1.s, p3, z0.s, z3.s
; CHECK-NEXT:    sel z0.s, p0, z0.s, z4.s
; CHECK-NEXT:    uzp1 z0.h, z0.h, z1.h
; CHECK-NEXT:    ret
    %x = call <vscale x 8 x i16> @llvm.fptoui.sat.nxv8f32.nxv8i16(<vscale x 8 x float> %f)
    ret <vscale x 8 x i16> %x
}

define <vscale x 2 x i64> @test_signed_v2f32_v2i64(<vscale x 2 x float> %f) {
; CHECK-LABEL: test_signed_v2f32_v2i64:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov w8, #1602224127 // =0x5f7fffff
; CHECK-NEXT:    mov z2.s, w8
; CHECK-NEXT:    fcmge p1.s, p0/z, z0.s, #0.0
; CHECK-NEXT:    movprfx z1, z0
; CHECK-NEXT:    fcvtzu z1.d, p0/m, z0.s
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.s, p0/z, z0.s, z2.s
; CHECK-NEXT:    mov z1.d, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.d, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z0.d, z1.d
; CHECK-NEXT:    ret
    %x = call <vscale x 2 x i64> @llvm.fptoui.sat.nxv2f32.nxv2i64(<vscale x 2 x float> %f)
    ret <vscale x 2 x i64> %x
}

define <vscale x 4 x i64> @test_signed_v4f32_v4i64(<vscale x 4 x float> %f) {
; CHECK-LABEL: test_signed_v4f32_v4i64:
; CHECK:       // %bb.0:
; CHECK-NEXT:    uunpklo z2.d, z0.s
; CHECK-NEXT:    uunpkhi z3.d, z0.s
; CHECK-NEXT:    mov w8, #1602224127 // =0x5f7fffff
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov z4.s, w8
; CHECK-NEXT:    fcmge p1.s, p0/z, z2.s, #0.0
; CHECK-NEXT:    fcmge p2.s, p0/z, z3.s, #0.0
; CHECK-NEXT:    movprfx z0, z2
; CHECK-NEXT:    fcvtzu z0.d, p0/m, z2.s
; CHECK-NEXT:    movprfx z1, z3
; CHECK-NEXT:    fcvtzu z1.d, p0/m, z3.s
; CHECK-NEXT:    fcmgt p3.s, p0/z, z2.s, z4.s
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    fcmgt p0.s, p0/z, z3.s, z4.s
; CHECK-NEXT:    mov z0.d, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.d, p2/m, #0 // =0x0
; CHECK-NEXT:    mov z0.d, p3/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z1.d, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i64> @llvm.fptoui.sat.nxv4f32.nxv4i64(<vscale x 4 x float> %f)
    ret <vscale x 4 x i64> %x
}

; Double

declare <vscale x 2 x i32> @llvm.fptoui.sat.nxv2f64.nxv2i32(<vscale x 2 x double>)
declare <vscale x 4 x i32> @llvm.fptoui.sat.nxv4f64.nxv4i32(<vscale x 4 x double>)
declare <vscale x 8 x i32> @llvm.fptoui.sat.nxv8f64.nxv8i32(<vscale x 8 x double>)
declare <vscale x 4 x i16> @llvm.fptoui.sat.nxv4f64.nxv4i16(<vscale x 4 x double>)
declare <vscale x 8 x i16> @llvm.fptoui.sat.nxv8f64.nxv8i16(<vscale x 8 x double>)
declare <vscale x 2 x i64> @llvm.fptoui.sat.nxv2f64.nxv2i64(<vscale x 2 x double>)
declare <vscale x 4 x i64> @llvm.fptoui.sat.nxv4f64.nxv4i64(<vscale x 4 x double>)

define <vscale x 2 x i32> @test_signed_v2f64_v2i32(<vscale x 2 x double> %f) {
; CHECK-LABEL: test_signed_v2f64_v2i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov x8, #281474974613504 // =0xffffffe00000
; CHECK-NEXT:    movk x8, #16879, lsl #48
; CHECK-NEXT:    fcmge p1.d, p0/z, z0.d, #0.0
; CHECK-NEXT:    mov z1.d, x8
; CHECK-NEXT:    movprfx z2, z0
; CHECK-NEXT:    fcvtzu z2.d, p0/m, z0.d
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.d, p0/z, z0.d, z1.d
; CHECK-NEXT:    mov z0.d, #0xffffffff
; CHECK-NEXT:    mov z2.d, p1/m, #0 // =0x0
; CHECK-NEXT:    sel z0.d, p0, z0.d, z2.d
; CHECK-NEXT:    ret
    %x = call <vscale x 2 x i32> @llvm.fptoui.sat.nxv2f64.nxv2i32(<vscale x 2 x double> %f)
    ret <vscale x 2 x i32> %x
}

define <vscale x 4 x i32> @test_signed_v4f64_v4i32(<vscale x 4 x double> %f) {
; CHECK-LABEL: test_signed_v4f64_v4i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov x8, #281474974613504 // =0xffffffe00000
; CHECK-NEXT:    movk x8, #16879, lsl #48
; CHECK-NEXT:    fcmge p1.d, p0/z, z1.d, #0.0
; CHECK-NEXT:    fcmge p2.d, p0/z, z0.d, #0.0
; CHECK-NEXT:    mov z2.d, x8
; CHECK-NEXT:    movprfx z3, z1
; CHECK-NEXT:    fcvtzu z3.d, p0/m, z1.d
; CHECK-NEXT:    movprfx z4, z0
; CHECK-NEXT:    fcvtzu z4.d, p0/m, z0.d
; CHECK-NEXT:    fcmgt p3.d, p0/z, z1.d, z2.d
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    fcmgt p0.d, p0/z, z0.d, z2.d
; CHECK-NEXT:    mov z0.d, #0xffffffff
; CHECK-NEXT:    mov z3.d, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z4.d, p2/m, #0 // =0x0
; CHECK-NEXT:    sel z1.d, p3, z0.d, z3.d
; CHECK-NEXT:    sel z0.d, p0, z0.d, z4.d
; CHECK-NEXT:    uzp1 z0.s, z0.s, z1.s
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i32> @llvm.fptoui.sat.nxv4f64.nxv4i32(<vscale x 4 x double> %f)
    ret <vscale x 4 x i32> %x
}

define <vscale x 8 x i32> @test_signed_v8f64_v8i32(<vscale x 8 x double> %f) {
; CHECK-LABEL: test_signed_v8f64_v8i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    str x29, [sp, #-16]! // 8-byte Folded Spill
; CHECK-NEXT:    addvl sp, sp, #-1
; CHECK-NEXT:    str p6, [sp, #5, mul vl] // 2-byte Folded Spill
; CHECK-NEXT:    str p5, [sp, #6, mul vl] // 2-byte Folded Spill
; CHECK-NEXT:    str p4, [sp, #7, mul vl] // 2-byte Folded Spill
; CHECK-NEXT:    .cfi_escape 0x0f, 0x0c, 0x8f, 0x00, 0x11, 0x10, 0x22, 0x11, 0x08, 0x92, 0x2e, 0x00, 0x1e, 0x22 // sp + 16 + 8 * VG
; CHECK-NEXT:    .cfi_offset w29, -16
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov x8, #281474974613504 // =0xffffffe00000
; CHECK-NEXT:    movk x8, #16879, lsl #48
; CHECK-NEXT:    fcmge p1.d, p0/z, z1.d, #0.0
; CHECK-NEXT:    fcmge p2.d, p0/z, z0.d, #0.0
; CHECK-NEXT:    fcmge p3.d, p0/z, z3.d, #0.0
; CHECK-NEXT:    fcmge p4.d, p0/z, z2.d, #0.0
; CHECK-NEXT:    movprfx z5, z1
; CHECK-NEXT:    fcvtzu z5.d, p0/m, z1.d
; CHECK-NEXT:    mov z4.d, x8
; CHECK-NEXT:    movprfx z6, z0
; CHECK-NEXT:    fcvtzu z6.d, p0/m, z0.d
; CHECK-NEXT:    movprfx z7, z3
; CHECK-NEXT:    fcvtzu z7.d, p0/m, z3.d
; CHECK-NEXT:    movprfx z24, z2
; CHECK-NEXT:    fcvtzu z24.d, p0/m, z2.d
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p5.d, p0/z, z1.d, z4.d
; CHECK-NEXT:    fcmgt p6.d, p0/z, z0.d, z4.d
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    mov z0.d, #0xffffffff
; CHECK-NEXT:    not p3.b, p0/z, p3.b
; CHECK-NEXT:    mov z5.d, p1/m, #0 // =0x0
; CHECK-NEXT:    fcmgt p1.d, p0/z, z3.d, z4.d
; CHECK-NEXT:    not p4.b, p0/z, p4.b
; CHECK-NEXT:    fcmgt p0.d, p0/z, z2.d, z4.d
; CHECK-NEXT:    mov z6.d, p2/m, #0 // =0x0
; CHECK-NEXT:    mov z7.d, p3/m, #0 // =0x0
; CHECK-NEXT:    mov z24.d, p4/m, #0 // =0x0
; CHECK-NEXT:    sel z1.d, p5, z0.d, z5.d
; CHECK-NEXT:    ldr p5, [sp, #6, mul vl] // 2-byte Folded Reload
; CHECK-NEXT:    sel z2.d, p6, z0.d, z6.d
; CHECK-NEXT:    ldr p6, [sp, #5, mul vl] // 2-byte Folded Reload
; CHECK-NEXT:    sel z3.d, p1, z0.d, z7.d
; CHECK-NEXT:    ldr p4, [sp, #7, mul vl] // 2-byte Folded Reload
; CHECK-NEXT:    sel z4.d, p0, z0.d, z24.d
; CHECK-NEXT:    uzp1 z0.s, z2.s, z1.s
; CHECK-NEXT:    uzp1 z1.s, z4.s, z3.s
; CHECK-NEXT:    addvl sp, sp, #1
; CHECK-NEXT:    ldr x29, [sp], #16 // 8-byte Folded Reload
; CHECK-NEXT:    ret
    %x = call <vscale x 8 x i32> @llvm.fptoui.sat.nxv8f64.nxv8i32(<vscale x 8 x double> %f)
    ret <vscale x 8 x i32> %x
}

define <vscale x 4 x i16> @test_signed_v4f64_v4i16(<vscale x 4 x double> %f) {
; CHECK-LABEL: test_signed_v4f64_v4i16:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov x8, #281337537757184 // =0xffe000000000
; CHECK-NEXT:    movk x8, #16623, lsl #48
; CHECK-NEXT:    fcmge p1.d, p0/z, z1.d, #0.0
; CHECK-NEXT:    fcmge p2.d, p0/z, z0.d, #0.0
; CHECK-NEXT:    mov z2.d, x8
; CHECK-NEXT:    movprfx z3, z1
; CHECK-NEXT:    fcvtzu z3.d, p0/m, z1.d
; CHECK-NEXT:    movprfx z4, z0
; CHECK-NEXT:    fcvtzu z4.d, p0/m, z0.d
; CHECK-NEXT:    fcmgt p3.d, p0/z, z1.d, z2.d
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    fcmgt p0.d, p0/z, z0.d, z2.d
; CHECK-NEXT:    mov z0.d, #65535 // =0xffff
; CHECK-NEXT:    mov z3.d, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z4.d, p2/m, #0 // =0x0
; CHECK-NEXT:    sel z1.d, p3, z0.d, z3.d
; CHECK-NEXT:    sel z0.d, p0, z0.d, z4.d
; CHECK-NEXT:    uzp1 z0.s, z0.s, z1.s
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i16> @llvm.fptoui.sat.nxv4f64.nxv4i16(<vscale x 4 x double> %f)
    ret <vscale x 4 x i16> %x
}

define <vscale x 8 x i16> @test_signed_v8f64_v8i16(<vscale x 8 x double> %f) {
; CHECK-LABEL: test_signed_v8f64_v8i16:
; CHECK:       // %bb.0:
; CHECK-NEXT:    str x29, [sp, #-16]! // 8-byte Folded Spill
; CHECK-NEXT:    addvl sp, sp, #-1
; CHECK-NEXT:    str p6, [sp, #5, mul vl] // 2-byte Folded Spill
; CHECK-NEXT:    str p5, [sp, #6, mul vl] // 2-byte Folded Spill
; CHECK-NEXT:    str p4, [sp, #7, mul vl] // 2-byte Folded Spill
; CHECK-NEXT:    .cfi_escape 0x0f, 0x0c, 0x8f, 0x00, 0x11, 0x10, 0x22, 0x11, 0x08, 0x92, 0x2e, 0x00, 0x1e, 0x22 // sp + 16 + 8 * VG
; CHECK-NEXT:    .cfi_offset w29, -16
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov x8, #281337537757184 // =0xffe000000000
; CHECK-NEXT:    movk x8, #16623, lsl #48
; CHECK-NEXT:    fcmge p1.d, p0/z, z3.d, #0.0
; CHECK-NEXT:    fcmge p2.d, p0/z, z2.d, #0.0
; CHECK-NEXT:    fcmge p3.d, p0/z, z1.d, #0.0
; CHECK-NEXT:    fcmge p4.d, p0/z, z0.d, #0.0
; CHECK-NEXT:    movprfx z5, z3
; CHECK-NEXT:    fcvtzu z5.d, p0/m, z3.d
; CHECK-NEXT:    mov z4.d, x8
; CHECK-NEXT:    movprfx z6, z2
; CHECK-NEXT:    fcvtzu z6.d, p0/m, z2.d
; CHECK-NEXT:    movprfx z7, z1
; CHECK-NEXT:    fcvtzu z7.d, p0/m, z1.d
; CHECK-NEXT:    movprfx z24, z0
; CHECK-NEXT:    fcvtzu z24.d, p0/m, z0.d
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p5.d, p0/z, z3.d, z4.d
; CHECK-NEXT:    fcmgt p6.d, p0/z, z2.d, z4.d
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    mov z2.d, #65535 // =0xffff
; CHECK-NEXT:    not p3.b, p0/z, p3.b
; CHECK-NEXT:    mov z5.d, p1/m, #0 // =0x0
; CHECK-NEXT:    fcmgt p1.d, p0/z, z1.d, z4.d
; CHECK-NEXT:    not p4.b, p0/z, p4.b
; CHECK-NEXT:    fcmgt p0.d, p0/z, z0.d, z4.d
; CHECK-NEXT:    mov z6.d, p2/m, #0 // =0x0
; CHECK-NEXT:    mov z7.d, p3/m, #0 // =0x0
; CHECK-NEXT:    mov z24.d, p4/m, #0 // =0x0
; CHECK-NEXT:    sel z0.d, p5, z2.d, z5.d
; CHECK-NEXT:    ldr p5, [sp, #6, mul vl] // 2-byte Folded Reload
; CHECK-NEXT:    sel z1.d, p6, z2.d, z6.d
; CHECK-NEXT:    ldr p6, [sp, #5, mul vl] // 2-byte Folded Reload
; CHECK-NEXT:    sel z3.d, p1, z2.d, z7.d
; CHECK-NEXT:    ldr p4, [sp, #7, mul vl] // 2-byte Folded Reload
; CHECK-NEXT:    sel z2.d, p0, z2.d, z24.d
; CHECK-NEXT:    uzp1 z0.s, z1.s, z0.s
; CHECK-NEXT:    uzp1 z1.s, z2.s, z3.s
; CHECK-NEXT:    uzp1 z0.h, z1.h, z0.h
; CHECK-NEXT:    addvl sp, sp, #1
; CHECK-NEXT:    ldr x29, [sp], #16 // 8-byte Folded Reload
; CHECK-NEXT:    ret
    %x = call <vscale x 8 x i16> @llvm.fptoui.sat.nxv8f64.nxv8i16(<vscale x 8 x double> %f)
    ret <vscale x 8 x i16> %x
}

define <vscale x 2 x i64> @test_signed_v2f64_v2i64(<vscale x 2 x double> %f) {
; CHECK-LABEL: test_signed_v2f64_v2i64:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov x8, #4895412794951729151 // =0x43efffffffffffff
; CHECK-NEXT:    mov z2.d, x8
; CHECK-NEXT:    fcmge p1.d, p0/z, z0.d, #0.0
; CHECK-NEXT:    movprfx z1, z0
; CHECK-NEXT:    fcvtzu z1.d, p0/m, z0.d
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.d, p0/z, z0.d, z2.d
; CHECK-NEXT:    mov z1.d, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.d, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z0.d, z1.d
; CHECK-NEXT:    ret
    %x = call <vscale x 2 x i64> @llvm.fptoui.sat.nxv2f64.nxv2i64(<vscale x 2 x double> %f)
    ret <vscale x 2 x i64> %x
}

define <vscale x 4 x i64> @test_signed_v4f64_v4i64(<vscale x 4 x double> %f) {
; CHECK-LABEL: test_signed_v4f64_v4i64:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov x8, #4895412794951729151 // =0x43efffffffffffff
; CHECK-NEXT:    mov z4.d, x8
; CHECK-NEXT:    fcmge p1.d, p0/z, z0.d, #0.0
; CHECK-NEXT:    fcmge p2.d, p0/z, z1.d, #0.0
; CHECK-NEXT:    movprfx z2, z0
; CHECK-NEXT:    fcvtzu z2.d, p0/m, z0.d
; CHECK-NEXT:    movprfx z3, z1
; CHECK-NEXT:    fcvtzu z3.d, p0/m, z1.d
; CHECK-NEXT:    fcmgt p3.d, p0/z, z0.d, z4.d
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    fcmgt p0.d, p0/z, z1.d, z4.d
; CHECK-NEXT:    mov z2.d, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z3.d, p2/m, #0 // =0x0
; CHECK-NEXT:    mov z2.d, p3/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z3.d, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z0.d, z2.d
; CHECK-NEXT:    mov z1.d, z3.d
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i64> @llvm.fptoui.sat.nxv4f64.nxv4i64(<vscale x 4 x double> %f)
    ret <vscale x 4 x i64> %x
}


; half

declare <vscale x 2 x i32> @llvm.fptoui.sat.nxv2f16.nxv2i32(<vscale x 2 x half>)
declare <vscale x 4 x i32> @llvm.fptoui.sat.nxv4f16.nxv4i32(<vscale x 4 x half>)
declare <vscale x 8 x i32> @llvm.fptoui.sat.nxv8f16.nxv8i32(<vscale x 8 x half>)
declare <vscale x 4 x i16> @llvm.fptoui.sat.nxv4f16.nxv4i16(<vscale x 4 x half>)
declare <vscale x 8 x i16> @llvm.fptoui.sat.nxv8f16.nxv8i16(<vscale x 8 x half>)
declare <vscale x 2 x i64> @llvm.fptoui.sat.nxv2f16.nxv2i64(<vscale x 2 x half>)
declare <vscale x 4 x i64> @llvm.fptoui.sat.nxv4f16.nxv4i64(<vscale x 4 x half>)

define <vscale x 2 x i32> @test_signed_v2f16_v2i32(<vscale x 2 x half> %f) {
; CHECK-LABEL: test_signed_v2f16_v2i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov w8, #31743 // =0x7bff
; CHECK-NEXT:    mov z1.h, w8
; CHECK-NEXT:    fcmge p1.h, p0/z, z0.h, #0.0
; CHECK-NEXT:    movprfx z2, z0
; CHECK-NEXT:    fcvtzu z2.d, p0/m, z0.h
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.h, p0/z, z0.h, z1.h
; CHECK-NEXT:    mov z0.d, #0xffffffff
; CHECK-NEXT:    mov z2.d, p1/m, #0 // =0x0
; CHECK-NEXT:    sel z0.d, p0, z0.d, z2.d
; CHECK-NEXT:    ret
    %x = call <vscale x 2 x i32> @llvm.fptoui.sat.nxv2f16.nxv2i32(<vscale x 2 x half> %f)
    ret <vscale x 2 x i32> %x
}

define <vscale x 4 x i32> @test_signed_v4f16_v4i32(<vscale x 4 x half> %f) {
; CHECK-LABEL: test_signed_v4f16_v4i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.s
; CHECK-NEXT:    mov w8, #31743 // =0x7bff
; CHECK-NEXT:    mov z2.h, w8
; CHECK-NEXT:    fcmge p1.h, p0/z, z0.h, #0.0
; CHECK-NEXT:    movprfx z1, z0
; CHECK-NEXT:    fcvtzu z1.s, p0/m, z0.h
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.h, p0/z, z0.h, z2.h
; CHECK-NEXT:    mov z1.s, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.s, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z0.d, z1.d
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i32> @llvm.fptoui.sat.nxv4f16.nxv4i32(<vscale x 4 x half> %f)
    ret <vscale x 4 x i32> %x
}

define <vscale x 8 x i32> @test_signed_v8f16_v8i32(<vscale x 8 x half> %f) {
; CHECK-LABEL: test_signed_v8f16_v8i32:
; CHECK:       // %bb.0:
; CHECK-NEXT:    uunpklo z2.s, z0.h
; CHECK-NEXT:    uunpkhi z3.s, z0.h
; CHECK-NEXT:    mov w8, #31743 // =0x7bff
; CHECK-NEXT:    ptrue p0.s
; CHECK-NEXT:    mov z4.h, w8
; CHECK-NEXT:    fcmge p1.h, p0/z, z2.h, #0.0
; CHECK-NEXT:    fcmge p2.h, p0/z, z3.h, #0.0
; CHECK-NEXT:    movprfx z0, z2
; CHECK-NEXT:    fcvtzu z0.s, p0/m, z2.h
; CHECK-NEXT:    movprfx z1, z3
; CHECK-NEXT:    fcvtzu z1.s, p0/m, z3.h
; CHECK-NEXT:    fcmgt p3.h, p0/z, z2.h, z4.h
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    fcmgt p0.h, p0/z, z3.h, z4.h
; CHECK-NEXT:    mov z0.s, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.s, p2/m, #0 // =0x0
; CHECK-NEXT:    mov z0.s, p3/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z1.s, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    ret
    %x = call <vscale x 8 x i32> @llvm.fptoui.sat.nxv8f16.nxv8i32(<vscale x 8 x half> %f)
    ret <vscale x 8 x i32> %x
}

define <vscale x 4 x i16> @test_signed_v4f16_v4i16(<vscale x 4 x half> %f) {
; CHECK-LABEL: test_signed_v4f16_v4i16:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.s
; CHECK-NEXT:    mov w8, #31743 // =0x7bff
; CHECK-NEXT:    mov z1.h, w8
; CHECK-NEXT:    fcmge p1.h, p0/z, z0.h, #0.0
; CHECK-NEXT:    movprfx z2, z0
; CHECK-NEXT:    fcvtzu z2.s, p0/m, z0.h
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.h, p0/z, z0.h, z1.h
; CHECK-NEXT:    mov z0.s, #65535 // =0xffff
; CHECK-NEXT:    mov z2.s, p1/m, #0 // =0x0
; CHECK-NEXT:    sel z0.s, p0, z0.s, z2.s
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i16> @llvm.fptoui.sat.nxv4f16.nxv4i16(<vscale x 4 x half> %f)
    ret <vscale x 4 x i16> %x
}

define <vscale x 8 x i16> @test_signed_v8f16_v8i16(<vscale x 8 x half> %f) {
; CHECK-LABEL: test_signed_v8f16_v8i16:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.h
; CHECK-NEXT:    mov w8, #31743 // =0x7bff
; CHECK-NEXT:    mov z2.h, w8
; CHECK-NEXT:    fcmge p1.h, p0/z, z0.h, #0.0
; CHECK-NEXT:    movprfx z1, z0
; CHECK-NEXT:    fcvtzu z1.h, p0/m, z0.h
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.h, p0/z, z0.h, z2.h
; CHECK-NEXT:    mov z1.h, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.h, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z0.d, z1.d
; CHECK-NEXT:    ret
    %x = call <vscale x 8 x i16> @llvm.fptoui.sat.nxv8f16.nxv8i16(<vscale x 8 x half> %f)
    ret <vscale x 8 x i16> %x
}

define <vscale x 2 x i64> @test_signed_v2f16_v2i64(<vscale x 2 x half> %f) {
; CHECK-LABEL: test_signed_v2f16_v2i64:
; CHECK:       // %bb.0:
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov w8, #31743 // =0x7bff
; CHECK-NEXT:    mov z2.h, w8
; CHECK-NEXT:    fcmge p1.h, p0/z, z0.h, #0.0
; CHECK-NEXT:    movprfx z1, z0
; CHECK-NEXT:    fcvtzu z1.d, p0/m, z0.h
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    fcmgt p0.h, p0/z, z0.h, z2.h
; CHECK-NEXT:    mov z1.d, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.d, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z0.d, z1.d
; CHECK-NEXT:    ret
    %x = call <vscale x 2 x i64> @llvm.fptoui.sat.nxv2f16.nxv2i64(<vscale x 2 x half> %f)
    ret <vscale x 2 x i64> %x
}

define <vscale x 4 x i64> @test_signed_v4f16_v4i64(<vscale x 4 x half> %f) {
; CHECK-LABEL: test_signed_v4f16_v4i64:
; CHECK:       // %bb.0:
; CHECK-NEXT:    uunpklo z2.d, z0.s
; CHECK-NEXT:    uunpkhi z3.d, z0.s
; CHECK-NEXT:    mov w8, #31743 // =0x7bff
; CHECK-NEXT:    ptrue p0.d
; CHECK-NEXT:    mov z4.h, w8
; CHECK-NEXT:    fcmge p1.h, p0/z, z2.h, #0.0
; CHECK-NEXT:    fcmge p2.h, p0/z, z3.h, #0.0
; CHECK-NEXT:    movprfx z0, z2
; CHECK-NEXT:    fcvtzu z0.d, p0/m, z2.h
; CHECK-NEXT:    movprfx z1, z3
; CHECK-NEXT:    fcvtzu z1.d, p0/m, z3.h
; CHECK-NEXT:    fcmgt p3.h, p0/z, z2.h, z4.h
; CHECK-NEXT:    not p1.b, p0/z, p1.b
; CHECK-NEXT:    not p2.b, p0/z, p2.b
; CHECK-NEXT:    fcmgt p0.h, p0/z, z3.h, z4.h
; CHECK-NEXT:    mov z0.d, p1/m, #0 // =0x0
; CHECK-NEXT:    mov z1.d, p2/m, #0 // =0x0
; CHECK-NEXT:    mov z0.d, p3/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    mov z1.d, p0/m, #-1 // =0xffffffffffffffff
; CHECK-NEXT:    ret
    %x = call <vscale x 4 x i64> @llvm.fptoui.sat.nxv4f16.nxv4i64(<vscale x 4 x half> %f)
    ret <vscale x 4 x i64> %x
}
