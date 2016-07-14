%{

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

FILE *fout;
  
int SumOfAscii(char *word);  
void chkVariable(char *);
int  chkExpVar(char *);
void display();
void insertToHash(int id, int key, char *name, char *type, int *loc, int size);
int searchInHash(int key);

char* InterCode(char *, char *, char );
void ThreeAddressCode();


struct hash *hashTable = NULL;
struct node
{
      int id, key, size, location;      
      char varName[100];
      char dataType[100];
      struct node *next;
};

struct hash
{
   struct node *head;
   int count;
};
int eleCount = 10;

struct node *createNode(int id, int key, char *name, char *type, int *loc, int size)
{
   struct node *newnode;
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->id  = id;
   newnode->key  = key;
   strcpy(newnode->varName, name);
   strcpy(newnode->dataType, type);
   newnode->location = *loc;
   newnode->size = size;
   newnode->next = NULL;
   return newnode;
};
    
int ind=0; 
char *temp;

struct incod
{
    char *opd1;
    char *opd2;
    char opr;
};    
    
        
char localName[100], type[100];   
int count = 0, loc, size, arrSize;   

extern int yylineno, yychar;

%}


%union{
    char* id;
    char* string;
}

%token<string> AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN
%token<string> FLOAT FOR GOTO IF INT LONG  REGISTER RETURN SHORT SIGNED SIZEOF STATIC STRUCT
%token<string> SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE

%token PLUS MINUS MULT DIVIDE

%token LESS LESS_EQ GREATER GREATER_EQ EQUAL NOT_EQ NOT  PLUS_EQ MINUS_EQ MULT_EQ DIV_EQ
 
%token LEFT_PAREN RIGHT_PAREN LEFT_SQ_BRACKET RIGHT_SQ_BRACKET LEFT_CURLY RIGHT_CURLY 
%token<string> COMMA UNDERSCORE SEMICOLON CONSTANT IDENTIFIER

%type<string>  datatype idenList term exp

%left PLUS MINUS 
%right ASSIGN MULT DIVIDE

%start program

%%

program 
    : statement    
    ;
     
statement
    :
    | line';'statement       
    | ';'statement           
    ;
    
line 
    : datatype idenList     { strcpy(type, ""); }
    | term '=' exp          { InterCode((char *)$1, (char *)$3, '='); fprintf(fout,"MOV %s, %s\n",$1, $3); }
    | exp		    
    | idenList 
    ;
     
datatype
    : CHAR     { printf("CHAR\t");   strcpy(type, $1); size = 1; }
    | DOUBLE   { printf("DOUBLE\t"); strcpy(type, $1); size = 8; }
    | INT      { printf("INT\t");    strcpy(type, $1); size = 4; }
    | LONG     { printf("LONG\t");   strcpy(type, $1); size = 4; }
    | FLOAT    { printf("FLOAT\t");  strcpy(type, $1); size = 4; } 
    | SHORT    { printf("SHORT\t");  strcpy(type, $1); size = 2;}     
    ; 
    
idenList 
    : IDENTIFIER 		{ count++; chkVariable($1);  }
    | idenList ',' IDENTIFIER   { count++; chkVariable($3);  }
    ;          

exp : exp PLUS   exp	{ $$ = InterCode((char *)$1, (char *)$3, '+'); fprintf(fout,"MOV %s,%s \nADD %s,%s\n", $$,$1,$$,$3); }
    | exp MINUS  exp	{ $$ = InterCode((char *)$1, (char *)$3, '-'); fprintf(fout,"MOV %s,%s \nSUB %s,%s\n", $$,$1,$$,$3); }
    | exp MULT   exp	{ $$ = InterCode((char *)$1, (char *)$3, '*'); fprintf(fout,"MOV %s,%s \nMUL %s,%s\n", $$,$1,$$,$3); }
    | exp DIVIDE exp	{ $$ = InterCode((char *)$1, (char *)$3, '/'); fprintf(fout,"MOV %s,%s \nDIV %s,%s\n", $$,$1,$$,$3); }
    | term		{ /*printf("term : %s\n", $1);*/ strcpy($$, $1);   }
    ;
    
term : IDENTIFIER        { if(chkExpVar($1)==1) { strcpy($$, $1); } else { printf("\n%s :: Variable not Declared.\n", $1); }  }
     | CONSTANT   	 { strcpy($$, $1);  }
     ;
%%

extern FILE *yyin;

main()
{
    //FILE *fin;
   // fin  = fopen("main","r");
    fout = fopen("out.txt","w");
    //yyin=fin;
    
    hashTable = (struct hash *)calloc(eleCount, sizeof(struct hash));
    //temp = "A";    
    yyparse();  
  
    display();

    //temp="A";
    ThreeAddressCode();

   // printf("\nNo. of Identifers = %d\n", count);
    fcloseall();
    
    printf("\nCODE GENERATION\n\n");	 
    system("cat out.txt");
    return 0;
}

yyerror(s)
char *s;
{ 
     fprintf(stderr, "%s: token %d on line %d\n", s, yychar, yylineno);
}

yywrap()
{ return 1; }

int SumOfAscii(char *word)
{
   int i, sum=0;
   for(i=0; i<strlen(word); i++)
       sum = sum + word[i];
   return sum;
}

void chkVariable(char *variableName)
{
    int key = SumOfAscii(variableName);  
    int chkKey = searchInHash(key);
                  
    if(strcmp(type, "") == 0 /*&& strcmp(variableName, "main") != 0*/)
    { 
         printf("\nInvalid Datatype\n"); 
         //exit(1); 
    }
    if((chkKey == 0 || chkKey == -1) && strcmp(type, "") != 0)
    {
	insertToHash(count, key, variableName, type, &key, size); 
    }
    else if(chkKey == 1)
    { 
	 printf("\n\n\t%s --> Variable Already exists\n", variableName);  
	// exit(1);
    }
}

void insertToHash(int count, int key, char *name, char *type, int *loc, int size)
{   
   int hashIndex = key % eleCount;
   struct node *newnode = createNode(count, key, name, type, loc, size);
   if(!hashTable[hashIndex].head)
   {
         hashTable[hashIndex].head  = newnode;
         hashTable[hashIndex].count = 1;
         return;
   }
   newnode->next = (hashTable[hashIndex].head);
   hashTable[hashIndex].head = newnode;
   hashTable[hashIndex].count++;
   return;
}

int searchInHash(int key) 
{
   int hashIndex = key % eleCount, flag = 0;
   struct node *myNode;
   myNode = hashTable[hashIndex].head;   
      
   if (!myNode) 
   {
      return -1;         //When Start Node is not created...Search element unavailable in hash table
   }
   while (myNode != NULL) 
   {
      if (myNode->key == key) 
      {                        
         flag = 1;
         return 1;
      }
      myNode = myNode->next;
   }
   if (!flag)
     return 0; //Search element unavailable in hash table...Not Flag;
}

int chkExpVar(char *variableName)
{ 
    int key = SumOfAscii(variableName);  
    int chkKey = searchInHash(key);
                  
    if((chkKey == 0 || chkKey == -1) && strcmp(type, "") != 0)
    {
	return 0;
    }
    else if(chkKey == 1)
    { 
          return 1;
	// exit(1);
    }
   
}

void display()
{
    printf("\nSYMBOL TABLE\n");
    printf("----------------------------------------------------------------------------\n");
    printf("   ID\tVar Name\tDatatype\tSize\tRel. Pos.\tLocation\n");
    printf("----------------------------------------------------------------------------\n");

 
   struct node *myNode;
   int i, sumCount = 0;  
   for(i=0; i<eleCount; i++)
   {
      if(hashTable[i].count == 0)
          continue;
      myNode = hashTable[i].head;
      if(!myNode)
             continue;
      while(myNode != NULL)
      {
        printf("   %d\t", myNode->id);
        printf("  %s\t\t", myNode->varName); 
        printf(" %s\t\t", myNode->dataType);                
        printf(" %d\t", myNode->size);
        printf("  %d\t", sumCount);
        printf("\t%p\n", myNode);
        printf("----------------------------------------------------------------------------\n");
        sumCount = sumCount + myNode->size;
        myNode = myNode->next;        
      }
   }
}


struct incod code[20];
int id=0;
char tempChar = 'A';

char* InterCode(char *opd1, char *opd2, char opr)
{
  //printf("sdsdsd\n");
  code[ind].opd1=(char *)malloc(strlen(opd1)+1);
  strcpy(code[ind].opd1, opd1);
  code[ind].opd2=(char *)malloc(strlen(opd2)+1);
  strcpy(code[ind].opd2, opd2);
  code[ind].opr=opr;
 

   //printf("%s\t%c\t%s\n", code[ind].opd1, code[ind].opr, code[ind].opd2);
   ind++;
   //printf("temp :: %s\n",temp);
   tempChar++;
   temp = &tempChar; 
   //printf("temp :: %s\n", temp);
   return temp;
}

void ThreeAddressCode()
{
   int cnt=0; 
   char tmp = 'A';
   tmp++;
   printf("\n\n\tTHREE ADDRESS CODE\n\n");
   // printf("ind :: %d\n", ind);
   int i = 0;
   for(i=0; i<ind; i++)
   {
      printf("%c := \t", tmp);
 
      printf("%s \t", code[i].opd1);  
      printf("%c \t", code[i].opr);
      printf("%s \n", code[i].opd2);  
      
      /*fprintf(fout,"MOV %c,%s\n",tmp, code[i].opd1);
      if(strcmp(code[i].opr, "+") == 0)
         fprintf(fout,"ADD %c,%s\n",tmp, code[i].opd2);          
      else if(strcmp(code[i].opr, "-") == 0)
         fprintf(fout,"SUB %c,%s\n",tmp, code[i].opd2);          
      else if(strcmp(code[i].opr, "*") == 0)
         fprintf(fout,"MUL %c,%s\n",tmp, code[i].opd2);          
      else if(strcmp(code[i].opr, "/") == 0)
         fprintf(fout,"DIV %c,%s\n",tmp, code[i].opd2);          
      else if(strcmp(code[i].opr, "=") == 0)
         fprintf(fout,"MOV %c,%s\n",tmp, code[i].opd2);  */       
    
      
      tmp++;
   }    
}
