%{
	#define TABLE_SIZE 100
	#define ID_SIZE 20
	int keywd_id(char arr[]);
	int insert(char hash[][ID_SIZE],char *str,int key);
%}

delim [ \t\n]
ws {delim}+
letter [a-zA-Z]
digit [0-9]
number {digit}+
alpha [a-zA-Z0-9_]

%%

{ws} ;

if	printf("IF");
else	printf("ELSE");
while	printf("WHILE");
for	printf("FOR");
break	printf("BREAK");
continue	printf("CONTINUE");
return	printf("RETURN");
auto	printf("AUTO");
case	printf("CASE");
char	printf("CHAR");
const	printf("CONST");
default	printf("DEFAULT");
do	{printf("DO");}
double	{printf("DOUBLE");}
enum	{printf("ENUM");}
extern	{printf("EXTERN");}
float	{printf("FLOAT");}
goto	{printf("GOTO");}
long	{printf("LONG");}
register	{printf("REGISTER");}
short	{printf("SHORT");}
signed	{printf("SIGNED");}
sizeof	{printf("SIZEOF");}
static	{printf("STATIC");}
struct	{printf("STRUCT");}
switch	{printf("SWITCH");}
typedef	{printf("TYPEDEF");}
union	{printf("UNION");}
unsigned	{printf("UNSIGNED");}
d	{printf("VOID");}
volatile	{printf("VOLATILE");}

"<" {printf("LT");}
"<=" {printf("LE");}
">" {printf("GT");}
">=" {printf("GE");}
"==" {printf("EQ");}
"!=" {printf("NE");}
"!"	{printf("NOT");}
"=" {printf("ASSIGNED_TO");}
"+=" {printf("PLUS_EQ");}
"-=" {printf("MINUS_EQ");}
"*=" {printf("MULT_EQ");}
"/=" {printf("DIV_EQ");}
"%=" {printf("MOD_EQ");}

"+" printf("PLUS");
"-" printf("MINUS");
"*" printf("MULT");
"/" printf("DIV");
"%" printf("MOD");
";" printf("<;>");
"," printf("<,>");
"(" printf("<(>");
")" printf("<)>");
"[" printf("<[>");
"]" printf("<]>");

{letter}{alpha}* {int a; a=keywd_id(yytext); if(a!=0)printf("<ID%d>",a);}
{number} printf("<NUMBER%s>",yytext);

%%

char symbolTable[TABLE_SIZE][ID_SIZE];
int i=0,j=0,k=0;
int symtab[100];
char arr1[10];
main(){
for(i=0;i<TABLE_SIZE;i++) strcpy(symbolTable[i],"EMP");
	yylex();
}
int insert(char hash[][ID_SIZE],char *arr,int key)
{
	int c=0;
k++;
char arr2[10];
arr2[0]='\0';
	while(1)
	{
		c++;
		if(c==TABLE_SIZE) return -1;
		if(strcmp(hash[key],"EMP")==0 || strcmp(hash[key],arr)==0)
		{
			strcpy(arr2,arr1);
			strcat(arr2,arr);
			//strcpy(arr2,arr1);
			strcpy(hash[key],arr2);
symtab[k]=key;			
printf("SYMBOl TABLE");
for(j=0;j<=k;j++)
{
printf("%s\n",hash[symtab[j]]);
}
//printf("%s",hash[key]);			
return key;
}
//printf("%s",hash[key]);
		key=(key+1)%TABLE_SIZE;
	}
}
int keywd_id(char arr[]){
//printf("the word received: %s",arr);
	int i;
	int key=0;
	for(i=0;i<strlen(arr);i++) key=key+(arr[i]);
	key=key%TABLE_SIZE;
if(strcmp(arr,"int")==0)
{
strcpy(arr1,arr);
strcat(arr1," ");
return 0;
}
	int ret=insert(symbolTable,arr,key);
	//printf("%s\t%d\n",arr,ret);
	return ret;
}

yywrap(){

}












