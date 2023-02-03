#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){

	int pid,y,z;
	char *arg[5] = {"gcc","-o","hello_world","hello_world.c",0};

	pid = fork();

	if(pid == 0){
		printf("CHILD PROCESS\n");
		execv("/usr/bin/gcc",arg);
	}

	y = wait(&z);

	exit(0);
}
