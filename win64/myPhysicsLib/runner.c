#include <stdio.h>
#include "test.h"

int main() 
{
	int m = 2000; 		/* Kg */
	int t1 = 10; 		/* Celsius */
	int t2 = 60;
	int Q = 88000000; 	/* Joule */
	/* ? */
	int c = 0;
	/* solve */
	c = substance(Q, m, t2 - t1);
	printf("%d\n", c);
	/* DEBUG */
	printf("%d\n", Q == quantityOfHeat(substance(Q, m, t2 - t1), m, t2 - t1));

	return 0;
}