#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){

	int pid,y,z;
	char *arg[1] = {0};
	pid = fork();

	if(pid == 0){
		printf("CHILD PROCESS\n");
		execv("hello_world",arg);
	}

	y = wait(&z);

	exit(0);
}
