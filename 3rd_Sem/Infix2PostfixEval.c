#include<stdio.h>
#include<math.h>
#include<string.h>
#define SIZE 50
char  operator[SIZE];
float operand[SIZE];
int top1 = -1, top2 = -1;
void pushoperator(char );
char popoperator();
void pushoperand(float );
float popoperand();
int pr(char );
int flag = 0;
void eval();

int main()
{
  char infix[50], postfix[50], ch, elem;
  int i = 0, j = 0, k = 0, opnd1 = 0, opnd2 = 0;
  printf("\nEnter the VALID Infix Expression :: ");
  scanf("%s", infix);
  system("clear");
  pushoperator('#');
  printf("Given the Infix Expression :: %s\n\n", infix);
  for(j=0; j<80; j++)
     printf("-");
  printf("\n Step |  Symbol  |   Operator   |  Opnd1  |  Opnd2  |   Value  |   Operand    \n");
  
  while((ch=infix[i++]) != '\0')
  {
   for(j=0; j<80; j++)
     printf("-");
   printf("\n  %d ", i);
   printf("       %c ", ch); 
    if(ch == '(')
      pushoperator(ch);
    else if(isdigit(ch))
      pushoperand((ch-48));
    else if(ch == ')')
    {
       while(operator[top1] != '(')
           eval();
       elem = popoperator();
    }
    else
    {
     while(pr(operator[top1]) >= pr(ch))
        eval(); 
     pushoperator(ch);
    }
    printf("\n");
  }
  while(operator[top1] != '#')
  {
    for(j=0; j<80; j++)
     printf("-");
    printf("\n  %d ", i++);
    eval();
    printf("\n");   
  }      
   for(j=0; j<80; j++)
     printf("-");
   elem = popoperator();
   printf("\n\nOutput :: %d\n", (int)operand[0]);
  
 /* if(top1 == 0 && top2 == 0)
     printf("Invalid Expression\n");
  else
     printf("Output :: %f\n", operand[0]); */
}

void pushoperator(char elem) 
{
 int i = 1; 
 operator[++top1] = elem;
 printf("        ");
 while(i < top1)
   printf("%c, ", operator[i++]);
 if(i==top1)
   printf("%c  ", operator[i++]);
}
char popoperator() 
{ 
  return (operator[top1--]);
}
void pushoperand(float elem) 
{ 
  int i = 0;
  operand[++top2] = elem;
  if(flag == 1)
  {
    printf("        ");
    flag = 0;
  }
  else
    printf("                                                      ");
  while(i < top2)
    printf("%d, ", (int)operand[i++]);
  if(i == top2)
    printf("%d  ", (int)operand[i++]);
}
float popoperand() 
{ 
  return (operand[top2--]);
}

int pr(char elem) 
{ 
 switch (elem) 
 {
  case '#':
    return 0;
  case '(':
    return 1;
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
   return 3;
 }
}

void eval()
{
        char ch1 = popoperator();
        int opnd2 = popoperand();
        int opnd1 = popoperand();
        printf("\t\t\t     %d          %d\t  ",opnd1, opnd2);
        switch(ch1)
        {
         case '+' : printf("%d",(opnd1+opnd2));
                    flag = 1;
                    pushoperand(opnd1+opnd2);
                    break;
	 case '-' : printf("%d",(opnd1-opnd2));
                    flag = 1;
                    pushoperand(opnd1-opnd2);
	            break;
	 case '*' : printf("%d",(opnd1*opnd2));
                    flag = 1;
                    pushoperand(opnd1*opnd2);
		    break;
	 case '/' : printf("%d",(opnd1/opnd2));
                    flag = 1;
                    pushoperand(opnd1/opnd2);
		    break;
         case '$' : printf("%d", (int)(pow(opnd1,opnd2)));
                    flag = 1;
                    pushoperand(pow(opnd1,opnd2));
                    break;
         } 
}
