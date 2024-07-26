// RUN:   %clang -### --target=x86_64-unknown-linux-gnu -fopenmp=libomp --sysroot=./ \
// RUN:     -fopenmp-targets=amdgcn-amd-amdhsa -Xopenmp-target=amdgcn-amd-amdhsa --offload-arch=gfx908  \
// RUN:     -nogpulib %s 2>&1 | FileCheck %s --check-prefix=CHECK-HEADERS
// RUN:   %clang -### --target=x86_64-unknown-linux-gnu -fopenmp=libomp --sysroot=./ \
// RUN:     -fopenmp-targets=nvptx64-nvidia-cuda -Xopenmp-target=nvptx64-nvidia-cuda --offload-arch=sm_70  \
// RUN:     -nogpulib %s 2>&1 | FileCheck %s --check-prefix=CHECK-HEADERS
// CHECK-HEADERS: "-cc1"{{.*}}"-isysroot" "./"{{.*}}"-internal-isystem" "{{.*}}include{{.*}}llvm_libc_wrappers"
// CHECK-HEADERS: "-cc1"{{.*}}"-isysroot" "./"{{.*}}"-internal-isystem" "{{.*}}include{{.*}}llvm_libc_wrappers"

// RUN:   %clang -### --target=amdgcn-amd-amdhsa -mcpu=gfx90a --sysroot=./ \
// RUN:     -nogpulib %s 2>&1 | FileCheck %s --check-prefix=CHECK-HEADERS-AMDGPU
// RUN:   %clang -### --target=nvptx64-nvidia-cuda -march=sm_89 --sysroot=./ \
// RUN:     -nogpulib %s 2>&1 | FileCheck %s --check-prefix=CHECK-HEADERS-NVPTX
// CHECK-HEADERS-AMDGPU: "-cc1"{{.*}}"-isysroot" "./"{{.*}}"-internal-isystem" "{{.*}}include{{.*}}amdgcn-amd-amdhsa"
// CHECK-HEADERS-NVPTX: "-cc1"{{.*}}"-isysroot" "./"{{.*}}"-internal-isystem" "{{.*}}include{{.*}}nvptx64-nvidia-cuda"

// RUN:   %clang -### --target=amdgcn-amd-amdhsa -mcpu=gfx1030 -nogpulib \
// RUN:     -nogpuinc %s 2>&1 | FileCheck %s --check-prefix=CHECK-HEADERS-DISABLED
// RUN:   %clang -### --target=amdgcn-amd-amdhsa -mcpu=gfx1030 -nogpulib \
// RUN:     -nostdinc %s 2>&1 | FileCheck %s --check-prefix=CHECK-HEADERS-DISABLED
// RUN:   %clang -### --target=amdgcn-amd-amdhsa -mcpu=gfx1030 -nogpulib \
// RUN:     -nobuiltininc %s 2>&1 | FileCheck %s --check-prefix=CHECK-HEADERS-DISABLED
// CHECK-HEADERS-DISABLED-NOT: "-cc1"{{.*}}"-internal-isystem" "{{.*}}include{{.*}}gpu-none-llvm"
