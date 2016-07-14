#include <string.h>
#include <stdio.h>

int main()
{
   char abc ='A';
   char *temp = NULL;
   abc++;
   
   temp = &abc;
   printf("temp = %c\n", *temp);
}
