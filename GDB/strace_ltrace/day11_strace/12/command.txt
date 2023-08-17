$ strace -T -ttt -o strace.out ./1

The actual write function writes out 1,600 bytes (this is the number after the equals sign toward the end of the line)

Simple math says that the write throughput was 40MBps (1,600 byes/0.000040 seconds).


Increase the counter value and check how many system calls are being executed
