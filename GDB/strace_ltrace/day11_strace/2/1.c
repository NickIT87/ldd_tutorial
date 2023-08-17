#include <stdio.h>

int main(void)
{
	FILE *fd = NULL;

	if(fd = fopen("test","rw"))
	{   
		printf("test file opened\n");
		fclose(fd);
	}   
	else
	{   
		printf("Failed to open the file\n");
	}   

	return 0;
}
