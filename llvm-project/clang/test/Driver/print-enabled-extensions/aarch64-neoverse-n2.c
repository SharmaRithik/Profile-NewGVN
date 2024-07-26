// REQUIRES: aarch64-registered-target
// RUN: %clang --target=aarch64 --print-enabled-extensions -mcpu=neoverse-n2 | FileCheck --strict-whitespace --implicit-check-not=FEAT_ %s

// CHECK: Extensions enabled for the given AArch64 target
// CHECK-EMPTY:
// CHECK-NEXT:     Architecture Feature(s)                                Description
// CHECK-NEXT:     FEAT_AMUv1                                             Enable Armv8.4-A Activity Monitors extension
// CHECK-NEXT:     FEAT_AdvSIMD                                           Enable Advanced SIMD instructions
// CHECK-NEXT:     FEAT_BF16                                              Enable BFloat16 Extension
// CHECK-NEXT:     FEAT_BTI                                               Enable Branch Target Identification
// CHECK-NEXT:     FEAT_CCIDX                                             Enable Armv8.3-A Extend of the CCSIDR number of sets
// CHECK-NEXT:     FEAT_CRC32                                             Enable Armv8.0-A CRC-32 checksum instructions
// CHECK-NEXT:     FEAT_CSV2_2                                            Enable architectural speculation restriction
// CHECK-NEXT:     FEAT_DIT                                               Enable Armv8.4-A Data Independent Timing instructions
// CHECK-NEXT:     FEAT_DPB                                               Enable Armv8.2-A data Cache Clean to Point of Persistence
// CHECK-NEXT:     FEAT_DPB2                                              Enable Armv8.5-A Cache Clean to Point of Deep Persistence
// CHECK-NEXT:     FEAT_DotProd                                           Enable dot product support
// CHECK-NEXT:     FEAT_ETE                                               Enable Embedded Trace Extension
// CHECK-NEXT:     FEAT_FCMA                                              Enable Armv8.3-A Floating-point complex number support
// CHECK-NEXT:     FEAT_FHM                                               Enable FP16 FML instructions
// CHECK-NEXT:     FEAT_FP                                                Enable Armv8.0-A Floating Point Extensions
// CHECK-NEXT:     FEAT_FP16                                              Enable half-precision floating-point data processing
// CHECK-NEXT:     FEAT_FRINTTS                                           Enable FRInt[32|64][Z|X] instructions that round a floating-point number to an integer (in FP format) forcing it to fit into a 32- or 64-bit int
// CHECK-NEXT:     FEAT_FlagM                                             Enable Armv8.4-A Flag Manipulation instructions
// CHECK-NEXT:     FEAT_FlagM2                                            Enable alternative NZCV format for floating point comparisons
// CHECK-NEXT:     FEAT_I8MM                                              Enable Matrix Multiply Int8 Extension
// CHECK-NEXT:     FEAT_JSCVT                                             Enable Armv8.3-A JavaScript FP conversion instructions
// CHECK-NEXT:     FEAT_LOR                                               Enable Armv8.1-A Limited Ordering Regions extension
// CHECK-NEXT:     FEAT_LRCPC                                             Enable support for RCPC extension
// CHECK-NEXT:     FEAT_LRCPC2                                            Enable Armv8.4-A RCPC instructions with Immediate Offsets
// CHECK-NEXT:     FEAT_LSE                                               Enable Armv8.1-A Large System Extension (LSE) atomic instructions
// CHECK-NEXT:     FEAT_LSE2                                              Enable Armv8.4-A Large System Extension 2 (LSE2) atomicity rules
// CHECK-NEXT:     FEAT_MPAM                                              Enable Armv8.4-A Memory system Partitioning and Monitoring extension
// CHECK-NEXT:     FEAT_MTE, FEAT_MTE2                                    Enable Memory Tagging Extension
// CHECK-NEXT:     FEAT_NV, FEAT_NV2                                      Enable Armv8.4-A Nested Virtualization Enchancement
// CHECK-NEXT:     FEAT_PAN                                               Enable Armv8.1-A Privileged Access-Never extension
// CHECK-NEXT:     FEAT_PAN2                                              Enable Armv8.2-A PAN s1e1R and s1e1W Variants
// CHECK-NEXT:     FEAT_PAuth                                             Enable Armv8.3-A Pointer Authentication extension
// CHECK-NEXT:     FEAT_PMUv3                                             Enable Armv8.0-A PMUv3 Performance Monitors extension
// CHECK-NEXT:     FEAT_RAS, FEAT_RASv1p1                                 Enable Armv8.0-A Reliability, Availability and Serviceability Extensions
// CHECK-NEXT:     FEAT_RDM                                               Enable Armv8.1-A Rounding Double Multiply Add/Subtract instructions
// CHECK-NEXT:     FEAT_SB                                                Enable Armv8.5-A Speculation Barrier
// CHECK-NEXT:     FEAT_SEL2                                              Enable Armv8.4-A Secure Exception Level 2 extension
// CHECK-NEXT:     FEAT_SPECRES                                           Enable Armv8.5-A execution and data prediction invalidation instructions
// CHECK-NEXT:     FEAT_SSBS, FEAT_SSBS2                                  Enable Speculative Store Bypass Safe bit
// CHECK-NEXT:     FEAT_SVE                                               Enable Scalable Vector Extension (SVE) instructions
// CHECK-NEXT:     FEAT_SVE2                                              Enable Scalable Vector Extension 2 (SVE2) instructions
// CHECK-NEXT:     FEAT_SVE_BitPerm                                       Enable bit permutation SVE2 instructions
// CHECK-NEXT:     FEAT_TLBIOS, FEAT_TLBIRANGE                            Enable Armv8.4-A TLB Range and Maintenance instructions
// CHECK-NEXT:     FEAT_TRBE                                              Enable Trace Buffer Extension
// CHECK-NEXT:     FEAT_TRF                                               Enable Armv8.4-A Trace extension
// CHECK-NEXT:     FEAT_UAO                                               Enable Armv8.2-A UAO PState
// CHECK-NEXT:     FEAT_VHE                                               Enable Armv8.1-A Virtual Host extension
