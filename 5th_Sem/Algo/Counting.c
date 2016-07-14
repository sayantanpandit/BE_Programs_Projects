#include<stdio.h>
#define MAXSIZE 100

int Counting_sort(int arr[], int k, int n)
{
    int i, j;
    int brr[100], crr[100];
    for(i = 0; i <= k; i++)
            crr[i] = 0;
    for(j =1; j <= n; j++)
            crr[arr[j]] = crr[arr[j]] + 1;
    for(i = 1; i <= k; i++)
            crr[i] = crr[i] + crr[i-1];
    for(j = n; j >= 1; j--)
    {
            brr[crr[arr[j]]] = arr[j];
            crr[arr[j]] = crr[arr[j]] - 1;
    }
    printf("\nThe Sorted array is :\n");
    for(i = 1; i <= n; i++)
          printf("\t%d",brr[i]);
}
 
int main()
{
    int n,i,k = 0, arr[MAXSIZE];
    printf("Enter the number of input : ");
    scanf("%d",&n);
    printf("\nEnter the elements to be sorted :\n");
    for ( i = 1; i <= n; i++)
    {
         scanf("%d",&arr[i]);
         if(arr[i] > k)
         {
            k = arr[i];
         }
    }
    Counting_sort(arr, k, n);
    printf("\n");
}
