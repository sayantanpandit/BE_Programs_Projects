#include<stdio.h>
#define MAX 100

int LargestNo(int [], int);
int max(int , int);

int main(){

    int arr[MAX],max,i, size;

    printf("Enter the size of the array: ");
    scanf("%d",&size);
    
    for(i=0;i<size;i++)
    {
      printf("Enter %d elements of an array: ", i+1);
      scanf("%d", &arr[i]);
    }

    max = LargestNo(arr, size);
    printf("Largest element of an array is: %d\n",max);

    return 0;
}

int LargestNo(int* arr, int size)
{   
    if(size == 1)
       return arr[0]; 
    else
       return max(LargestNo(arr, size-1), arr[size-1]);
}

int max(int n1, int n2)
{
  return n1 > n2 ? n1: n2;
}
