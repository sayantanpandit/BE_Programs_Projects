#include<stdio.h>
#include<stdlib.h>
struct node
	{
 		 int data;
  		struct node *next;
	};
typedef struct node node;
node *f;             
node *sortlist(node *c)
{
  	 node *i,*p;
   	int m;
  	 if(c->next==NULL)
       		 return f;
   	m=c->data;
   	p=c;
   	for(i=c->next;i!=NULL;i=i->next)
  	 {
      		 if((i->data)<m)
       		{
           		m=i->data;
           		p=i;
       		}
  	 }
     	(p->data)=(c->data); 
     	c->data=m;
     	return(sortlist(c->next));  
}

node *insertend(node *f)//Here, since our interest is only sorting we are just using insertend
{
   node *cur,*c;
   cur=(node *)malloc(sizeof(node));
   printf("\n enter the no to be inserted:");
   scanf("%d",&cur->data);
   cur->next=NULL;
   if(f==NULL)
  {
    f=cur;
    return f;
  }
  for(c=f;c->next!=NULL;c=c->next);
  c->next=cur;
  return f;
}


void list(node *f)
{
  node *c;
  printf("\nTraverse through the linklist:\t");
  for(c=f;c!=NULL;c=c->next)
  {
    printf("%d\t",c->data);
  }
   return;
}
int main()
 {
	node *start;
	char ch;
	int a;
	start=NULL;
	do
	{
		printf("\n1.Insert an element in the ll");
		printf("\n2.Sort the ll");
		printf("\n3.Exit from the Menu");
		printf("\n Enter your choice : ");
		if(scanf("%d",&a))
			{
  				switch(a)
  				{
					case 1:start=insertend(start);
					       list(start);
						break;
					case 2: f=start;
						start=sortlist(start);
						list(start);
						break;
					case 3:exit(1);
					default:printf("\nInvalid input\n");
	 					exit(2);
				}
			}
		 else
			{
				printf("\nInvalid input\n");
				exit(3);
			}
	}while(a!=3);
return 0;
}	

