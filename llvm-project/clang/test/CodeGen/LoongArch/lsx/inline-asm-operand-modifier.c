// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// RUN: %clang_cc1 -triple loongarch64 -emit-llvm -O2 %s -o - | FileCheck %s

typedef long long v2i64 __attribute__ ((vector_size(16), aligned(16)));

// CHECK-LABEL: define dso_local void @test_w
// CHECK-SAME: () local_unnamed_addr #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <2 x i64> asm sideeffect "vldi ${0:w}, 1", "=f"() #[[ATTR1:[0-9]+]], !srcloc !2
// CHECK-NEXT:    ret void
//
void test_w() {
  v2i64 v2i64_r;
  asm volatile ("vldi %w0, 1" : "=f" (v2i64_r));
}
