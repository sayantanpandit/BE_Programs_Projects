%option noyywrap
%{ 
   char test='s';
%}

%%
(""[aA][nN][dD]"")|(""[oO][rR]"")|(""[bB][uU][tT]"") { test='c'; }
.                                                    {;}
\n                                                   { return 0; }
%%
main()
{
   yylex();
   if(test == 's')
      printf("\n Its a simple sentence\n");
   else if(test == 'c')
      printf("\n This is compound sentence\n");
}
