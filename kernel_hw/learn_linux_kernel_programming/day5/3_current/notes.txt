While writing a module if we want to get information about the current process that is running in the kernel, we need to read the "task_struct" of the  corresponding process.

The kernel provides a easy way to do this by providing a macro by the name "current", which always returns a pointer to the "task_struct" of the current executing process.

This macro has to be implemented by each architecture.

Some architectures stores this in a register some stores them in bottom of kernel stack of process
