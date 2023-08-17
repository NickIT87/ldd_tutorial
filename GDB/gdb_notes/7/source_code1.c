/*
	 break when the value of i is 500
	 (gdb) b line number if i==500
*/
#include <stdio.h>
int main() 
{
        int i=0;
        for (i=0;i<1000;i++) 
		{
                printf("%d\n",i);
        }
}
