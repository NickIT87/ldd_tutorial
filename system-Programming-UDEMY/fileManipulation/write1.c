#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
int main(){

	// User Group Other
	// R: 4  W: 2  X: 1


	int file;

	file = open("myFile.txt", O_RDWR | O_CREAT, 0755);

	if(file < 0){
		printf("Error Creating/Opening File!\n");
	}

	char *writeThis = "I am writing to the file";

	int writeSz;

	writeSz = write(file, writeThis, strlen(writeThis));

	if(writeSz < 0){
		printf("Error Writing to file!\n");
	}

	if(close(file) < 0){
		printf("Error\n");
	}

	return 0;
}

