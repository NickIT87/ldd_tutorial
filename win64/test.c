#include <stdio.h>

int quantityOfHeat(double c, double m, double dt );

int main() {
	printf("%d\n", quantityOfHeat(880, 200, 23));


	return 0;
}

/* The quantity of heat Q that changes the 
 temperature ΔT of a mass m of a substance 
 is given by Q = cmΔT */
int quantityOfHeat(double c, double m, double dt )
{
	long double Q = c * m * dt;
	return Q;
}