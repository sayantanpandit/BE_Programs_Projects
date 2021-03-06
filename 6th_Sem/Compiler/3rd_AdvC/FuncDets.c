#include "FuncDefs.h"

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
                  
    if(strcmp(type, "") == 0)
    { 
         printf("\nInvalid Datatype\n"); 
         exit(1); 
    }
    if((chkKey == 0 || chkKey == -1) && strcmp(type, "") != 0)
	insertToHash(countVar, key, variableName, type, &key, size); 
    else if(chkKey == 1)
    { 
	 printf("\n\n\t%s --> Variable Already exists\n", variableName);  
	 exit(1);
    }
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

void insertToHash(int count, int key, char *name, char *type, int *loc, int size)
{   
   int hashIndex = key % eleCount;
   struct node *newnode = createNode(countVar, key, name, type, loc, size);
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
