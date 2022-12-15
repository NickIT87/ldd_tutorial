#include <stdio.h>

int square(int a) {
	return a * a;
}


int main(int argc, char **argv) {
	//  int (*test)();
	// double(*test)(double);
	int (*test)(int);
	test = square;

	printf("Result=%d\n", test(4));
	return 0;
}
