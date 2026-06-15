obj-m := hello.o

KBUILD_EXTRA_SYMBOLS := /home/linuxtrainer/Linux_Device_Drivers/day3/3_license/Module.symvers

all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
