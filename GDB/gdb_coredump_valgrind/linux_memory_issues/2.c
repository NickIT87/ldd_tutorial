#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void write_overflow_compilemem(void)
{
	int i, arr[5];

	for (i = 0; i <= 50; i++) {
		arr[i] = 100;	/* Bug: 'arr' overflows on i==5*/
	}
}

static void write_overflow_dynmem(void)
{
	char *dest, src[] = "abcd56789123456789";

	dest = malloc(8);
	if (!dest)
		printf("malloc failed\n");

	strcpy(dest, src);	/* Bug: write overflow */
	free(dest);
}

static void write_underflow(void)
{
	char *p = malloc(8);

	if (!p)
		printf("malloc failed\n");

	p--;
	strncpy(p, "abcd5678", 8);	/* Bug: write underflow */
	free(++p);
}

int main()
{
	//write_underflow();
	write_overflow_dynmem();
	//write_overflow_compilemem();

	return 0;
}
