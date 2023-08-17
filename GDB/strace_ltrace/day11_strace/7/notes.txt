Attaching strace to a running process
=====================================

strace can also be attached to a running process and can be used to record its system calls.

To do this, we must know the PID of the process which we want to debug. 

We can get this PID using the ps command. 

When we have the PID, we can pass it to strace using the -p parameter to the command.

$ strace -p 4724


The “strace -p ...” which is attached to a process may be stopped at any time by typing CTRL-C; the
tested program then continues to proceed normally and at full speed.

If the program was started under strace, typing CTRL-C will not only abort strace, but also the launched program
