Time spent per system call 
==========================
Sometimes, it is important to understand which system call is taking how much time

This knowledge can be used to identify the bottlenecks in the application

Using –T option we can get time spent per system call.

-Ttt returns time spent per each system call as well as microsecond precision

$ strace -T pwd

$ strace -Ttt pwd
