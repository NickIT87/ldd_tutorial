obj-m += my_module.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

load:
	sudo insmod my_module.ko
	sudo dmesg -c

unload:
	sudo rmmod my_module.ko
	sudo dmesg -c
