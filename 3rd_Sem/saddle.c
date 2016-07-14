#include<stdio.h>

int main()
{
  int arr[20][20];
  int rmin[20], rmax[20], cmin[20], cmax[20];
  int i,j,flag = 0, n;

  printf("Enter square matrix of :: ");
  scanf("%d", &n);

  //Taking input from user
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      printf("arr[%d][%d] :: ",i,j);
      scanf("%d", &arr[i][j]);
    }
  }
  
  //Calculation
  for(i=0; i<n; i++)
  {
    rmin[i] = arr[i][0];
    rmax[i] = arr[i][0];
    cmin[i] = arr[0][i];
    cmax[i] = arr[0][i];   
  
   for(j=0; j<n; j++)
   {
     if(rmin[i] > arr[i][j])
       rmin[i] = arr[i][j];
     if(rmax[i] < arr[i][j])
       rmax[i] = arr[i][j];
     if(cmin[i] > arr[j][i])
       cmin[i] = arr[j][i];
     if(cmax[i] < arr[j][i])
       cmax[i] = arr[j][i];
   }
  } 
  
  //For Displaying the Matrix in a fashion way
  printf("\nThe Given Matrix -->");
  for(i=0; i<n; i++)
  {
    printf("\n    ");
    for(j=0; j<n; j++)
       printf(" %d ",arr[i][j]);
  }
 
  //For Displaying Saddle Point
  for(i=0; i<n; i++)
  {
   for(j=0; j<n; j++)
   { 
     if(rmax[i] == cmin[j])
     {
       if(flag == 0)
          printf("\nSaddle Point ---> \n");
       printf("arr[%d,%d] :: %d\n", (i+1),(j+1), rmax[i]);
       flag = flag + 1;
     }
     if(rmin[i] == cmax[j])
     {
       if(flag == 0)
          printf("\nSaddle Point ---> \n");
       printf("arr[%d,%d] :: %d\n", (i+1),(j+1), rmin[i]);
       flag = flag + 1;
     }
   }
  }
  if(flag == 0)
     printf("\nNo Saddle Point exists...\n\n");
}
