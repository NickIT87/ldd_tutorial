#include <stdio.h>

main()
{
	int c;
	
	while ((c = getchar()) != EOF)
		putchar(c);

	printf("%d\n", EOF);

	if (((c = getchar()) != EOF) == 1) {
		printf("1\n");
	}
	
}