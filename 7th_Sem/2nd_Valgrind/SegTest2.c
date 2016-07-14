#include <stdio.h>

int main()
{
  int x,y;  
  printf("\nx : ");
  scanf("%d", &x);
  printf("\ny : ");
  scanf("%d", y);
  
  if(x == y)
       printf("X equals to Y\n");
  else if(x > y)
       printf("X greater than Y\n");
  else if(x < y)
       printf("Y less than X\n");
  return 0; 
}
