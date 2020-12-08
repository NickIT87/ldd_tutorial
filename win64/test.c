#include <stdio.h>

double quantityOfHeat(double c, double m, double dt)
{	/*	The quantity of heat Q that changes the 
 	temperature ΔT of a mass m of a substance 
 	is given by Q = cmΔT	*/	
	return c * m * dt;
}

double substance(double Q, double m, double dt)
{	/*	Joule per kilogram-degree Celsius	*/
	return Q / (m * dt);
}

int phaseDt(int t1, int t2)
{	/*	time per second	*/
	return t2 - t1;
}

	/*	main flow programm	*/
int main() 
{
	int m = 2000; 			/* Kg */
	int t1 = 10; 			/* Celsius */
	int t2 = 60;
	double Q = 88000000; 	/* Joule */
	/* ? */
	double c = 0;
	/* solve */
	c = substance(Q, m, phaseDt(t1, t2));
	printf("%f\n", c);
	/* DEBUG */
	printf("%f\n", quantityOfHeat(c, m, phaseDt(t1, t2)));

	return 0;
}