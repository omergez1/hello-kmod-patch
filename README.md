# hello-kmod-patch

A trivial Linux kernel module for the Raspberry Pi 5 (Buildroot 2026.08, kernel 6.12.61), and a kernel patch that integrates it into the kernel source tree.

The module prints `hello world` when loaded and `bye bye world` when unloaded.

## Contents

| File | Description |
|---|---|
| `0002-hello-kmod.patch` | Kernel patch: adds `drivers/misc/hello_kmod.c`, a `HELLO_KMOD` Kconfig entry and a Makefile rule in `drivers/misc/` |
| `hello_kmod/hello_kmod.c` | Module source |
| `hello_kmod/Makefile` | Out-of-tree cross-compile Makefile (uses Buildroot's kernel tree and toolchain) |

## 1. Out-of-tree build and test

```bash
cd hello_kmod
make BR_OUTPUT=/path/to/buildroot/output
scp hello_kmod.ko root@<pi-ip>:/root/
ssh root@<pi-ip> 'insmod /root/hello_kmod.ko && rmmod hello_kmod'
```

Output on the serial console:

```
hello_kmod: hello world
hello_kmod: bye bye world
```

## 2. Integrating the module into the kernel

The patch makes three changes in `drivers/misc/`:

1. Adds the module source: `hello_kmod.c`.
2. `Makefile`: `obj-$(CONFIG_HELLO_KMOD) += hello_kmod.o`
3. `Kconfig`: a `config HELLO_KMOD` tristate entry (default `n`), placed before `endmenu`.

Apply it to the kernel source manually:

```bash
cd <kernel-source>
patch -p1 < 0002-hello-kmod.patch
```

or with Buildroot, by placing it in the directory referenced by `BR2_LINUX_KERNEL_PATCH`.

Then enable the module in the kernel configuration (**Device Drivers → Misc devices → Hello world kernel module**), or set `CONFIG_HELLO_KMOD=m`. Rebuild the kernel; on the target:

```bash
modprobe hello_kmod
modprobe -r hello_kmod
```
