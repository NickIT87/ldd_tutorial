#include <stdio.h>

int main(void)
{
  register int wye;
  int *ptr;
  int ex;

  ptr = &ex;
  ex = 305441741;
  wye = -1;
  printf("Enter an integer: ");
  scanf("%i", ptr);
  wye += *ptr;
  printf("The result is %i\n", wye);

  return 0;
}
