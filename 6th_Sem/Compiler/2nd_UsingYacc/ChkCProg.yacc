%{

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void hello();   
int SumOfAscii(char *word);  
void chkVariable(char *);
void display();
void insertToHash(int id, int key, char *name, char *type, int *loc, int size);
int searchInHash(int key);

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
    
char localName[100], type[100];   
int count = 0, loc, size, arrSize;   



extern int yylineno, yychar;

%}


%union{
    char* id;
    char* string;
}

%token <string> AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN
%token <string> FLOAT FOR GOTO IF INT LONG  REGISTER RETURN SHORT SIGNED SIZEOF STATIC STRUCT
%token <string> SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE

%token PLUS MINUS MULT DIVIDE
%token LESS LESS_EQ GREATER GREATER_EQ EQUAL NOT_EQ NOT ASSIGN PLUS_EQ MINUS_EQ MULT_EQ DIV_EQ
 
%token LEFT_PAREN RIGHT_PAREN LEFT_SQ_BRACKET RIGHT_SQ_BRACKET LEFT_CURLY RIGHT_CURLY 
%token <string> COMMA UNDERSCORE SEMICOLON CONSTANT IDENTIFIER

%type <string> variables datatype

%start program

%%

program
    : 
    | program datatype variables SEMICOLON  { printf("\n"); insertToHash(count, SumOfAscii($3), $3, $2, &size, size); }     
    | program error                         { /*yyerrok;*/ }
    ; 
    
datatype
    : CHAR      { printf("CHAR\t");    size = 1; }
    | DOUBLE    { printf("DOUBLE\t");  size = 8; }
    | INT       { printf("INT\t");     size = 4; }
    | LONG	{ printf("LONG\t");    size = 4; }
    | FLOAT 	{ printf("FLOAT\t");   size = 4; } 
    | SHORT	{ printf("FLOAT\t");   size = 2; }     
    ;
    
variables
    : IDENTIFIER                        { count++; printf("IDENTIFIER"); }
    | IDENTIFIER UNDERSCORE IDENTIFIER  { count++; printf("IDENTIFIER_IDENTIFIER"); }
    | IDENTIFIER UNDERSCORE CONSTANT    { count++; printf("IDENTIFIER_CONSTANT");  }
    | IDENTIFIER CONSTANT               { count++; printf("IdentifierConstant");  }
    ;

%%
main()
{
    hashTable = (struct hash *)calloc(eleCount, sizeof(struct hash));
    yyparse();
     
    printf("\nSYMBOL TABLE\n");
   printf("----------------------------------------------------------------------------\n");
   printf("   ID\tVar Name\tDatatype\tSize\tRel. Pos.\tLocation\n");
   printf("----------------------------------------------------------------------------\n");
   display();
   printf("\nNo. of Identifers = %d\n", count);
	

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

void display()
{
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
