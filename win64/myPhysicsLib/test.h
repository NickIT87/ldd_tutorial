/*#include <stdio.h>*/

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

