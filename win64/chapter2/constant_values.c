#include <stdio.h>
#include <limits.h>
#include<float.h>
/* определить диапазоны типов */
int main()
{
	printf("Integer datatypes:\n");
    printf("%d <= char <= %d\n", CHAR_MIN, CHAR_MAX);
    printf("%d <= int <= %d\n", INT_MIN, INT_MAX);
    printf("%ld <= long <= %ld\n", LONG_MIN, LONG_MAX);
    printf("%d <= signed char <= %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("%d <= short <= %d\n", SHRT_MIN, SHRT_MAX);
    printf("0 <= unsigned char <= %d\n", UCHAR_MAX);
    printf("0 <= unsigned int <= %u\n", UINT_MAX);
    printf("0 <= unsigned long <= %lu\n", ULONG_MAX);
    printf("0 <= unsigned short <= %d\n", USHRT_MAX);
    printf("\n");
    printf("Float datatypes:\n");
    printf("%e <= float <= %e\n", FLT_MIN, FLT_MAX);
    printf("%e <= double <= %e\n", DBL_MIN, DBL_MAX);
  	

    typedef enum {
    	FALSE,	// 0
    	TRUE,	// 1
    } bool;

    bool a = TRUE;
    bool b = FALSE;

    printf("True: %d, False: %d\n", a, b);

    return 0;
}
