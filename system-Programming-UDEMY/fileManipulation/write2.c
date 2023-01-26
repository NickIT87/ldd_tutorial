#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main(){


	int fd, fd2, numOfReads;
	char buffer[100];



	fd = open("random_text.txt", O_RDWR | O_CREAT, 0777);
	fd2 = open("modified_text.txt", O_RDWR | O_CREAT, 0777);
	
	if((fd | fd2) < 0){
		printf("Error!\n");
	}

	

	// While loop to read from random_text.txt and write to modified_text.txt

	int readCount = read(fd, buffer, 100);


	while(readCount > 0){
		// Logic for writing to modified_text.txt
		if(numOfReads % 2 == 0){
			write(fd2, "Even Read!\n",10);
			
		}else{
			write(fd2, buffer, 100);
			write(fd2, "\n", 1);
		}

		readCount = read(fd, buffer, 100);
		numOfReads++;
	} 

	if((close(fd) | close(fd2)) < 0){
		printf("Error!\n");
		exit(1);
	}

	return 0;
}

