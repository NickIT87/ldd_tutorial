Linux kernel internally refers processes as tasks.  
Kernel stores the list of processes in a circular doubly linked list called the task list.

Each task/process is represented in kernel with struct task_struct (defined in <linux/sched.h>).

This data structure (task_struct) is huge (1.7 Kilobytes) containing all the information about a specific process.

Let's write a module/device driver which reads the circular linked list and prints the following information for us:

	-->	Process Name

	--> Process ID

	--> Process State

Before that, we should know what are the different states a process can be:

	TASK_RUNNING: Process is either currently running or on a run-queue waiting to run
	TASK_INTERRUPTIBLE: Process is sleeping/blocked. Can be runnable/awaken by a signal
	TASK_UNINTERRUPTIBLE: Similar to TASK_INTERRUPTIBLE, but does not wakeup on a signal
	__TASK_TRACED: Process is traced by a debugger e.g. ptrace
	__TASK_STOPPED: Process execution has stopped. This happens when the task receives SIGSTOP, SIGTSTP, SIGTTIN or SIGTTOU signal or if it receives any signal while it is being debugged.


