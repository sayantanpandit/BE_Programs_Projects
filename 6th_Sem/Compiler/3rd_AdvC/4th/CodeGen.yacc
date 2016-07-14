%{
   #include<stdio.h>
   #include<ctype.h>
   #include<string.h>
   FILE *fout;
%}

%token<var> NAME PLUS EQUAL MULT DIVI SUBT 
%type<var> exp 

%union
{
  char var[10];
}

%right EQUAL
%left PLUS SUNT
%left MULT DIVI

%start program

%%	
	
program : input
        ;
	
	
input: line'\n'input
     | '\n'input
     | /*empty*/
     ;
     
line:NAME EQUAL exp {fprintf(fout,"MOV %s,AX\n",$1);  }
    ;
    
exp: NAME PLUS NAME { fprintf(fout,"MOV AX,%s \nADD AX,%s\n",$1,$3); }
   | NAME SUBT NAME { fprintf(fout,"MOV AX,%s \nSUB AX,%s\n",$1,$3); }
   | NAME MULT NAME { fprintf(fout,"MOV AX,%s \nMUL AX,%s\n",$1,$3); }
   | NAME DIVI NAME { fprintf(fout,"MOV AX,%s \nDIV AX,%s\n",$1,$3); }
   | NAME  	    { strcpy($$,$1);}
   ;
%%

extern yylineno;

yyerror()
{ printf("\nerror %d",yylineno); }

yywrap()
{ return 1; }

extern FILE *yyin;

main()
{
  FILE *fin;
  fin  = fopen("main","r");
  fout = fopen("out.txt","w");

  yyin=fin;

   yyparse();
   fcloseall();	 
   system("cat out.txt");
   return 0;   
}
