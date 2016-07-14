#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int insertionSort(int *, int );

int main()
{
  int noCase = 4;
  int testCase[4] = {10, 100, 1000, 10000};
  int *arr, i, j, size, count[4];
 
   FILE *fp; 
   fp = fopen("InsertionSort.txt", "w"); 
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
     
     count[i] = insertionSort(arr, size);
     fprintf(fp, "%d\t%d\t%d\n", (i+1), size, count[i]);
  }
  
  for(i=0; i<4; i++)
  {
     printf("%d\t%5d\t%5d\n", (i+1), testCase[i], count[i]);
  }
}

int insertionSort(int *arr, int size)
{
   int i, j, temp, count = 0;
    
   for(i=1; i<size; i++)
   {
      j=i;
      
      while(j>0 && arr[j]>arr[j-1])
      {
          temp     = arr[j];
          arr[j]   = arr[j-1];
          arr[j-1] = temp;
          
          j--;
          count++;
      }
   }
   return count;
}
