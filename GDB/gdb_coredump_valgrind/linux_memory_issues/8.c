#include <stdio.h>

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

static void leakage_case2(size_t size, unsigned int reps)
{
	unsigned int i, threshold = 3*BLK_1MB;
	double mem_leaked;

	if (reps == 0)
		reps = 1;
	mem_leaked = size * reps;
	printf("%s(): will now leak a total of %.0f bytes (%.2f MB)"
			" [%zu bytes * %u loops]\n",
			__FUNCTION__, mem_leaked, mem_leaked/(1024*1024),
			size, reps);

	if (mem_leaked >= threshold)
		system("free|grep \"^Mem:\"");

	for (i=0; i<reps; i++) {
		if (i%10000 == 0)
			printf("%s():%6d:malloc(%zu)\n", __FUNCTION__, i, size);
		amleaky(size);
	}

	if (mem_leaked >= threshold)
		system("free|grep \"^Mem:\"");
	printf("\n");
}

int main()
{

	/*We allocate, and leak, a tiny amount of memory (32 bytes) but in a loop 100,000 times (so, yes, we end up leaking over 3 MB)*/
	leakage_case2(32, 100000);
	/*We allocate, and leak, a large amount of memory (1 MB) in a loop 12 times (so, we end up leaking 12 MB).*/
	leakage_case2(BLK_1MB, 12);

	return 0;
}
