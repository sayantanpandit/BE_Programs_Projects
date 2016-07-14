#include <stdio.h> 
#include <string.h>
#define SIZE 50            

char s[SIZE];
int top = -1; 

void push(char );
char pop(); 
int  pr(char );
 
main() 
{ 
 char infx[50], pofx[50], ch, elem;
 int i = 0, j = 0, k = 0;
 system("clear");
 printf("Enter VALID Infix Expression :: ");
 scanf("%s", infx);
 push('#');
 for(j = 0; j<60; j++)
   printf("-");
  printf("\n");
 printf("  Step  |   Symbol  |    Stack   |   Postfix   \n");
 
 while ((ch = infx[i++]) != '\0') 
 {
  for(j = 0; j<60; j++)
    printf("-");
  printf("\n  %d", i);
  printf("\t     %c", ch);
   if (ch == '(')
     push(ch);
   else if (isalnum(ch))
   {
     pofx[k++] = ch;
     printf("                          %s\n",pofx);
   }
   else if (ch == ')') 
   {
    while (s[top] != '(')
      pofx[k++] = pop();
    printf("                          %s\n",pofx);
    elem = pop();
   } 
   else 
   { 
     while (pr(s[top]) >= pr(ch))
       pofx[k++] = pop();
     push(ch);
   }
 }
 while (s[top] != '#')
 {
   for(j = 0; j<60; j++)
     printf("-");
   printf("\n  %d", i);
   pofx[k++] = pop();
   printf("                                     %s\n",pofx);
 }
 
 for(j = 0; j<60; j++)
     printf("-");
 printf("\n");
 pofx[k] = '\0'; 
 printf("\nPostfix Expression :: %s\n\n", pofx);
}

void push(char elem) 
{ 
  s[++top] = elem;
  if(elem != '#')  
  printf("         %c\n", elem);
}
 
char pop() 
{ 
  return (s[top--]);
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

