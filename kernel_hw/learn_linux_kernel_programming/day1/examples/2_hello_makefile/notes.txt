============================================
What happens when we do insmod on a module 
============================================

What is a kernel module?

	Kernel module is a piece of kernel code which can be added to the running kernel when loaded and can be removed from the kernel when the functionality is removed.

When we do insmod on a module, it performs a series of steps:

	a) It calls init_module() to intimate the kernel that a module is attempted to be loaded and transfers the control to the kernel

	b) In kernel, sys_init_module() is run. It does a sequence of operations as follows:

		--> Verifies if the user who attempts to load the module has the permission to do so or not

		--> After verification, load_module function is called.

				-->	The load_module function assigns temporary memory and copies the elf module from user space to kernel memory using copy_from_user

				--> It then checks the sanity of the ELF file ( Verification if it is a proper ELF file )

				--> Then based on the ELF file interpretation, it generates offset in the temporary memory space allocated. This is called the convenience variables

				-->	User arguments to the module are also copied to the kernel memory

				-->	Symbol resolution is done

				-->	The load_module function returns a reference to the kernel module.

		-->	The reference to the module returned by load_module is added to a doubly linked list that has a list of all the modules loaded in the system

		-->	Then the module_init function in the module code is called
