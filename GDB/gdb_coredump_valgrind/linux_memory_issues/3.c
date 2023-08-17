#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void read_underflow(int cond)
{
	char *dest, src[] = "abcd56789", *orig;

	printf("%s(): cond %d\n", __FUNCTION__, cond);
	dest = malloc(25);
	if (!dest)
		printf("malloc failed\n");
	orig = dest;

	strncpy(dest, src, strlen(src));
	if (cond) { /* Bug, below.. */
		*(orig-1) = 'x';
		dest --;
	}
	printf(" dest: %s\n", dest);

	free(orig);
}

//It does not even cause a crash. At first glance, bugs such as this might appear fairly harmless—the truth, though, is that this is a really dangerous bug!
static void read_overflow_dynmem(void)
{
	char *arr;

	arr = malloc(5);
	if (!arr)
		printf("malloc failed\n");
	memset(arr, 'a', 5);
	/* Bug 1: Steal secrets via a buffer overread.
	 * Ensure the next few bytes are _not_ NULL.
	 * Ideally, this should be caught as a bug by the compiler,
	 * but isn't! (Tools do; seen later).
	 */
	arr[5] = 'S'; arr[6] = 'e'; arr[7] = 'c';
	arr[8] = 'r'; arr[9] = 'e'; arr[10] = 'T';
	printf("arr = %s\n", arr);

	/* Bug 2, 3: more read buffer overflows */
	printf("*(arr+100)=%d\n", *(arr + 100));
	printf("*(arr+10000)=%d\n", *(arr + 10000));

	free(arr);
}

//we deliberately do not null-terminate the first buffer (but do so on the second one), so, the printf(3) that will emit on arr continues reading into the second buffer, tmp. What if the tmp buffer contains secrets?

static void read_overflow_compilemem(void)
{
	char arr[16], tmp[16];

	memset(arr, 'a', 16);
	memset(tmp, 't', 16);
	tmp[15] = '\0';

	printf("arr = %s\n", arr);	/* Bug: read buffer overflow */
}


int main()
{
	read_overflow_compilemem();
	//read_overflow_dynmem();
	//read_underflow(0);
	//read_underflow(1);

	return 0;
}
