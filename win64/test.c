#include <stdio.h>

int quantityOfHeat(int c, int m, int dt)
{	/*	The quantity of heat Q that changes the 
 	temperature ΔT of a mass m of a substance 
 	is given by Q = cmΔT	*/	
	return c * m * dt;
}

int substance(int Q, int m, int dt)
{	/*	Joule per kilogram-degree Celsius	*/
	return Q / (m * dt);
}

	/*	main flow programm	*/
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