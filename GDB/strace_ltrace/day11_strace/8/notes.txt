Tracing only specific system calls 
=================================

Sometimes the full syscall trace is too much

Using –e option we can also specify which system calls to be traced.

To trace only open() and close() system calls use the following command:

$ strace –e trace=’open,close’ <program-name>


Similarly we can also use negation option to not trace specific system calls. If we don’t want to trace open() system call in previous example we can give the below command 

$ strace -e trace='!open,close' ./a.out

Track by specific system call group
====================================
-e trace=ipc – Track communication between processes (IPC)
-e trace=memory – Track memory syscalls
-e trace=network – Track memory syscalls
-e trace=process – Track process calls (like fork, exec)
-e trace=signal – Track process signal handling (like HUP, exit)
-e trace=file (for syscalls that mention filenames)
-e trace=desc (for read() and write() and friends, which mention file descriptors)


strace -e trace=open,stat,read,write gnome-calculator

strace -e trace=openat cat /etc/hosts
strace -e trace=openat,close cat /etc/hosts
strace -e trace=openat,close,read,write cat /etc/hosts
strace -e file cat /etc/hosts
