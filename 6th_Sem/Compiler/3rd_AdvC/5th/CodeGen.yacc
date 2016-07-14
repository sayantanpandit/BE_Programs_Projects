%{
   #include<stdio.h>
   #include<ctype.h>
   #include<string.h>
   
   void ThreeAddressCode();
   void triple();
   void qudraple();
   char AddToTable(char ,char, char);   
   
   FILE *fout;
   
   int ind=0;
   char temp='A';
   struct incod
   {
     char opd1;
     char opd2;
     char opr;
   };
%}

%token<var> NAME PLUS EQUAL MULT DIVI SUBT 
%type<var> exp 

%left  SUBT PLUS
%right MULT DIVI

%union
{
  char var[10];
}

%start program

%%	
	
program : input
        ;
	
	
input: line'\n'input
     | '\n'input
     | /*empty*/
     ;
     
line:NAME EQUAL exp ';' {fprintf(fout,"MOV %s,AX\n",$1);}
    | exp ';'
    ;
    
exp: exp PLUS exp { fprintf(fout,"MOV AX,%s \nADD AX,%s\n",$1,$3); $$ = AddToTable((char )$1, (char )$3,'+'); }
   | exp SUBT exp { fprintf(fout,"MOV AX,%s \nSUB AX,%s\n",$1,$3); $$ = AddToTable((char )$1, (char )$3,'-'); }
   | exp MULT exp { fprintf(fout,"MOV AX,%s \nMUL AX,%s\n",$1,$3); $$ = AddToTable((char )$1, (char )$3,'*'); }
   | exp DIVI exp { fprintf(fout,"MOV AX,%s \nDIV AX,%s\n",$1,$3); $$ = AddToTable((char )$1, (char )$3,'/'); }
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


struct incod code[20];
int id=0;

char AddToTable(char opd1,char opd2,char opr)
{
   code[ind].opd1=opd1;
   code[ind].opd2=opd2;
   code[ind].opr=opr;
   ind++;
   temp++;
   return temp;
}

void ThreeAddressCode()
{
int cnt=0;
temp++;
printf("\n\n\t THREE ADDRESS CODE\n\n");
while(cnt<ind)
{
	printf("%c : = \t",temp);

	
        if(isalpha(code[cnt].opd1))
		printf("%c\t",code[cnt].opd1);
	else
		{printf("%c\t",temp);}

	printf("%c\t",code[cnt].opr);
	
	if(isalpha(code[cnt].opd2))
		printf("%c\t",code[cnt].opd2);
	else
		{printf("%c\t",temp);}

	printf("\n");
	cnt++;
	temp++;
}
}

