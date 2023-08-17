#include <stdio.h>

unsigned int factorial(unsigned int n)
{
    if (n == 0)  
		return 1;
    return n * factorial(n-1);
}

int main(int argc, char* argv[])
{
	unsigned int loop = 50;
	while(loop--) {
    printf("Factorial of number %d is %u\n", 
            loop, 
            factorial(loop));
	}
    
	return 0;
}
