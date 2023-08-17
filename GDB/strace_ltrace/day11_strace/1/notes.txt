What are all these calls between execve() and write()?
==========================================================
They take care of connecting all of the standard C libraries before the main program starts. 

They basically set up the runtime. If you look at them carefully you’ll see that they walk through a series of possible files, check to see if they are accessible, open them, map them into a memory location, and close them.



Redirecting the output to a file 
============

Viewing data in the terminal is one thing, but sometimes we need to record the data to an file so we can analyze it later.

Using -o option we can redirect the complex output of strace into a file.

$ strace -o <output-file-name> <program-name>


$ strace -o empty-trace ./1
$ strace -o print-trace ./2
$ vimdiff empty-trace print-trace
