ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m  := devcats.o

else
# normal makefile
    KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD

help:
	$(MAKE) -C $(KDIR) M=$$PWD help

modules_install:
	$(MAKE) -C $(KDIR) M=$$PWD modules_install

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

endif
