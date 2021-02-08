#include <stdio.h>
/*
int main(int argc, char const *argv[])
{
	long nc;

	nc = 0;

	while (getchar() != EOF)
		++nc;

	printf("%ld\n", nc);

	return 0;
}
*/
main() 
{
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}
