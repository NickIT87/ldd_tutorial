#include <stdio.h>


void printMessage(char *msg) {
	if (msg != NULL)
		printf("msg:%s\n", msg);
}


int main(){
	
	char buffer[] = "Hello World";
	int i = 10;

	printMessage(buffer);
	return 0;
}
