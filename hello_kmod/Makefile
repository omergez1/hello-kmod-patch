# Out-of-tree build of hello_kmod for the Raspberry Pi 5 (based on course slide 184).
# Uses the kernel source and cross-compiler that Buildroot already built.

# Path to a built Buildroot output/ directory; override with: make BR_OUTPUT=/path/to/buildroot/output
BR_OUTPUT     ?= $(HOME)/projects/buildroot_pi5/rpi-buildroot-2026.08/output

ARCH          := arm64
CROSS_COMPILE := $(BR_OUTPUT)/host/bin/aarch64-linux-
obj-m         := hello_kmod.o
ROOTDIR       := $(BR_OUTPUT)/build/linux-custom
PWD           := $(shell pwd)

default:
	$(MAKE) CROSS_COMPILE=$(CROSS_COMPILE) -C $(ROOTDIR) ARCH=$(ARCH) M=$(PWD) modules

clean:
	$(MAKE) CROSS_COMPILE=$(CROSS_COMPILE) -C $(ROOTDIR) ARCH=$(ARCH) M=$(PWD) clean
