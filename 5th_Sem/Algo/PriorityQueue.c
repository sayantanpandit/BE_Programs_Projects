#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
typedef struct
{
  int value;
  int key;
}item;

void Maximum(item *, int *, item *);
void ExtractMax(item *,int *,item *);
void InsertHeap(item *,int *,item *);
void Heap_IncreaseKey(item *,int *, int , int );
void Swap(item *, item *);
int Parent(int );
void heapify(item arr[],int i,int n)
{
	int l,r,largest;
	l=2*i+1;
	r=2*i+2;
	if((l<=n)&&(arr[l].key>arr[i].key))
	{
		largest=l;	
	}
	else
	{
		largest=i;
	}
	if((r<=n)&&(arr[r].key>arr[largest].key))
	{
		largest=r;

	}
	if(i!=largest)
	{
		Swap(&arr[i],&arr[largest]);
		heapify(arr,largest,n);
	}
}
void Swap(item *a, item *b)
{ 
   int tempvalue;
   int tempkey;
   tempvalue = a->value;
   tempkey   = a->key;
   a->value   = b->value;
   a->key     = b->key;
   b->key     = tempkey;
   b->value   = tempvalue; 
}


void Maximum(item arr[], int *n, item *maxElem)
{
   if((*n) < 0)
   {
      printf("Priority Queue does not contain any item\n");
      return;
   }
   (*maxElem) = arr[0]; 
}

void ExtractMax(item arr[], int *n, item *maxElem)
{ 
   if((*n)<0)
   {
 	printf("Empty priority queue\n");
	return;
   }
   else if((*n)==0)
   {
	(*n) =(*n)-1;
	(*maxElem) = arr[0];
	return;
   }

   Swap(&arr[0],&arr[(*n)]);
   (*n) = (*n)-1;
   heapify(arr,0,(*n));
   (*maxElem) = arr[(*n)+1];
   return;
}

void InsertHeap(item arr[], int *n, item *x)
{
   if((*n)<0)
   {
       printf("This is the first item\n");
   }
   (*n) = (*n)+1;
   int i=(*n);
   while(i>0 && arr[parent(i)].key<x->key)
   {
       arr[i].value = arr[parent(i)].value;
       arr[i].key   = arr[parent(i)].key;
       i = parent(i);
   }
  arr[i].value = x->value;
  arr[i].key   = x->key;
}
void Heap_IncreaseKey(item arr[],int *n, int chvalue, int newKey)
{
    bool flag = false;
    int i;
    for(i=0;i<=(*n);i++)
    {
	if(arr[i].value == chvalue)
	{
		flag=true;
		break;
	}
    }
   if(flag == false)
   {
	printf("Value is not found\n");
	return;
   }
  else
  {
     if(arr[i].key > newKey)
     {
	printf("New key is smaller than current key\n");
	return;
     }
     else
     {
	arr[i].key = newKey;
	item x = arr[i];
	while(i>0 && arr[parent(i)].key < newKey)
	{
	     arr[i].value = arr[parent(i)].value;
	     arr[i].key   = arr[parent(i)].key;
	     i = parent(i);
	}
	arr[i].value = x.value;
	arr[i].key   = x.key;
     }
  }
}

int parent(int i)
{
	return (i-1)/2; 
}
int main()
{
   int itemno = -1, choice;
   item arr[100];
   

   while(1)
   {
      printf("1. Insert a new Element\n");
      printf("2. Display the Largest Key\n");
      printf("3. Delete the Largest key\n");
      printf("4. Increase the element's keyvalue with new key\n"); 
      printf("5. Exit\n");

      scanf("%d", &choice);
      
     if(choice == 1)
     {
        item newitem;
        printf("Enter element's value :: ");
        scanf("%d", &newitem.value);
        printf("Enter element's key :: ");
        scanf("%d", &newitem.key); 
        InsertHeap(arr,&itemno,&newitem);
     }
     else if(choice == 2)
     {
        item maxitem;
        Maximum(arr,&itemno,&maxitem);
        printf("Largest Value = %d key = %d\n\n",maxitem.value,maxitem.key);
     }
     else if(choice==3)
     {
        item delMaxItem;
        ExtractMax(arr,&itemno,&delMaxItem);
        printf("Delete Max Value = %d Key = %d\n\n",delMaxItem.value, delMaxItem.key );
     }
     else if(choice == 4)
     {
         int val, newKeyVal;
         printf("Enter the element's value :: ");
         scanf("%d", &val);
         printf("Enter the new key value :: ");
         scanf("%d", &newKeyVal);
         Heap_IncreaseKey(arr,&itemno, val, newKeyVal);
     }
    else if(choice == 5)
        exit(1);
    else
       printf("You have entered wrong choice...Try Again\n");
   }
}


