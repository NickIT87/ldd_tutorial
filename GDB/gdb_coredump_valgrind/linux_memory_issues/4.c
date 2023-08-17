#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Use After Free (UAF). Operating upon a memory pointer after it has been freed up is obviously a bug, causing UB. The pointer is sometimes called a dangling pointer.


static void uaf(void)
{
	char *arr, *next;
	char name[]="Hands-on Linux Sys Prg";
	int n=512;

	arr = malloc(n);
	if (!arr)
		printf("malloc arr failed\n");
	memset(arr, 'a', n);
	arr[n-1]='\0';
	printf("%s():%d: arr = %p:%.*s\n", __FUNCTION__, __LINE__, arr, 32, arr);

	next = malloc(n);
	if (!next) {
		free(arr);
		fprintf(stderr, "Error log: arr=%p:val=%s\n", arr, arr);
			/* Noticed one more potential UAF here? */
		printf("malloc next failed\n");
	}
	free(arr);
	strncpy(arr, name, strlen(name)); /* Bug: UAF */

	printf("%s():%d: arr = %p:%.*s\n", __FUNCTION__, __LINE__, arr, 32, arr);
	free(next);
}

//Tip:Did you notice the neat printf(3) format specifier, %.*s, trick? This format is used to print a string of a specific length (no terminating null required!). First, specify the length in bytes to print, and then the pointer to string.

int main()
{
	uaf();
	return 0;
}
