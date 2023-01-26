#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main(){

	
	int fd;
	char buffer[100];

	fd = open("random_text.txt", O_RDONLY, 0777);
	if(fd < 0){
		printf("Error!\n");
		exit(1);
	}

	int readCount;
	readCount = read(fd, buffer, 100);

	while(readCount > 0){
		printf("%.*s\n",readCount,buffer);
		readCount = read(fd, buffer, 100);
	}


	if(close(fd) < 0){
		printf("Error!\n");
		exit(1);
	}

	return(0);
}

