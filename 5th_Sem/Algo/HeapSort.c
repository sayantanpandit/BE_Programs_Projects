#include<stdio.h>
#include<stdlib.h>

void swap(int *, int *);
void heapSort(int *, int ,int *);
void buildHeap(int *, int ,int *);
void Heapify(int *,int ,int ,int *);

int main()
{
   int i,j, size, noCase = 8;
   int testcase[8] = {10, 100, 1000, 2000, 4000, 6000, 8000, 10000};
   int *arr;
   int count=0;

   FILE *fp; 
   fp = fopen("HeapSort.txt", "w"); 
   if(fp == NULL)
   {
     printf("File Cannot be Created\n");
   }

   for(i=0; i<noCase; i++)
   {
     size = testcase[i]; 
     arr = (int *)malloc(size * sizeof(int));

     for(j=0; j<size; j++)
     {
        arr[j] = rand() % 1000;
     }
     
     heapSort(arr, size-1,  &count);
       
     fprintf(fp, "%d\t%d\n", size, count);
     printf("%d\t%d\n", size, count);
   }   
}

void swap(int *a, int *b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp; 
}

void heapSort(int arr[], int n, int *count)
{
  int i;
  buildHeap(arr,n, count);
 
  for(i=n; i>0; i--)
  {
      swap(&arr[0], &arr[i]);
      Heapify(arr, 0, i-1, count);
  }
}

void buildHeap(int arr[] ,int n, int *count)
{
   int i;
  // printf("BuildHeap Count = %d\n", count);
   for(i=((n/2); i>=0; i--)
         Heapify(arr, i, n, count);
}

void Heapify(int arr[], int i, int n, int *count)
{
   int l = 2*i+1;
   int r = 2*i+2;
   int largest;

   if((l<=n) && (arr[l] > arr[i]))
   {
      largest = l;
      (*count)++;
    // printf("Heap Count1 = %d\n", *count);
   }
   else
      largest = i;

   if((r<=n) && (arr[r] > arr[largest]))
   {
      largest = r;
      (*count)++;
       //printf("Heap Count2 = %d\n", *count);
   }
   if(i != largest)
   {
        swap(&arr[i], &arr[largest]);
        Heapify(arr, largest, n, count);
   }
}
