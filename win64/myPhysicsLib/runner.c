#include <stdio.h>
#include "test.h"

void solver()
{
	int m = 2000; 		/* Kg */
	int t1 = 10; 		/* Celsius */
	int t2 = 60;
	int Q = 88000000; 	/* Joule */
	/* c ? */
	/* solve */
	printf("%d\n", substance(Q, m, t2 - t1));
	/* DEBUG */
	printf("%d\n", Q == quantityOfHeat(substance(Q, m, t2 - t1), m, t2 - t1));
}

int main() 
{
	solver();
	return 0;
}