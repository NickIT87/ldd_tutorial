Generate statistics for System Calls
==============================================================
Sometimes, we only want to look at which system calls were made by the program and how many system calls of same type were made. 

These statistics can be used to identify the most commonly used system calls by the program. 

Using –c option strace provides summary information on executing a program. 

It provides information like 
	number of times a system call is used, 
	time spent executing various system calls, 
	number of times errors returned as shown below.

$ strace -c <command>

'-C' - prints the regular output + stats

$ strace -C <command>
