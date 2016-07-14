#include<stdio.h>

int count=0;
int main()
{
 int t,n,c=0,min,max,p,i;
 int arr[100],large[100],small[100];
 printf("Enter No. :: ");
 scanf("%d", &n);
  for(i=0;i<n;i++)
  { 
   printf("Enter No.%d :: ", (i+1));
   scanf("%d",&arr[i]);
  }
  if(n%2 == 0)
  { 
   for(i=0; i<n-1; i+=2)
   {
    count++;
    if(arr[i]>arr[i+1])
     {
      large[c]=arr[i];
      small[c]=arr[i+1];
     }
     else
     {
        large[c]=arr[i+1];
         small[c]=arr[i];
     }
      c++;
     }
    }
    else
    {
         for(i=0;i<n-2;i+=2)
         {
          count++;
          if(arr[i]>arr[i+1])
           {  
            large[c]=arr[i];
            small[c]=arr[i+1];
           }
           else
           {
            large[c]=arr[i+1];
            small[c]=arr[i];
           }
           c++;
          }
           large[c]=arr[n-1];
           small[c]=arr[n-1];
           c=c+1;
          
         }
 while(c!=1)
{
  t=0;
 if(c%2==0)
  {
   
   for(i=0;i<c-1;i+=2)
    {
     count+=2;
     if(small[i]<small[i+1])
     {
      small[t]=small[i];
     }
     else
      small[t]=small[i+1];
     if(large[i]>large[i+1])
      {
      large[t]=large[i];
      }
     else
      large[t]=large[i+1];
     t++;
    }
    c=t;
   }
   else   
  {
  
   for(i=0;i<c-2;i+=2)
    {
    count+=2;
     if(small[i]<small[i+1])
     {
      small[t]=small[i];
     }
     else
      small[t]=small[i+1];
     if(large[i]>large[i+1])
      {
       large[t]=large[i];
      }
     else
      large[t]=large[i+1];
     t++;
    }
     small[t]=small[c-1];
     large[t]=large[c-1];
     c = t+1;
  }
}
   min = small[0];
   max = large[0];
   printf("\n Minimum  :: %d",min);
   printf("\n Maximum  :: %d",max);
   printf("\n Compare  :: %d\n", count);     
   return 0;
}
