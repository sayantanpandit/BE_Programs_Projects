//Example of memory leak without "free()" so that no error is shown

#include <stdlib.h>

int main()
{
  char *x;
  x = (char *)malloc(sizeof(char));
  //free(x);
  return 0;
}
