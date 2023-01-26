#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main() {

	int file;
	
	// 0 USER GROUP OTHER
	// R: 4    W: 2   X: 1

	file = open("newFile.txt", O_RDWR | O_CREAT, 0750);

	if(file < 0){
		printf("Error!\n");
		exit(1);
	}  

	int x;

	x = close(file);

	if(x < 0){
		printf("Error!\n");
		exit(1);
	} 

	int y;
	
	y = remove("newFile.txt.txt");

	if(y < 0){
		print("Error!\n");
		exit(1);
	}

	return(0);
}

