#include <stdio.h>

int quantityOfHeat(int c, int m, int dt );

int main() {
	printf("%d\n", quantityOfHeat(880, 2000, 50));


	return 0;
}

int quantityOfHeat(int c, int m, int dt )
{
	int Q = c * m * dt;
	return Q;
}