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

int ind=0; 
char *temp;
struct incod
{
    char *opd1;
    char *opd2;
    char opr;
};
    
char localName[100], type[100];   
int count1 = 0, loc, size, arrSize;   

extern int yylineno, yychar;

%}


%union{
    char* id;
    char* string;
}


%token <string> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token <string> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression         { printf("Additive_2\n"); }
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID      
	| CHAR           		{ printf("CHAR\t");     size = 1;  strcpy(type, $1); }
	| SHORT          		{ printf("SHORT\t");    size = 2;  strcpy(type, $1); }
	| INT            		{ printf("INT\t");      size = 4;  strcpy(type, $1); }
	| LONG           		{ printf("LONG\t");     size = 4;  strcpy(type, $1); }
	| FLOAT		 		{ printf("FLOAT\t");    size = 2;  strcpy(type, $1); }
	| DOUBLE	 		{ printf("DOUBLE\t");   size = 8;  strcpy(type, $1); }
	| SIGNED	 		{ printf("SIGNED\t");   size = 4;  strcpy(type, $1); }
	| UNSIGNED	 		{ printf("UNSIGNED\t"); size = 4;  strcpy(type, $1); }
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER			{ count1++; printf("IDENTIFIER\t"); chkVariable($1); }
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'		
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER	  		     { count1++; printf("IDENTIFIER\t"); chkVariable($1);  }
	| identifier_list ',' IDENTIFIER     { count1++; printf("IDENTIFIER\t"); chkVariable($3);  }   
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
       // | IF '(' expression ')' statement ELSE statement		
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


main()
{
    hashTable = (struct hash *)calloc(eleCount, sizeof(struct hash));
    temp = "A";
    yyparse();
     
    printf("\nSYMBOL TABLE\n");
   printf("----------------------------------------------------------------------------\n");
   printf("   ID\tVar Name\tDatatype\tSize\tRel. Pos.\tLocation\n");
   printf("----------------------------------------------------------------------------\n");
   display();
   printf("\nNo. of Identifers = %d\n", count1);
	

    return 0;
}

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
                  
    if(strcmp(type, "") == 0 && strcmp(variableName, "main") != 0)
    { 
         printf("\nInvalid Datatype\n"); 
         exit(1); 
    }
    if((chkKey == 0 || chkKey == -1) && strcmp(type, "") != 0)
	insertToHash(count1, key, variableName, type, &key, size); 
    else if(chkKey == 1)
    { 
	 printf("\n\n\t%s --> Variable Already exists\n", variableName);  
	 exit(1);
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

struct incod code[20];
int id=0;

char* InterCode(char* opd1, char* opd2, char opr)
{
  code[ind].opd1 = (char *)malloc(sizeof(char)*5);
  strcpy(code[ind].opd1, opd1);
  code[ind].opd2 = (char *)malloc(sizeof(char)*5);  
  strcpy(code[ind].opd2, opd2);
  code[ind].opr=opr;
  ind++;
  *(temp)++; 
  return temp;
}
