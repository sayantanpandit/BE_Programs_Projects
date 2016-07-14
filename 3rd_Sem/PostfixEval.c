#include<stdio.h>
#include<math.h>
#include<string.h>
float stack[100];
int top=-1;
void push(float );
float pop();

void main()
{
  int i = 0, j=0;
  char suffix[200];
  int opnd1, opnd2, step=0;
  system("clear");
  printf("Enter a valid Postfix expression :: ");
  gets(suffix);
  system("clear");
  printf("\nGiven Expression :: %s\n\n", suffix);
  for(j=0; j<80; j++)
     printf("-");
  printf("\n   Step   |   Symbol   |   Opnd1   |   Opnd2   |   Value   |      Stack   \n");
  for(j=0; j<80; j++)
     printf("-");

  while (suffix[i] != '\0')
  {
     printf("\n    %d", ++step);
     printf("\t\t%c", suffix[i]);
     if(isdigit(suffix[i]))
     { 
       printf("                                             ");
       push(suffix[i]-48);
     }
     else
     {
        opnd2 = pop();
        opnd1 = pop();
        printf("\t     %d\t        %d           ", opnd1,opnd2);
        switch(suffix[i])
        {
          case '+' : printf("%d         ", (opnd1+opnd2));
                     push(opnd1+opnd2);  
              break;
          case '-' : printf("%d         ", (opnd1-opnd2));
                     push(opnd1-opnd2);
              break;
          case '*' : printf("%d         ", (opnd1*opnd2));
                     push((opnd1*opnd2));
              break;
          case '/' : printf("%d         ", (opnd1/opnd2));
                     push((opnd1/opnd2));
              break;
          case '$' : printf("%d         ", (int)(pow(opnd1,opnd2)));
                     push((pow(opnd1,opnd2)));
              break;
        }    
     }  
     i++;
  }
  printf("\n\nThe result of %s = %d\n\n",suffix, (int)stack[0]);
}

void push(float num)
{
  int i = 0;
  top = top + 1;
  stack[top] = num;
  //For Displaying Stack Items...
  while(i < top)
  { 
    printf("%d, ", (int)stack[i]);
    i++;
  }
  if(i==top)
    printf("%d\n", (int)stack[top]);
  for(i=0; i<80; i++)
     printf("-"); 
}

float pop()
{
  float num;
  num = stack[top];
  int i = top;
  top = top - 1;
  return num; 
}
