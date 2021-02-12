#include <stdio.h>

int main()
{
    int arr[]={1,2,3,2,3,1,4,5,5,6,6};
    int res = 0;
    for(int i = 0; i < 11; i++)
    {
	res = res ^ arr[i];
    }
    printf("%d", res);

    return 0;
}
