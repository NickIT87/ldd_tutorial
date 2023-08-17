#include <stdio.h>


/*A classic case: local (or automatic) variables are, by definition, uninitialized (unlike globals, which are always preset to zero):

In the below code, it's undefined what will occur at runtime as x is uninitialized and will thus have random content.
*/

void uninit_var()
{
	int x;

	if (x)
		printf("true case: x=%d\n", x);
	else
		printf("false case\n");
}

int main()
{

	uninit_var();

	return 0;
}
