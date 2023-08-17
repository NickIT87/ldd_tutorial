What is strace
===================

strace stands for system call tracer

It is a debugging tool that 
	monitors the system calls used by a program and 
	all the signals it receives.

System calls are used by userspace applications when they need to do something that requires the kernel. 

What it does
===================

----> Learn which system calls a program make

----> Find those system calls that fail together with error code

----> Find which files a program opens

----> Find out what syscalls a running program is making, for example to see if it is struck in a loop



Using strace is quite simple. There are two ways to let strace monitor a program.

Method 1:
=========

$ strace program_name

Ex: $ strace ls

$strace pwd

Reading strace output:

Each line in the output represents a system call. They follow the format: 

system_call(argument1, argument2, ... ) = return_value 

Errors (typically a return value of -1) have the errno symbol and error string appended.

open("/foo/bar", O_RDONLY) = -1 ENOENT (No such file or directory)

strace emits its entire output to stderr


Method 2:
============

If we want to monitor a process which is currently running we can attach to the process using –p option

$ strace –p <pid-of-the-application>


$ dd if=/dev/zero of=/dev/null bs=1 count=500k
$ strace dd if=/dev/zero of=/dev/null bs=1 count=500k

