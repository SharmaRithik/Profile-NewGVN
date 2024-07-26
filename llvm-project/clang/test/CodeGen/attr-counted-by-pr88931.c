// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -O2 -Wno-missing-declarations -emit-llvm -o - %s | FileCheck %s

struct foo {
  int x,y,z;
  struct bar {
    int count;
    int array[] __attribute__((counted_by(count)));
  };
};

void init(void * __attribute__((pass_dynamic_object_size(0))));

// CHECK-LABEL: define dso_local void @test1(
// CHECK-SAME: ptr noundef [[P:%.*]]) local_unnamed_addr #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[ARRAY:%.*]] = getelementptr inbounds i8, ptr [[P]], i64 4
// CHECK-NEXT:    tail call void @init(ptr noundef nonnull [[ARRAY]], i64 noundef -1) #[[ATTR2:[0-9]+]]
// CHECK-NEXT:    ret void
//
void test1(struct bar *p) {
  init(p->array);
}

struct mux {
  int count;
  int array[] __attribute__((counted_by(count)));
};

struct bux { struct mux x; };

// CHECK-LABEL: define dso_local void @test2(
// CHECK-SAME: ptr noundef [[P:%.*]]) local_unnamed_addr #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @init(ptr noundef [[P]], i64 noundef -1) #[[ATTR2]]
// CHECK-NEXT:    ret void
//
void test2(struct bux *p) {
  init(p);
}
