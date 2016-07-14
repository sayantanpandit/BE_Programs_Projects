%{
   #include <string.h>
   #include <stdio.h>
   #include <stdlib.h>
   
   int SumOfAscii(char *word);  
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
   int count = 0, loc, size;   
%}

digit  [0-9]+
delim  [ \t]
ws     {delim}*

%%
auto      	{ printf("AUTO\t");  }
break     	{ printf("BREAK\t"); }
case      	{ printf("CASE\t");  }
char      	{ printf("CHAR\t"); count++; strcpy(type, "char"); size=1;  }
const     	{ printf("CONST\t"); }
continue  	{ printf("CONTINUE\t"); }
default   	{ printf("DEFAULT\t");	}
do        	{ printf("DO\t"); }
double          { printf("DOUBLE\t"); count++; strcpy(type, "double");  size=8; }
else            { printf("ELSE\t"); }
enum            { printf("ENUM\t"); }
extern          { printf("EXTERN\t"); }
exit            { return 0; }
float           { printf("CASE\t"); count++; strcpy(type, "float");  size=4; }
for             { printf("FOR\t"); }
goto            { printf("GOTO\t"); }
if              { printf("IF\t"); }
int		{ printf("INT\t");  count++; strcpy(type, "int");   size=4; }
long		{ printf("LONG\t"); count++; strcpy(type, "long");  size=4; }
main		{ printf("IDENTIFIER\t"); }
register	{ printf("REGISTER\t"); }
return		{ printf("RETURN\t"); }
short		{ printf("SHORT\t"); }
signed		{ printf("SIGNED\t"); }
sizeof		{ printf("SIZEOF\t"); }
static		{ printf("STATIC\t"); }
struct		{ printf("STRUCT\t"); }
switch		{ printf("SWITCH\t"); }
typedef		{ printf("TYPEDEF\t"); }
union		{ printf("UNION\t"); }
unsigned	{ printf("UNSIGNED\t"); }
void		{ printf("VOID\t"); }
volatile	{ printf("VOLATILE\t"); }
while		{ printf("WHILE\t"); }

"<" 		{ printf("RELOP\t"); }
"<=" 		{ printf("RELOP\t"); }
">" 		{ printf("RELOP\t"); }
">=" 		{ printf("RELOP\t"); }
"==" 		{ printf("RELOP\t"); }
"!=" 		{ printf("RELOP\t"); }
"!"		{ printf("RELOP\t"); }
"=" 		{ printf("RELOP\t"); }
"+=" 		{ printf("RELOP\t"); }
"-=" 		{ printf("RELOP\t"); }
"*=" 		{ printf("RELOP\t"); }
"/=" 		{ printf("RELOP\t"); }

"+" 		{ printf("OPERATOR\t"); }
"-" 		{ printf("OPERATOR\t"); }
"*" 		{ printf("OPERATOR\t"); }
"/"  		{ printf("OPERATOR\t"); }
"," 		{ printf("OPERATOR\t"); }
"(" 		{ printf("DELIM\t"); }
")" 		{ printf("DELIM\t"); }
"[" 		{ printf("DELIM\t"); }
"]" 		{ printf("DELIM\t"); }

";"		{ printf("Semi-Colon"); int key = SumOfAscii(localName); 
                  int chkKey = searchInHash(key);
		  if(chkKey == 0 || chkKey == -1)
		      insertToHash(count, key, localName, type, &key, size); 
		  else if(chkKey == 1)
		      { printf("\n\n\t%s --> Variable Already exists\n", localName);  exit(1); }
		}

"\n" 		{ printf("\n"); }

{digit}         { printf("DIGIT\t"); }
[a-zA-Z]*       { printf("IDENTIFIER\t"); /*strcpy(varName[count], yytext);*/ strcpy(localName, yytext); }
{ws}            { /*No action and no return*/ }
[-#<>{}=+*/.]   { printf("DELIM"); }

%%
main(int argc, char *argv[])
{
   hashTable = (struct hash *)calloc(eleCount, sizeof(struct hash));
   yyin = fopen(argv[1], "r");
   printf("\nFile Name = %s\n", argv[1]);
   
   yylex();
   printf("\nSYMBOL TABLE\n");
   printf("----------------------------------------------------------------\n");
   printf("   ID\tVar Name\tDatatype\tSize\tLocation\n");
   printf("----------------------------------------------------------------\n");
   display();
   printf("\nNo. of Identifers = %d\n", count);
   fclose(yyin);
}

yywrap() 
{}

int SumOfAscii(char *word)
{
   int i, sum=0;
   for(i=0; i<strlen(word); i++)
       sum = sum + word[i];
   return sum;
}

void display()
{
   struct node *myNode;
   int i;  
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
        printf("    %s\t\t", myNode->varName); 
        printf(" %s\t\t", myNode->dataType);                
        printf(" %d\t", myNode->size);                      
        printf("    %p\n", myNode);
        printf("----------------------------------------------------------------\n");
        myNode = myNode->next;
      }
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
     return 0;      //Search element unavailable in hash table...Not Flag\n");
}
