#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int *, int ,int ,int , int *);
int partition(int *, int ,int , int *);

int main()
{
  int noCase = 4;
  int testCase[4] = {10, 100, 1000, 10000};
  int *arr, i, j, size, count[4];
  int countMerge = 0;
 
   FILE *fp;
   fp = fopen("MergeSort.txt","w");
   if(fp == NULL)
   {
      printf("File cannot be Created\n");
   }
   
  for(i=0; i<noCase; i++)
  {
     size = testCase[i];
     arr = (int *)malloc(size * sizeof(int));
     
     for(j=0; j<size; j++)
     {
        arr[j] = rand() % 10000;
     }
     
     partition(arr, 0, size-1, &countMerge);     
     count[i] = countMerge;
     
     fprintf(fp, "%d\t%d\t%d\n", (i+1), size, countMerge);
     //printf("%d\t%5d\t%5d\n", (i+1), testCase[i], count[i]);
  }
}

int partition(int *arr, int low, int high, int *countMerge)
{
   int mid;
   
   if(low<high)
   {
     mid = (low + high)/2;
     partition(arr, low, mid, countMerge);
     partition(arr, mid+1, high, countMerge);
     mergeSort(arr, low, mid, high, countMerge);
   }
}

void mergeSort(int *arr, int low, int mid, int high, int *countMerge)
{
   int i, j, m ,k , temp[high-low+1], count = 0;
   
   i = low;
   j = mid+1;
   k = 0;
   
   while((i <= mid) && (m <= high))
   {
      if(arr[i] <= arr[j])
      {
        temp[k++] = arr[i++];
      }
      else
      {
         temp[k++] = arr[j++];
      }
      (*countMerge)++;
   }   
   
   while(i <= mid)
   {
       temp[k++] = arr[i++];
       (*countMerge)++;
   }

   while(j <= high)
   {
       temp[k++] = arr[j++];
       (*countMerge)++;
   }
  
   k--;
   
   while(k >= 0)
   {
     arr[low + k] = temp[k];
     k--;
   }
   //return countMerge; 
}
