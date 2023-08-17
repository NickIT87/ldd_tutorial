#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Double-free. Once a malloc family buffer is freed, one is not allowed to use that pointer at all. Attempting to free the same pointer again (without again allocating it memory via one of the malloc family APIs) is a bug: double free.

*/

static void doublefree(int cond)
{
	char *ptr, *bogus;
	char name[]="Hands-on Linux Sys Prg";
	int n=512;

	printf("%s(): cond %d\n", __FUNCTION__, cond);
	ptr = malloc(n);
	if (!ptr)
		printf("malloc failed\n");
	strncpy(ptr, name, strlen(name));
	free(ptr);

	if (cond) {
		/*on a 64-bit OS, -1UL = 0xffffffffffffffff = 18446744073709551615 bytes = 16 EB. That's the entire extent of the virtual address space on 64-bit.*/
		bogus = malloc(-1UL); /* will fail! */
		if (!bogus) {
			fprintf(stderr, "%s:%s:%d: malloc failed\n",
			   __FILE__, __FUNCTION__, __LINE__);
			free(ptr); /* Bug: double-free */
			exit(EXIT_FAILURE);
		}
	}
}


int main()
{

	doublefree(0);
	doublefree(1);
	
	return 0;
}
