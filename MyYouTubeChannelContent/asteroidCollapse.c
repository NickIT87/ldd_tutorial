#include <stdio.h>
#include <math.h>
#include <complex.h>

//2,59076⋅1020

long double M;

int main()
{
    M = 2.59076 * pow(10, 20);
    
    //printf("%f + i%f\n", creal(M), cimag(M));
    
    printf("%Lf \n", M);

    return 0;
}