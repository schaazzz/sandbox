obj-m  := test_module.o

KDIR   := /usr/src/linux-headers-2.6.22-14-generic
PWD    := $(shell pwd)

#all:
#		$(MAKE) -C $(KDIR) M=$(PWD)
#clean:
#		rm -f *.o core .depend .*.cmd *.ko *.mod.c
default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
