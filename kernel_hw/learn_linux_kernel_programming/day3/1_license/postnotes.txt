What is tainted kernel?
==========================

When the kernel is tainted, it means that it is in a state that is not supported by the community. 

In addition, some debugging functionality and API calls may be disabled when the kernel is tainted.

The kernel may become tainted for any of several reasons, including (but not limited to) the following

	The use of a proprietary (or non-GPL-compatible) kernel module—this is the most common cause of tainted kernels and usually results from loading proprietary NVIDIA or AMD video drivers

	The use of staging drivers, which are part of the kernel source code but are not fully tested

	The use of out-of-tree modules that are not included with the Linux kernel source code

	Certain critical error conditions, such as machine check exceptions and kernel oopses
