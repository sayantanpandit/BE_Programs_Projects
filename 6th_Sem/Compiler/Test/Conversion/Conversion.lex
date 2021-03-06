%{
   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   
   void lowToUp(char *);
   
   char oldText[100];
%}

%%
[a-zA-Z]*       { strcpy(oldText, yytext); lowToUp(oldText); }
%%

main(int argc, char *argv[])
{
   yylex();
}

int yywrap()
{ return 1; }


void lowToUp(char *word)
{
  int i;
  for(i=0; i<strlen(word); i++)
  {
     if(word[i]>=65 && word[i] <= 90)
        word[i]=word[i]+32;
     else if(word[i]>=97 && word[i] <= 122)
        word[i]=word[i]-32;
  }
  printf("\n\nAlternate Word :: %s\n", word);
}
