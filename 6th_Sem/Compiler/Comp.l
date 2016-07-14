%{
%}
digit  [0-9]+
delim  [ \t\n]
ws     {delim}*
%%

auto      	{ printf("AUTO\n");  }
break     	{ printf("BREAK\n"); }
case      	{ printf("CASE\n");  }
char      	{ printf("CHAR\n");  }
const     	{ printf("CONST\n"); }
continue  	{ printf("CONTINUE\n"); }
default   	{ printf("DEFAULT\n");	}
do        	{ printf("DO\n"); }
double          { printf("DOUBLE\n"); }
else            { printf("ELSE\n"); }
enum            { printf("ENUM\n"); }
extern          { printf("EXTERN\n"); }
exit            { return 0; }
float           { printf("FLOAT\n"); }
for             { printf("FOR\n"); }
goto            { printf("GOTO\n"); }
if              { printf("IF\n"); }
int		{ printf("INT\n"); }
long		{ printf("LONG\n"); }
register	{ printf("REGISTER\n"); }	
return		{ printf("RETURN\n"); }
short		{ printf("SHORT\n"); }
signed		{ printf("SIGNED\n"); }
sizeof		{ printf("SIZEOF\n"); }
static		{ printf("STATIC\n"); }
struct		{ printf("STRUCT\n"); }
switch		{ printf("SWITCH\n"); }
typedef		{ printf("TYPEDEF\n"); }
union		{ printf("UNION\n"); }
unsigned	{ printf("UNSIGNED\n"); }
void		{ printf("VOID\n"); }
volatile	{ printf("VOLATILE\n"); }
while		{ printf("WHILE\n"); }


{digit}         { printf("Number\n");}
[a-zA-Z]*       { printf("Word\n");}
{ws}            { /*No action and no return*/}

"<"       { printf("Less Than\n"); }
"<="      { printf("Less Than or Equal\n"); }
"="       { printf("Equal\n"); }
"<>"      { printf("Not Equal\n"); }
">"       { printf("Greater Than\n"); }
">="      { printf("Greater Than or Equal\n"); }

%%

main()
{
  yylex();
}
yywrap()
{}                                                                                                                                               
