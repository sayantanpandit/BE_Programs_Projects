#include<stdio.h>
void HelloMan(int y)
{
  int x;
  int *p = NULL;
  x = 5;
  printf("Hii,Man... I am in Func...%d", y);
  scanf("%d",&x);
  
  if(x == 0)
      *p =  20;
  else
      printf("print\n");
  
}

int main()
{ 
  int arr[2], i=0, temp;
  for(i=0; i<5; i++)
  {
     arr[i] = i+1;
     temp = i+1;
  }
      
  HelloMan(20);
  for(i=0; i<10; i++)
    printf("%d\n", arr[i]);
  printf("Value printed :: %d\n", i);
}
