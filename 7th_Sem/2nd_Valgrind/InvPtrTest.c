//Example of catching invalid pointer use
//Allocating an array of characters of size "10" elements
//and then trying to write to the "11th" element 

#include <stdio.h>

int main()
{
  char *x;
  x = (char *)malloc(10*sizeof(char));
  x[10] = 'a';
  free(x);
  return 0;
}
