#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
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
int countVar = 0, loc, size, arrSize;   
