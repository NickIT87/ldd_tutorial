#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Memory Leakage: The golden rule for dynamic memory is to free the memory you allocate after using.
	Memory leakage is the term used to describe the situation where one fails to do so.

*/
static const size_t BLK_1MB = 1024*1024;

static void amleaky(size_t mem)
{
	char *ptr;

	ptr = malloc(mem);
	if (!ptr)
		printf("malloc(%zu) failed\n", mem);
	/* Do something with the memory region; else, the compiler
	 * might just optimize the whole thing away!
	 * ... and we won't 'see' the leak.
	 */
	memset(ptr, 0, mem);

	/* Bug: no free, leakage */
}

static void leakage_case1(size_t size)
{
	printf("%s(): will now leak %zu bytes (%ld MB)\n",
			__FUNCTION__, size, size/(1024*1024));
	amleaky(size);
}



int main()
{

	leakage_case1(32);
	leakage_case1(BLK_1MB);
	return 0;
}
