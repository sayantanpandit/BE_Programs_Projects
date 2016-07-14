#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int selectionSort(int *, int );

int main()
{
  int noCase = 4;
  int testCase[4] = {10, 100, 1000, 10000};
  int *arr, i, j, size, count[4];
 
  FILE *fp; 
  fp = fopen("SelectionSort.txt", "w"); 
  if(fp == NULL)
  {
    printf("File Cannot be Created\n");
  }
 
  for(i=0; i<noCase; i++)
  {
     size = testCase[i];
     arr = (int *)malloc(size * sizeof(int));
     
     for(j=0; j<size; j++)
     {
        arr[j] = rand() % 10000;
     }
     
     count[i] = selectionSort(arr, size);
     fprintf(fp, "%d\t%d\t%d\n", (i+1),size, count[i]);
     printf("%d\t%5d\t%5d\n", (i+1), testCase[i], count[i]);
  }
}

int selectionSort(int *arr, int size)
{
   int i, j, temp, position, count = 0; 
   
   for(i=0; i<(size-1); i++)
   {
     position = i;
     for(j=i+1; j<size; j++)
     {
        if(arr[position] > arr[j])
          position = j;
        count++;
     }
     if(position != i)
     {
       temp   	     = arr[i];
       arr[i]        = arr[position];
       arr[position] = temp;
     }
   }
   return count;
}
