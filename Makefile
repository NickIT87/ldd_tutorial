obj-m := hello.o
KDIR := /lib/modules/5.3.0-45-generic/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD)
