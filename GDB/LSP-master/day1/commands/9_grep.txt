grep 
==============

1. grep “linux” file.txt 

It searches for the given string in the specified file.

2. Insensitive search  using -i option

$ grep -i “linux” file.txt

The grep command searches for the words like “LINUX”, “Linux”, “linux” case insensitively.

3. Searching for a string in multiple files

$ grep “linux” file*.*

This command will search for "linux" string in multiple files at a time. It searches in all files with file1.txt, file2.txt and along with different extensions too like file1.html, file2.php and so on.

4. Displaying the line numbers.

$ grep -n “word*” file.txt

You can use this grep command to display the line number which contains the matched string in a file using the -n option

5. Search the pattern recursively using -r option

$ grep -r linux /etc/

6. Counting the lines when words match

$ grep -c 'test' /home/example/test.txt


