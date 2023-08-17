locate
==================

Locates a file within the Linux File System

$ locate <filename>


find
===================

Find command performs the same functionality as locates

$find <path> -name 'filename'

Differences between locate and find
====================================

locate uses a prebuilt database, which should be regularly updated
find iterates over the filesystem to find the files

locate is much faster as it uses a database(to update the database use updatedb command)
find can select files based on not only name but also permissions, owner, file type etc

$find / -name "*conf" -mtime 7
command returns a list of all files in the entire file system that end with the characters conf and have been modified in the last 7 days.




