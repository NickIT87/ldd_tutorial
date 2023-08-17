-s [size] Print [size] characters per string displayed. This is useful if you are trying to trace what a program is writing to a file descriptor.

strace -s 80 ./program

This will print the first 80 characters of every string.

