! RUN: bbc -emit-hlfir -fopenmp %s -o - | FileCheck %s
! RUN: %flang_fc1 -emit-hlfir -fopenmp %s -o - | FileCheck %s

! CHECK-LABEL:   omp.declare_reduction @add_reduction_f64 : f64 init {
! CHECK:         ^bb0(%[[VAL_0:.*]]: f64):
! CHECK:           %[[VAL_1:.*]] = arith.constant 0.000000e+00 : f64
! CHECK:           omp.yield(%[[VAL_1]] : f64)

! CHECK-LABEL:   } combiner {
! CHECK:         ^bb0(%[[VAL_0:.*]]: f64, %[[VAL_1:.*]]: f64):
! CHECK:           %[[VAL_2:.*]] = arith.addf %[[VAL_0]], %[[VAL_1]] fastmath<contract> : f64
! CHECK:           omp.yield(%[[VAL_2]] : f64)
! CHECK:         }

! CHECK-LABEL:   omp.declare_reduction @add_reduction_i64 : i64 init {
! CHECK:         ^bb0(%[[VAL_0:.*]]: i64):
! CHECK:           %[[VAL_1:.*]] = arith.constant 0 : i64
! CHECK:           omp.yield(%[[VAL_1]] : i64)

! CHECK-LABEL:   } combiner {
! CHECK:         ^bb0(%[[VAL_0:.*]]: i64, %[[VAL_1:.*]]: i64):
! CHECK:           %[[VAL_2:.*]] = arith.addi %[[VAL_0]], %[[VAL_1]] : i64
! CHECK:           omp.yield(%[[VAL_2]] : i64)
! CHECK:         }

! CHECK-LABEL:   omp.declare_reduction @add_reduction_f32 : f32 init {
! CHECK:         ^bb0(%[[VAL_0:.*]]: f32):
! CHECK:           %[[VAL_1:.*]] = arith.constant 0.000000e+00 : f32
! CHECK:           omp.yield(%[[VAL_1]] : f32)

! CHECK-LABEL:   } combiner {
! CHECK:         ^bb0(%[[VAL_0:.*]]: f32, %[[VAL_1:.*]]: f32):
! CHECK:           %[[VAL_2:.*]] = arith.addf %[[VAL_0]], %[[VAL_1]] fastmath<contract> : f32
! CHECK:           omp.yield(%[[VAL_2]] : f32)
! CHECK:         }

! CHECK-LABEL:   omp.declare_reduction @add_reduction_i32 : i32 init {
! CHECK:         ^bb0(%[[VAL_0:.*]]: i32):
! CHECK:           %[[VAL_1:.*]] = arith.constant 0 : i32
! CHECK:           omp.yield(%[[VAL_1]] : i32)

! CHECK-LABEL:   } combiner {
! CHECK:         ^bb0(%[[VAL_0:.*]]: i32, %[[VAL_1:.*]]: i32):
! CHECK:           %[[VAL_2:.*]] = arith.addi %[[VAL_0]], %[[VAL_1]] : i32
! CHECK:           omp.yield(%[[VAL_2]] : i32)
! CHECK:         }

! CHECK-LABEL:   func.func @_QPsimple_int_reduction() {
! CHECK:           %[[VAL_0:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFsimple_int_reductionEi"}
! CHECK:           %[[VAL_1:.*]]:2 = hlfir.declare %[[VAL_0]] {uniq_name = "_QFsimple_int_reductionEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_2:.*]] = fir.alloca i32 {bindc_name = "x", uniq_name = "_QFsimple_int_reductionEx"}
! CHECK:           %[[VAL_3:.*]]:2 = hlfir.declare %[[VAL_2]] {uniq_name = "_QFsimple_int_reductionEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_4:.*]] = arith.constant 0 : i32
! CHECK:           hlfir.assign %[[VAL_4]] to %[[VAL_3]]#0 : i32, !fir.ref<i32>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_5:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_6:.*]]:2 = hlfir.declare %[[VAL_5]] {uniq_name = "_QFsimple_int_reductionEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_7:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_8:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_9:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(@add_reduction_i32 %[[VAL_3]]#0 -> %[[VAL_10:.*]] : !fir.ref<i32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_11:.*]]) : i32 = (%[[VAL_7]]) to (%[[VAL_8]]) inclusive step (%[[VAL_9]]) {
! CHECK:                 %[[VAL_12:.*]]:2 = hlfir.declare %[[VAL_10]] {uniq_name = "_QFsimple_int_reductionEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:                 fir.store %[[VAL_11]] to %[[VAL_6]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_13:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_14:.*]] = fir.load %[[VAL_6]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_15:.*]] = arith.addi %[[VAL_13]], %[[VAL_14]] : i32
! CHECK:                 hlfir.assign %[[VAL_15]] to %[[VAL_12]]#0 : i32, !fir.ref<i32>
! CHECK:                 omp.yield
! CHECK:               }
! CHECK:               omp.terminator
! CHECK:             }
! CHECK:             omp.terminator
! CHECK:           }
! CHECK:           return
! CHECK:         }

subroutine simple_int_reduction
  integer :: x
  x = 0
  !$omp parallel
  !$omp do reduction(+:x)
  do i=1, 100
    x = x + i
  end do
  !$omp end do
  !$omp end parallel
end subroutine


! CHECK-LABEL:   func.func @_QPsimple_real_reduction() {
! CHECK:           %[[VAL_0:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFsimple_real_reductionEi"}
! CHECK:           %[[VAL_1:.*]]:2 = hlfir.declare %[[VAL_0]] {uniq_name = "_QFsimple_real_reductionEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_2:.*]] = fir.alloca f32 {bindc_name = "x", uniq_name = "_QFsimple_real_reductionEx"}
! CHECK:           %[[VAL_3:.*]]:2 = hlfir.declare %[[VAL_2]] {uniq_name = "_QFsimple_real_reductionEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:           %[[VAL_4:.*]] = arith.constant 0.000000e+00 : f32
! CHECK:           hlfir.assign %[[VAL_4]] to %[[VAL_3]]#0 : f32, !fir.ref<f32>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_5:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_6:.*]]:2 = hlfir.declare %[[VAL_5]] {uniq_name = "_QFsimple_real_reductionEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_7:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_8:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_9:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(@add_reduction_f32 %[[VAL_3]]#0 -> %[[VAL_10:.*]] : !fir.ref<f32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_11:.*]]) : i32 = (%[[VAL_7]]) to (%[[VAL_8]]) inclusive step (%[[VAL_9]]) {
! CHECK:                 %[[VAL_12:.*]]:2 = hlfir.declare %[[VAL_10]] {uniq_name = "_QFsimple_real_reductionEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:                 fir.store %[[VAL_11]] to %[[VAL_6]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_13:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<f32>
! CHECK:                 %[[VAL_14:.*]] = fir.load %[[VAL_6]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_15:.*]] = fir.convert %[[VAL_14]] : (i32) -> f32
! CHECK:                 %[[VAL_16:.*]] = arith.addf %[[VAL_13]], %[[VAL_15]] fastmath<contract> : f32
! CHECK:                 hlfir.assign %[[VAL_16]] to %[[VAL_12]]#0 : f32, !fir.ref<f32>
! CHECK:                 omp.yield
! CHECK:               }
! CHECK:               omp.terminator
! CHECK:             }
! CHECK:             omp.terminator
! CHECK:           }
! CHECK:           return
! CHECK:         }

subroutine simple_real_reduction
  real :: x
  x = 0.0
  !$omp parallel
  !$omp do reduction(+:x)
  do i=1, 100
    x = x + i
  end do
  !$omp end do
  !$omp end parallel
end subroutine


! CHECK-LABEL:   func.func @_QPsimple_int_reduction_switch_order() {
! CHECK:           %[[VAL_0:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFsimple_int_reduction_switch_orderEi"}
! CHECK:           %[[VAL_1:.*]]:2 = hlfir.declare %[[VAL_0]] {uniq_name = "_QFsimple_int_reduction_switch_orderEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_2:.*]] = fir.alloca i32 {bindc_name = "x", uniq_name = "_QFsimple_int_reduction_switch_orderEx"}
! CHECK:           %[[VAL_3:.*]]:2 = hlfir.declare %[[VAL_2]] {uniq_name = "_QFsimple_int_reduction_switch_orderEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_4:.*]] = arith.constant 0 : i32
! CHECK:           hlfir.assign %[[VAL_4]] to %[[VAL_3]]#0 : i32, !fir.ref<i32>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_5:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_6:.*]]:2 = hlfir.declare %[[VAL_5]] {uniq_name = "_QFsimple_int_reduction_switch_orderEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_7:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_8:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_9:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(@add_reduction_i32 %[[VAL_3]]#0 -> %[[VAL_10:.*]] : !fir.ref<i32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_11:.*]]) : i32 = (%[[VAL_7]]) to (%[[VAL_8]]) inclusive step (%[[VAL_9]]) {
! CHECK:                 %[[VAL_12:.*]]:2 = hlfir.declare %[[VAL_10]] {uniq_name = "_QFsimple_int_reduction_switch_orderEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:                 fir.store %[[VAL_11]] to %[[VAL_6]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_13:.*]] = fir.load %[[VAL_6]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_14:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_15:.*]] = arith.addi %[[VAL_13]], %[[VAL_14]] : i32
! CHECK:                 hlfir.assign %[[VAL_15]] to %[[VAL_12]]#0 : i32, !fir.ref<i32>
! CHECK:                 omp.yield
! CHECK:               }
! CHECK:               omp.terminator
! CHECK:             }
! CHECK:             omp.terminator
! CHECK:           }
! CHECK:           return
! CHECK:         }

subroutine simple_int_reduction_switch_order
  integer :: x
  x = 0
  !$omp parallel
  !$omp do reduction(+:x)
  do i=1, 100
    x = i + x
  end do
  !$omp end do
  !$omp end parallel
end subroutine

! CHECK-LABEL:   func.func @_QPsimple_real_reduction_switch_order() {
! CHECK:           %[[VAL_0:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFsimple_real_reduction_switch_orderEi"}
! CHECK:           %[[VAL_1:.*]]:2 = hlfir.declare %[[VAL_0]] {uniq_name = "_QFsimple_real_reduction_switch_orderEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_2:.*]] = fir.alloca f32 {bindc_name = "x", uniq_name = "_QFsimple_real_reduction_switch_orderEx"}
! CHECK:           %[[VAL_3:.*]]:2 = hlfir.declare %[[VAL_2]] {uniq_name = "_QFsimple_real_reduction_switch_orderEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:           %[[VAL_4:.*]] = arith.constant 0.000000e+00 : f32
! CHECK:           hlfir.assign %[[VAL_4]] to %[[VAL_3]]#0 : f32, !fir.ref<f32>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_5:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_6:.*]]:2 = hlfir.declare %[[VAL_5]] {uniq_name = "_QFsimple_real_reduction_switch_orderEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_7:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_8:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_9:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(@add_reduction_f32 %[[VAL_3]]#0 -> %[[VAL_10:.*]] : !fir.ref<f32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_11:.*]]) : i32 = (%[[VAL_7]]) to (%[[VAL_8]]) inclusive step (%[[VAL_9]]) {
! CHECK:                 %[[VAL_12:.*]]:2 = hlfir.declare %[[VAL_10]] {uniq_name = "_QFsimple_real_reduction_switch_orderEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:                 fir.store %[[VAL_11]] to %[[VAL_6]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_13:.*]] = fir.load %[[VAL_6]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_14:.*]] = fir.convert %[[VAL_13]] : (i32) -> f32
! CHECK:                 %[[VAL_15:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<f32>
! CHECK:                 %[[VAL_16:.*]] = arith.addf %[[VAL_14]], %[[VAL_15]] fastmath<contract> : f32
! CHECK:                 hlfir.assign %[[VAL_16]] to %[[VAL_12]]#0 : f32, !fir.ref<f32>
! CHECK:                 omp.yield
! CHECK:               }
! CHECK:               omp.terminator
! CHECK:             }
! CHECK:             omp.terminator
! CHECK:           }
! CHECK:           return
! CHECK:         }

subroutine simple_real_reduction_switch_order
  real :: x
  x = 0.0
  !$omp parallel
  !$omp do reduction(+:x)
  do i=1, 100
    x = i + x
  end do
  !$omp end do
  !$omp end parallel
end subroutine

! CHECK-LABEL:   func.func @_QPmultiple_int_reductions_same_type() {
! CHECK:           %[[VAL_0:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFmultiple_int_reductions_same_typeEi"}
! CHECK:           %[[VAL_1:.*]]:2 = hlfir.declare %[[VAL_0]] {uniq_name = "_QFmultiple_int_reductions_same_typeEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_2:.*]] = fir.alloca i32 {bindc_name = "x", uniq_name = "_QFmultiple_int_reductions_same_typeEx"}
! CHECK:           %[[VAL_3:.*]]:2 = hlfir.declare %[[VAL_2]] {uniq_name = "_QFmultiple_int_reductions_same_typeEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_4:.*]] = fir.alloca i32 {bindc_name = "y", uniq_name = "_QFmultiple_int_reductions_same_typeEy"}
! CHECK:           %[[VAL_5:.*]]:2 = hlfir.declare %[[VAL_4]] {uniq_name = "_QFmultiple_int_reductions_same_typeEy"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_6:.*]] = fir.alloca i32 {bindc_name = "z", uniq_name = "_QFmultiple_int_reductions_same_typeEz"}
! CHECK:           %[[VAL_7:.*]]:2 = hlfir.declare %[[VAL_6]] {uniq_name = "_QFmultiple_int_reductions_same_typeEz"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_8:.*]] = arith.constant 0 : i32
! CHECK:           hlfir.assign %[[VAL_8]] to %[[VAL_3]]#0 : i32, !fir.ref<i32>
! CHECK:           %[[VAL_9:.*]] = arith.constant 0 : i32
! CHECK:           hlfir.assign %[[VAL_9]] to %[[VAL_5]]#0 : i32, !fir.ref<i32>
! CHECK:           %[[VAL_10:.*]] = arith.constant 0 : i32
! CHECK:           hlfir.assign %[[VAL_10]] to %[[VAL_7]]#0 : i32, !fir.ref<i32>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_11:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_12:.*]]:2 = hlfir.declare %[[VAL_11]] {uniq_name = "_QFmultiple_int_reductions_same_typeEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_13:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_14:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_15:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(@add_reduction_i32 %[[VAL_3]]#0 -> %[[VAL_16:.*]] : !fir.ref<i32>, @add_reduction_i32 %[[VAL_5]]#0 -> %[[VAL_17:.*]] : !fir.ref<i32>, @add_reduction_i32 %[[VAL_7]]#0 -> %[[VAL_18:.*]] : !fir.ref<i32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_19:.*]]) : i32 = (%[[VAL_13]]) to (%[[VAL_14]]) inclusive step (%[[VAL_15]]) {
! CHECK:                 %[[VAL_20:.*]]:2 = hlfir.declare %[[VAL_16]] {uniq_name = "_QFmultiple_int_reductions_same_typeEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:                 %[[VAL_21:.*]]:2 = hlfir.declare %[[VAL_17]] {uniq_name = "_QFmultiple_int_reductions_same_typeEy"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:                 %[[VAL_22:.*]]:2 = hlfir.declare %[[VAL_18]] {uniq_name = "_QFmultiple_int_reductions_same_typeEz"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:                 fir.store %[[VAL_19]] to %[[VAL_12]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_23:.*]] = fir.load %[[VAL_20]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_24:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_25:.*]] = arith.addi %[[VAL_23]], %[[VAL_24]] : i32
! CHECK:                 hlfir.assign %[[VAL_25]] to %[[VAL_20]]#0 : i32, !fir.ref<i32>
! CHECK:                 %[[VAL_26:.*]] = fir.load %[[VAL_21]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_27:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_28:.*]] = arith.addi %[[VAL_26]], %[[VAL_27]] : i32
! CHECK:                 hlfir.assign %[[VAL_28]] to %[[VAL_21]]#0 : i32, !fir.ref<i32>
! CHECK:                 %[[VAL_29:.*]] = fir.load %[[VAL_22]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_30:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_31:.*]] = arith.addi %[[VAL_29]], %[[VAL_30]] : i32
! CHECK:                 hlfir.assign %[[VAL_31]] to %[[VAL_22]]#0 : i32, !fir.ref<i32>
! CHECK:                 omp.yield
! CHECK:               }
! CHECK:               omp.terminator
! CHECK:             }
! CHECK:             omp.terminator
! CHECK:           }
! CHECK:           return
! CHECK:         }

subroutine multiple_int_reductions_same_type
  integer :: x,y,z
  x = 0
  y = 0
  z = 0
  !$omp parallel
  !$omp do reduction(+:x,y,z)
  do i=1, 100
    x = x + i
    y = y + i
    z = z + i
  end do
  !$omp end do
  !$omp end parallel
end subroutine

! CHECK-LABEL:   func.func @_QPmultiple_real_reductions_same_type() {
! CHECK:           %[[VAL_0:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFmultiple_real_reductions_same_typeEi"}
! CHECK:           %[[VAL_1:.*]]:2 = hlfir.declare %[[VAL_0]] {uniq_name = "_QFmultiple_real_reductions_same_typeEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_2:.*]] = fir.alloca f32 {bindc_name = "x", uniq_name = "_QFmultiple_real_reductions_same_typeEx"}
! CHECK:           %[[VAL_3:.*]]:2 = hlfir.declare %[[VAL_2]] {uniq_name = "_QFmultiple_real_reductions_same_typeEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:           %[[VAL_4:.*]] = fir.alloca f32 {bindc_name = "y", uniq_name = "_QFmultiple_real_reductions_same_typeEy"}
! CHECK:           %[[VAL_5:.*]]:2 = hlfir.declare %[[VAL_4]] {uniq_name = "_QFmultiple_real_reductions_same_typeEy"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:           %[[VAL_6:.*]] = fir.alloca f32 {bindc_name = "z", uniq_name = "_QFmultiple_real_reductions_same_typeEz"}
! CHECK:           %[[VAL_7:.*]]:2 = hlfir.declare %[[VAL_6]] {uniq_name = "_QFmultiple_real_reductions_same_typeEz"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:           %[[VAL_8:.*]] = arith.constant 0.000000e+00 : f32
! CHECK:           hlfir.assign %[[VAL_8]] to %[[VAL_3]]#0 : f32, !fir.ref<f32>
! CHECK:           %[[VAL_9:.*]] = arith.constant 0.000000e+00 : f32
! CHECK:           hlfir.assign %[[VAL_9]] to %[[VAL_5]]#0 : f32, !fir.ref<f32>
! CHECK:           %[[VAL_10:.*]] = arith.constant 0.000000e+00 : f32
! CHECK:           hlfir.assign %[[VAL_10]] to %[[VAL_7]]#0 : f32, !fir.ref<f32>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_11:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_12:.*]]:2 = hlfir.declare %[[VAL_11]] {uniq_name = "_QFmultiple_real_reductions_same_typeEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_13:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_14:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_15:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(@add_reduction_f32 %[[VAL_3]]#0 -> %[[VAL_16:.*]] : !fir.ref<f32>, @add_reduction_f32 %[[VAL_5]]#0 -> %[[VAL_17:.*]] : !fir.ref<f32>, @add_reduction_f32 %[[VAL_7]]#0 -> %[[VAL_18:.*]] : !fir.ref<f32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_19:.*]]) : i32 = (%[[VAL_13]]) to (%[[VAL_14]]) inclusive step (%[[VAL_15]]) {
! CHECK:                 %[[VAL_20:.*]]:2 = hlfir.declare %[[VAL_16]] {uniq_name = "_QFmultiple_real_reductions_same_typeEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:                 %[[VAL_21:.*]]:2 = hlfir.declare %[[VAL_17]] {uniq_name = "_QFmultiple_real_reductions_same_typeEy"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:                 %[[VAL_22:.*]]:2 = hlfir.declare %[[VAL_18]] {uniq_name = "_QFmultiple_real_reductions_same_typeEz"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:                 fir.store %[[VAL_19]] to %[[VAL_12]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_23:.*]] = fir.load %[[VAL_20]]#0 : !fir.ref<f32>
! CHECK:                 %[[VAL_24:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_25:.*]] = fir.convert %[[VAL_24]] : (i32) -> f32
! CHECK:                 %[[VAL_26:.*]] = arith.addf %[[VAL_23]], %[[VAL_25]] fastmath<contract> : f32
! CHECK:                 hlfir.assign %[[VAL_26]] to %[[VAL_20]]#0 : f32, !fir.ref<f32>
! CHECK:                 %[[VAL_27:.*]] = fir.load %[[VAL_21]]#0 : !fir.ref<f32>
! CHECK:                 %[[VAL_28:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_29:.*]] = fir.convert %[[VAL_28]] : (i32) -> f32
! CHECK:                 %[[VAL_30:.*]] = arith.addf %[[VAL_27]], %[[VAL_29]] fastmath<contract> : f32
! CHECK:                 hlfir.assign %[[VAL_30]] to %[[VAL_21]]#0 : f32, !fir.ref<f32>
! CHECK:                 %[[VAL_31:.*]] = fir.load %[[VAL_22]]#0 : !fir.ref<f32>
! CHECK:                 %[[VAL_32:.*]] = fir.load %[[VAL_12]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_33:.*]] = fir.convert %[[VAL_32]] : (i32) -> f32
! CHECK:                 %[[VAL_34:.*]] = arith.addf %[[VAL_31]], %[[VAL_33]] fastmath<contract> : f32
! CHECK:                 hlfir.assign %[[VAL_34]] to %[[VAL_22]]#0 : f32, !fir.ref<f32>
! CHECK:                 omp.yield
! CHECK:               }
! CHECK:               omp.terminator
! CHECK:             }
! CHECK:             omp.terminator
! CHECK:           }
! CHECK:           return
! CHECK:         }

subroutine multiple_real_reductions_same_type
  real :: x,y,z
  x = 0.0
  y = 0.0
  z = 0.0
  !$omp parallel
  !$omp do reduction(+:x,y,z)
  do i=1, 100
    x = x + i
    y = y + i
    z = z + i
  end do
  !$omp end do
  !$omp end parallel
end subroutine

! CHECK-LABEL:   func.func @_QPmultiple_reductions_different_type() {
! CHECK:           %[[VAL_0:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFmultiple_reductions_different_typeEi"}
! CHECK:           %[[VAL_1:.*]]:2 = hlfir.declare %[[VAL_0]] {uniq_name = "_QFmultiple_reductions_different_typeEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_2:.*]] = fir.alloca f64 {bindc_name = "w", uniq_name = "_QFmultiple_reductions_different_typeEw"}
! CHECK:           %[[VAL_3:.*]]:2 = hlfir.declare %[[VAL_2]] {uniq_name = "_QFmultiple_reductions_different_typeEw"} : (!fir.ref<f64>) -> (!fir.ref<f64>, !fir.ref<f64>)
! CHECK:           %[[VAL_4:.*]] = fir.alloca i32 {bindc_name = "x", uniq_name = "_QFmultiple_reductions_different_typeEx"}
! CHECK:           %[[VAL_5:.*]]:2 = hlfir.declare %[[VAL_4]] {uniq_name = "_QFmultiple_reductions_different_typeEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_6:.*]] = fir.alloca i64 {bindc_name = "y", uniq_name = "_QFmultiple_reductions_different_typeEy"}
! CHECK:           %[[VAL_7:.*]]:2 = hlfir.declare %[[VAL_6]] {uniq_name = "_QFmultiple_reductions_different_typeEy"} : (!fir.ref<i64>) -> (!fir.ref<i64>, !fir.ref<i64>)
! CHECK:           %[[VAL_8:.*]] = fir.alloca f32 {bindc_name = "z", uniq_name = "_QFmultiple_reductions_different_typeEz"}
! CHECK:           %[[VAL_9:.*]]:2 = hlfir.declare %[[VAL_8]] {uniq_name = "_QFmultiple_reductions_different_typeEz"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:           %[[VAL_10:.*]] = arith.constant 0 : i32
! CHECK:           hlfir.assign %[[VAL_10]] to %[[VAL_5]]#0 : i32, !fir.ref<i32>
! CHECK:           %[[VAL_11:.*]] = arith.constant 0 : i64
! CHECK:           hlfir.assign %[[VAL_11]] to %[[VAL_7]]#0 : i64, !fir.ref<i64>
! CHECK:           %[[VAL_12:.*]] = arith.constant 0.000000e+00 : f32
! CHECK:           hlfir.assign %[[VAL_12]] to %[[VAL_9]]#0 : f32, !fir.ref<f32>
! CHECK:           %[[VAL_13:.*]] = arith.constant 0.000000e+00 : f64
! CHECK:           hlfir.assign %[[VAL_13]] to %[[VAL_3]]#0 : f64, !fir.ref<f64>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_14:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_15:.*]]:2 = hlfir.declare %[[VAL_14]] {uniq_name = "_QFmultiple_reductions_different_typeEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_16:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_17:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_18:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(@add_reduction_i32 %[[VAL_5]]#0 -> %[[VAL_19:.*]] : !fir.ref<i32>, @add_reduction_i64 %[[VAL_7]]#0 -> %[[VAL_20:.*]] : !fir.ref<i64>, @add_reduction_f32 %[[VAL_9]]#0 -> %[[VAL_21:.*]] : !fir.ref<f32>, @add_reduction_f64 %[[VAL_3]]#0 -> %[[VAL_22:.*]] : !fir.ref<f64>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_23:.*]]) : i32 = (%[[VAL_16]]) to (%[[VAL_17]]) inclusive step (%[[VAL_18]]) {
! CHECK:                 %[[VAL_24:.*]]:2 = hlfir.declare %[[VAL_19]] {uniq_name = "_QFmultiple_reductions_different_typeEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:                 %[[VAL_25:.*]]:2 = hlfir.declare %[[VAL_20]] {uniq_name = "_QFmultiple_reductions_different_typeEy"} : (!fir.ref<i64>) -> (!fir.ref<i64>, !fir.ref<i64>)
! CHECK:                 %[[VAL_26:.*]]:2 = hlfir.declare %[[VAL_21]] {uniq_name = "_QFmultiple_reductions_different_typeEz"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:                 %[[VAL_27:.*]]:2 = hlfir.declare %[[VAL_22]] {uniq_name = "_QFmultiple_reductions_different_typeEw"} : (!fir.ref<f64>) -> (!fir.ref<f64>, !fir.ref<f64>)
! CHECK:                 fir.store %[[VAL_23]] to %[[VAL_15]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_28:.*]] = fir.load %[[VAL_24]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_29:.*]] = fir.load %[[VAL_15]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_30:.*]] = arith.addi %[[VAL_28]], %[[VAL_29]] : i32
! CHECK:                 hlfir.assign %[[VAL_30]] to %[[VAL_24]]#0 : i32, !fir.ref<i32>
! CHECK:                 %[[VAL_31:.*]] = fir.load %[[VAL_25]]#0 : !fir.ref<i64>
! CHECK:                 %[[VAL_32:.*]] = fir.load %[[VAL_15]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_33:.*]] = fir.convert %[[VAL_32]] : (i32) -> i64
! CHECK:                 %[[VAL_34:.*]] = arith.addi %[[VAL_31]], %[[VAL_33]] : i64
! CHECK:                 hlfir.assign %[[VAL_34]] to %[[VAL_25]]#0 : i64, !fir.ref<i64>
! CHECK:                 %[[VAL_35:.*]] = fir.load %[[VAL_26]]#0 : !fir.ref<f32>
! CHECK:                 %[[VAL_36:.*]] = fir.load %[[VAL_15]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_37:.*]] = fir.convert %[[VAL_36]] : (i32) -> f32
! CHECK:                 %[[VAL_38:.*]] = arith.addf %[[VAL_35]], %[[VAL_37]] fastmath<contract> : f32
! CHECK:                 hlfir.assign %[[VAL_38]] to %[[VAL_26]]#0 : f32, !fir.ref<f32>
! CHECK:                 %[[VAL_39:.*]] = fir.load %[[VAL_27]]#0 : !fir.ref<f64>
! CHECK:                 %[[VAL_40:.*]] = fir.load %[[VAL_15]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_41:.*]] = fir.convert %[[VAL_40]] : (i32) -> f64
! CHECK:                 %[[VAL_42:.*]] = arith.addf %[[VAL_39]], %[[VAL_41]] fastmath<contract> : f64
! CHECK:                 hlfir.assign %[[VAL_42]] to %[[VAL_27]]#0 : f64, !fir.ref<f64>
! CHECK:                 omp.yield
! CHECK:               }
! CHECK:               omp.terminator
! CHECK:             }
! CHECK:             omp.terminator
! CHECK:           }
! CHECK:           return
! CHECK:         }

subroutine multiple_reductions_different_type
  integer :: x
  integer(kind=8) :: y
  real :: z
  real(kind=8) :: w
  x = 0
  y = 0
  z = 0.0
  w = 0.0
  !$omp parallel
  !$omp do reduction(+:x,y,z,w)
  do i=1, 100
    x = x + i
    y = y + i
    z = z + i
    w = w + i
  end do
  !$omp end do
  !$omp end parallel
end subroutine
