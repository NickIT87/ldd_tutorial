What is THIS_MODULE?
========================

Whenever you create a kernel module, the kernel's build machinery generates a struct module object for you, and makes THIS_MODULE point to it.

This struct contains many fields, some of which can be set with module macros such as MODULE_VERSION.

<linux/export.h>

#ifndef __ASSEMBLY__
#ifdef MODULE
extern struct module __this_module;
#define THIS_MODULE (&__this_module)
#else
#define THIS_MODULE ((struct module *)0)
#endif


You can see from the definition of THIS_MODULE macro that it is referring to '__this_module'. This is defined when we build the module file by running 'make'
