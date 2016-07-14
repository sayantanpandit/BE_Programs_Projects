#include <stdio.h>
#define MAX 1000

void reverse(int [], int );

int main()
{
  int arr[MAX],max,i, size;

  printf("Enter the size of the array: ");
  scanf("%d",&size);
    
  for(i=0;i<size;i++)
  {
     printf("Enter %d elements of an array: ", i+1);
     scanf("%d", &arr[i]);
  }
  reverse(arr, size);
  printf("\n");
  return 0;
}

void reverse(int arr[], int n)
{
  if(n == 0)
    return ;
  else
  {
    printf("%d\t", arr[n-1]);
    reverse(arr, n-1);
  }
}
/*
EXAMPLE
Enter the size of the array: 5
Enter 1 elements of an array: 6
Enter 2 elements of an array: 1
Enter 3 elements of an array: 2
Enter 4 elements of an array: 7
Enter 5 elements of an array: 3
3	7	2	1	6	
*/
