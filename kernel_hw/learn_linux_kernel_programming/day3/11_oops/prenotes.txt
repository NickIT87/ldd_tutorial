=====================================
What is OOPS Message in Linux Kernel?
=====================================

An OOPS is similar to segfault in user space. Kernel throws oops message when an exception such as accessing invalid memory location happens in the kernel code.

Upon OOPS, the kernel performs the following operations:

	Kills the offending process
	Prints information which can help the developers to debug
	Continues execution. Note: After oops, the system cannot be trusted further as the some of the locks or structures may not be cleaned up.


An OOPS Message contains the following information:
	Processor Status
	Contents of the CPU Registers at the time of exception
	Stack trace
	Call Trace


