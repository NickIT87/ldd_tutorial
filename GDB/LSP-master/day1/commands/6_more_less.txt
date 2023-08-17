more command
======================

view contents of text file one page at a time.

press spacebar to go to the next page

$ more filename

more -num filename : shows 'num' of lines in a page

more -10 filename will show 10 lines for every page

less command
=======================

less was written by a man who was fed up with more's inability to scroll backwards through a file.

Less command is linux utility which can be used to read contents of text file one page(one screen) per time.

$ less filename.txt

You can navigate the page up/down using the less command and not possible in more command.

head command
============================

The head command outputs the first part (the head) of a file or files.

head, by default, prints the first 10 lines of each FILE to standard output. 

$ head myfile.txt

Display the first ten lines of myfile.txt.

head -15 myfile.txt

$ Display the first fifteen lines of myfile.txt.

$ head myfile.txt myfile2.txt

Display the first ten lines of both myfile.txt and myfile2.txt

$ head -c 20 myfile.txt

Will output only the first twenty bytes (characters) of myfile.txt

tail command
===============================

Tail is a command which prints the last few number of lines (10 lines by default) of a certain file, then terminates.

$ tail /path/to/file

Interested in just the last 3 lines of a file, or maybe interested in the last 15 lines of a file. this is when the -n option comes handy,

$ tail -n <number_of_lines> /path/to/file

most useful and commonly used option for tail command is -f option. f stands for follow

Unlike the default behaviour which is to end after printing certain number of lines, the -f option “which stands for follow” will keep the stream going.

$ tail -f /path/to/file







