/* Physics 8 class Baryakhtar, Dovguy */
#include <stdio.h>
#include "test.h"

void p35_solver()
{
	/* During the combustion of firewood, a brick stove weighing 
	2 tons received 88 megajoules of heat and heated up from 10 to 60 
	degrees Celsius. Determine the specific heat of the brick. */

	int m = 2000; 		/* Kg */
	int t1 = 10; 		/* Celsius */
	int t2 = 60;
	int Q = 88000000; 	/* Joule */
	/* c ? */
	/* solve */
	printf("%d\n", substance(Q, m, t2 - t1)); /* 880 joule/kg*Celsius */
	/* DEBUG */
	printf("%d\n", Q==quantityOfHeat(substance(Q,m,t2-t1), m, t2-t1));
}


void p122_solver() {
	return 0;
}


int main() 
{
	p35_solver();
	return 0;
}
