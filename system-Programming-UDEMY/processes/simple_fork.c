#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){


	int pid;
	pid = fork();

	// Child Process
	if(pid == 0){
		printf("Hello from the Child --- PID: %d ---- Parent PID: %d\n",getpid(),getppid());
		sleep(10);
	// Parent Process	
	}else{
		wait(NULL);
		printf("Hello from the Parent --- PID: %d ---- Child PID: %d\n",getpid(),pid);	
	}

return 0;
}
