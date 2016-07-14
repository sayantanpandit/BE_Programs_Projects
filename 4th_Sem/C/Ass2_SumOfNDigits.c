#include <stdio.h>
int sum(int n);

int main()
{
   int n;
   printf("Enter No. : ");
   scanf("%d", &n);
   printf("Sum = %d\n", sum(n));
   return 0;   
}

int sum(int n)
{
   if(n == 1)
      return 1;
   else
      return n + sum(n-1);;
}

/*
EXAMPLE
Enter No. : 5
Sum = 15
*/
