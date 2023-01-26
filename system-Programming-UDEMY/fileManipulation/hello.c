#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{

	printf("Hello World!\n");
	
	// Using system calls!
	write(STDOUT_FILENO,"Hello World!\n", strlen("Hello World!\n")); 
	return 0;
}
