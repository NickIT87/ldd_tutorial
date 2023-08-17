pipe |
=================

Linux systems allow stdout of a command to be connected to stdin of another command.

You can make it do so by using the pipe character ‘|’.

Pipe is used to combine two or more commands, and in this, the output of one command acts as input to another command

Syntax:

command_1 | command_2 | command_3 | .... | command_N 

1. Listing all files and directories and give it as input to more command.

$ ls -l | more 

2. Use head and tail to print lines in a particular range in a file.

$ cat sample2.txt | head -7 | tail -5

This command select first 7 lines and last 5 lines from the file and print those lines which are common to both of them.

tee command
==================

The tee command reads from the standard input and writes to both standard output and one or more files at the same time

$ df -h | tee disk_usage.txt

we are using the df command to get information about the amount of available disk space on the file system

The output is piped to the tee command, which displays the output to the terminal and writes the same information to the file disk_usage.txt.






