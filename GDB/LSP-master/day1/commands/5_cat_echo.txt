echo command
===============================

It prints the strings that are passed as arguments to the standard output.

echo is usually used in shell scripts to display a message or output the results of other commands.

1. Display a line of text on standard output.

	echo Hello, World!

2. Display a line of text containing a double quote.

	$ echo 'Hello "Linux"'

	$ echo "Hello \"Linux\""

3. Display a message containing special characters.

	Use the -e option to enable the interpretation of the escape characters.

	$ echo -e "You know nothing, Jamal.\n\t- Linux"

4. echo can be used with redirect operator to output to a file and not standard output.

	$ echo "Test Page" > testpage 

5. To append to a file

	$ echo "Test Page" >> testpage 

cat command
=========================

cat stands for concatenate

1. Display the contents of the file

	$ cat /etc/passwd

2. View contents of multiple files

	$ cat file1.txt file2.txt

3. Create a file with cat command

	cat > file.txt

	Will create a file 'file.txt' and allows user to type the content on the console, until user press CTRL-D to exit

4. Display Line numbers in file

	cat -n file.txt

5. Redirect output of a file to a new file
	
	cat file1.txt > file2.txt

	Careful, existing contents of file2.txt will be overwritten by contents of file1.txt file.

6. Appending to an existing file

	cat file1.txt >> file2.txt

	Contents of file1.txt will be appended to file2.txt

