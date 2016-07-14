#include<stdio.h>
int sequential(int *arr,int n, int x)// array index starts from 0
{
 int count=1,index=0;
 while((index<n) && (arr[index]<x))
 {
   count++;
   index+=1;
 }
 if((index>=n)||(arr[index]!=x)) 
   index=0;
 return count;
}


int binary(int *arr,int n, int x)
{
 int count=0,first=0,last=n-1,mid;
 while(first<=last)
 {
   count++;
   mid=(first+last)/2;
   if(x<arr[mid])
     last=mid-1;
   else if(x>arr[mid])
     first=mid+1;
   else
     break;
 }
 return count;
}



int interpolation(int *arr,int n, int x)
{
 int count=1,index=0,first=0,last=n-1,mid;
 if((x<arr[first])||(x>arr[last]))
    return count;
 while((first<=last)&&((x>=arr[first])&&(x<=arr[last]))&&(index=0))
 {
  if(first==last)
    mid=first;
  else
    mid=first+((x-arr[first])/(arr[last]-arr[first])* (last-first));
  if(x==arr[mid])
    index=mid;
  else if(x<arr[mid])
    last=mid-1;
  else
    first=mid+1;
  count++;
 }
 return count;
}


int main()
{
 int i;
 int test[201];
 int list[100];
 int count[201][3];
 FILE *fp;
 fp=fopen("SearchPlot.txt","w");
 if(fp==NULL)
 {
   printf("file cannot be created\n");
 }
  
 for(i=0;i<201;i++)
    test[i]=(i+1)*5;
 for(i=0;i<100;i++)
    list[i]=(i+1)*10;
 

 for(i=0;i<201;i++)
 {
  count[i][0]=sequential(list,100,test[i]);
  count[i][1]=binary(list,100,test[i]);
  count[i][2]=interpolation(list,100,test[i]);
 }
 for(i=1;i<201;i++)
 {
   count[i][0]+=count[i-1][0];
   count[i][1]+=count[i-1][1];
   count[i][2]+=count[i-1][2];
 }
 int k = 5;
for(i=0;i<201;i++)
 {
  fprintf(fp,"%d\t%5d\t%5d\t%5d\n",k,count[i][0],count[i][1],count[i][2]);
  k = k+ 5;
 } 
 
 fclose(fp);
 return 0;
}
 
