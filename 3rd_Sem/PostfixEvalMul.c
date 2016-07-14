#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 30
typedef struct
{
    int top;
    int arr[SIZE];
}stack;
int push(int, stack*);
int pop(stack*);
int solve(char[]);
int flag = 0,num;

int main()
{
	int i=0, j=0;
	char inp[SIZE];
        system("clear");
    	printf("Enter a postfix expression :: ");
        
	while((inp[i++]=getchar())!='\n');
	inp[i-1]='\0';	
        printf("\n\nGiven Postfix Expression :: %s\n", inp);
        for(j=0; j<90; j++)
           printf("-");
        printf("\n  Steps  |    Symbol    |     Opnd1    |     Opnd2    |    Value     |       Stack   \n");  
	for(j=0; j<90; j++)
           printf("-");
  	printf("\n\nThe ans is: %d\n\n",solve(inp));
	return 0;
}	
int solve(char arr[])
{
    int i=0,j,v1,v2, k = 0, l = 0, neg=0;
    stack stk;	
    stk.top=-1;
	
    while(arr[i])
    {
     
	if(arr[i]==' ')	
        {
           i++;	
           continue;
        }
        num=0;
    	if((arr[i]>='0' && arr[i]<='9') || ((arr[i]=='-') && (arr[i+1] >= '0' && arr[i+1]<= '9')))  
	{
          printf("\n     %d", (++l));
     //Checking whether the no. is Negative or not...
          if(arr[i] == '-')
          {
            neg = 1;
            i++;
          }
     //For Making Single Digit to Multiple Digits...
	  for(j=i;arr[j]>='0' && arr[j]<='9';j++)	
          { 
             num*=10; 
             num=num+arr[j]-'0';
          }
          if(neg)
             num = -num;   //If the no. is negative, convert into negative by putting '-' sign before it.
          printf("         %d",num);
	  push(num,&stk);
	  i=j, neg = 0;
	}
        else
            {
                printf("\n     %d",(++l));
                printf("         %c",arr[i]);
                v2=pop(&stk); // Popping out the last element
                v1=pop(&stk); // Popping out the 2nd last element
                printf("               %d                %d              ",v2, v1);
                switch(arr[i])
                {
                    case '+': printf("%d", (v2+v1));
                              flag = 1;
                              push(v2+v1,&stk);
                              break;
                    case '-': printf("%d", (v2-v1));
                              flag = 1;
                              push(v2-v1,&stk);
                              break;
                    case '*': printf("%d",  (v2*v1));
                              flag = 1;    
                              push(v2*v1,&stk);
                              break;
                    case '/': printf("%d",   (v2/v1));
                              flag = 1;
                              push(v2/v1,&stk);
                              break;
		    case '^':
		    case '$': printf("%d",  (int)(pow(v2,v1)));
                              flag = 1;
                              push(pow(v2,v1),&stk);
                              break;
                    default: {printf("Invalid operator!"); 
                             return 1;}
                }
            }
	i++;
      }
    return pop(&stk);
}

int push(int c,stack *s)
{
    int i = 0;
    if(s->top<SIZE)    
    {
      s->arr[++s->top]=c;    
      //return 1; 

   //For Displaying in a Fashion Way...
    if(flag == 1)
    {
       printf("          ");
       flag = 0;
    }
    else
       printf("                                                          ");
    while(i < s->top)
    { 
      printf("%d, ", s->arr[i]);
      i++;
    }

    if(i==s->top)
      printf("%d\n", s->arr[i]);
    for(i=0; i<90; i++)
      printf("-");
    return 1;
    }  
    return 0;
}

int pop(stack *s)
{
	if(s->top>=0)  
           return s->arr[s->top--];
    	return 0; 
}
