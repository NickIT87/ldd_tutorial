==============================
What is Kernel Panic
==============================

Kernel Panic is an error in the kernel code. 

On Kernel Panic, kernel stop running immediately to avoid data loss or other damage. 

The reason to stop running is to protect your computer, 
for example, if the module which is controlling the fan fails to load, kernel generates a panic and freezes the system.

===================================
What are the reasons for Kernel Panic
======================================

Hardware or Software Issue (e.g. unable to start init process)
Bug in the kernel driver
Defective or Incompatible RAM


=====================================
What happens during Kernel Panic
=====================================

When kernel decides to Panic, it calls the panic() function which dumps some debug information and depending on the configuration reboots the system

=========================================
Configure Kernel to reboot on Kernel Panic
=========================================

By default, the kernel will not reboot on Kernel Panic. There are two ways by which you can instruct the kernel to reboot

1. Kernel Command line: Add "panic=N" to the kernel command line, for the kernel to reboot after N seconds
2. Proc File system: echo N > /proc/sys/kernel/panic , for kernel to reboot after N seconds on reboot. Note this setting is not persistent on reboot.

