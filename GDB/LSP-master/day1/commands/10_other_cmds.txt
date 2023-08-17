Other Frequently used commands
==================================

1. wc -- word count

wc -l : Prints the number of lines in a file.
wc -w : prints the number of words in a file.
wc -c : Displays the count of bytes in a file.
wc -m : prints the count of characters from a file.
wc -L : prints only the length of the longest line in a file.

wc filename.txt 
will show number of lines, words and bytes

2. top command

top command displays the top processes in the system ( by default sorted by cpu usage ). 

3. df command

Displays the file system disk space usage.

By default df -k displays output in bytes.

$ df -k

df -h displays output in human readable form. i.e size will be displayed in GB’s.

$ df -h

Use -T option to display what type of file system.

$ df -T

4. uname command

Uname command displays important information about the system such as — Kernel name, Host name, Kernel release number, Processor type, etc.,

$ uname -a

5. date command

Set the system date:

# date -s "01/31/2010 23:59:53"

6. ping command

Check network connectivity

ping ipaddress

7. which command

which command in Linux is a command which is used to locate the executable file associated with the given command by searching it in the path environment variable.

$ which ls

8. whoami command

whoami command print the name of current user

9. lsof command

lsof mean List of all open files.

lsof -u panther2

10. history command

11. time command

Find time taken by a command/program on Linux Shell

The time taken is shown in three forms.
real: Total end to end time taken by program/command
user: Time taken in user mode.
sys: Time taken in kernel mode

$ time ls -l

