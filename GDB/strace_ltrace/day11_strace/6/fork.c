#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

#define CHILD 0

int main()
{
	pid_t pid;
	printf(" My pid = %d \n", getpid());
	pid = fork();
	if( pid == CHILD){
		printf(" child: My pid = %d \n", getpid());
	}
	else{
		printf(" My pid = %d \n", getpid());
		printf(" Newly created child pid = %d \n", pid);
	}
}
