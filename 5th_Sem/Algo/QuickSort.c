#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void partitionQuick(int *,int ,int ,int *);
int quickSort(int *,int ,int ,int *);

int main()
{
  int noCase = 4;
  int testCase[4] = {10, 100, 1000, 10000};
  int *arr, i, j, size, count[4];
  //int countQuick = 0;

   FILE *fp; 
   fp = fopen("QuickSort.txt", "w"); 
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
     int countQuick = 0;
     partitionQuick(arr, 0, size-1, &countQuick);
     count[i] =  countQuick;
     
     fprintf(fp, "%d\t%d\t%d\n", (i+1), size, countQuick);
     //printf("%d\t%5d\t%5d\n", (i+1), testCase[i], count[i]);
  }
  
  for(i=0; i<4; i++)
  {
     printf("%d\t%5d\t%5d\n", (i+1), testCase[i], count[i]);
  }
}

void partitionQuick(int *arr, int lb, int ub, int *count)
{
	int pivotPos;
	if(lb < ub)
	{
		pivotPos = quickSort(arr,lb,ub, count);
		partitionQuick(arr,lb,pivotPos-1, count);
		partitionQuick(arr,pivotPos+1,ub, count);
	}
}

int quickSort(int *arr, int lb, int ub, int *count)
{
        int pivot = arr[lb], down=lb, up=ub, temp, j;
	while(up>down)
	{
	   while((arr[down]<=pivot) && (down<up))
	   {	
               down = down+1;
           }
	   while(arr[up]>pivot)
	   {	
               up = up-1;
           }
	  if(up > down)
	  {
             temp      = arr[down];
	     arr[down] = arr[up];
	     arr[up]   = temp;
	  }
	  (*count)++;
        }
     
	temp    = arr[lb];
	arr[lb] = arr[up];
	arr[up] = temp;
	j = up;
	return j;
}
