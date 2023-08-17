pwd command
========================
Will print the current working directory
$pwd

touch command 
====================
Allows user to make files from the command line Interface

Note: You can only create files using touch command not directories.

$ touch <filename>.<extension>

rm command
===================

rm -- remove 

This command is used to remove files

$ rm <filename>.<extension>

Note it only removes files, trying to remove directory fails

You can use -r option to remove the directories. -r option recursively removes directories

$ rm -r <directoryname>

mkdir command
====================

mkdir -- Make directory

Allows user to create a new directory.

$ mkdir <directory_name>

rmdir command
================

rmdir -- remove directory

Allows user to remove a directory

$ rmdir <directory_name>

mv command
================

mv -- Move

Allows user to move file from one place to another 

mv /home/user1/file1.txt /home/user/test/file1.txt

Other use case of mv is to rename

mv /home/user1/file1.txt /home/user/file.txt

cp command
===============

cp -- Copy

$ cp file1 file2

$ cp -i file1 file2

if file2 exists prompt for confirmation before overwritting it.

$ cp -p file1 file2

Copy file1 to file2 preserving the mode, ownership and timestamp.

clear command
==================

clear command clears the screen

clear command will take the user back to the start prompt of whatever directory you are currently operating in

man command
==============

man -- Manual

Use to show the manual of the command passed

$ man man


