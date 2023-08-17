/*
	you want to break in myFunction, but only the 4th time you enter that function. 
	steps:
	1. Set a breakpoint to myFunction
	2. condition <num> sFunctionCounter==4
*/

#include <stdio.h>

void myFunction()
{
   // Initialize the counter to 0
   static int sFunctionCounter = 0;
 
   // Each time we enter the function,
   // increment the counter
   sFunctionCounter++;
 
}
 
int main (int argc, const char * argv[])
{
   int i;
 
   // Call 10 times myFunction.
   for(i = 0 ; i < 10 ; i++)
        myFunction();
 
   return 0;
}
