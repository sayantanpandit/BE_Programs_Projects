%{
   #include <string.h>
   #include <stdio.h>
   #include <stdlib.h>
   
   #include "y.tab.h"
   #define COPY_STRING { yylval.id=(char *)malloc((yyleng+1)*(sizeof(char))); strncpy(yylval.id, yytext, yyleng+1); }
   
%}

digit  [0-9]+
delim  [ \t]
ws     {delim}*

%%
auto      	{ return (AUTO);  }
break     	{ return (BREAK); }
case      	{ return (CASE);  }
char      	{ COPY_STRING return (CHAR);     }
const     	{ return (CONST); }
continue  	{ return (CONTINUE); }
default   	{ return (DEFAULT);	}
do        	{ return (DO); }
double          { return (DOUBLE);   }
else            { return (ELSE); }
enum            { return (ENUM); }
extern          { return (EXTERN); }
exit            { return 0; }
float           { return (FLOAT);   }
for             { return (FOR);  }
goto            { return (GOTO); }
if              { return (IF); }
int		{ COPY_STRING return (INT);   }
long		{ return (LONG);  }
main		{ return (IDENTIFIER); }
register	{ return (REGISTER); }
return		{ return (RETURN); }
short		{ return (SHORT); }
signed		{ return (SIGNED); }
sizeof		{ return (SIZEOF); }
static		{ return (STATIC); }
struct		{ return (STRUCT); }
switch		{ return (SWITCH); }
typedef		{ return (TYPEDEF); }
union		{ return (UNION); }
unsigned	{ return (UNSIGNED); }
void		{ return (VOID); }
volatile	{ return (VOLATILE); }
while		{ return (WHILE); }

"+" 		{ return (PLUS); }
"-" 		{ return (MINUS); }
"*" 		{ return (MULT); }
"/"  		{ return (DIVIDE); }

"<" 		{ return (LESS); }
"<=" 		{ return (LESS_EQ); }
">" 		{ return (GREATER); }
">=" 		{ return (GREATER_EQ); }
"==" 		{ return (EQUAL); }
"!=" 		{ return (NOT_EQ); }
"!"		{ return (NOT); }
"=" 		{ return (ASSIGN); }
"+=" 		{ return (PLUS_EQ); }
"-=" 		{ return (MINUS_EQ); }
"*=" 		{ return (MULT_EQ); }
"/=" 		{ return (DIV_EQ); }

"(" 		{ return (LEFT_PAREN); }
")" 		{ return (RIGHT_PAREN); }
"[" 		{ return (LEFT_SQ_BRACKET); }
"]" 		{ return (RIGHT_SQ_BRACKET); }
"{" 		{ return (LEFT_CURLY); }
"}" 		{ return (RIGHT_CURLY); }

"," 		{ return (COMMA); }
"_"		{ return (UNDERSCORE);}
";"		{ return (SEMICOLON); }

"\n" 		{ /*printf("\n"); */}

{digit}                { COPY_STRING return (CONSTANT);    }
[a-zA-Z][a-zA-Z0-9]*   { COPY_STRING return (IDENTIFIER);  }
{ws}            { /*No action and no return*/ }
[-#<>{}=+*/.]   { printf("DELIM"); }

%%
