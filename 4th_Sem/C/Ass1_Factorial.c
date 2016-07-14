#include <stdio.h>
int facto(int n);

int main()
{
   int n;
   printf("Enter No. : ");
   scanf("%d", &n);
   printf("Factorial of %d = %d\n", n, facto(n));
   return 0;
   
}

int facto(int n)
{
   if(n == 1)
      return 1;
   else
      return n*facto(n-1);;
}

/*
EXAMPLE
Enter No. : 6
Factorial of 6 = 720
*/
