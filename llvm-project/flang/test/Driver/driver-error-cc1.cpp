// C++ files are currently not supported (i.e. `flang -cc1`). Make sure that the
// driver reports this as expected.

// RUN: not %flang %s 2>&1 | FileCheck %s

// CHECK: error: unknown integrated tool '-cc1'. Valid tools include '-fc1'.
