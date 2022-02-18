#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>

int main (void) 
{
    double x = 5.0;
    double y = gsl_sf_bessel_J0 (x);
    printf("J0(%g) = %.18e\n", x, y);
    return 0;
}

/* 
1) compiling
        gcc -Wall -I/usr/local/include -c example.c
2) linking
        gcc -L/usr/local/lib example.o -lgsl -lgslcblas -lm
*/