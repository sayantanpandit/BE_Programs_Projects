#include<stdio.h>
#include<string.h>
#define SIZE 20
typedef struct node
{
	struct node *l,*r;
	char info;
}node;
int top;
char post[SIZE];
node* maketree(char c);
void setleft(node *p,char c)		
{ 
  p->l=maketree(c);
}
void setright(node *p,char c)	
{
  p->r=maketree(c);
}
node* getnode()	{return (node*)malloc(sizeof(node));}
node* design(char*,char*);
void postorder(node*);
int main()
{
	int i;
	node *tree;
	char pre[SIZE],in[SIZE];
	printf(" Enter Preorder traversal: ");
	scanf("%s",pre);
	printf(" Enter Inorder traversal: ");
	scanf("%s",in);
	//////////////////////
	top=0;
	tree=design(pre,in);
	top=0;
	postorder(tree);
	printf("\nPostorder traversal is: ");
	for(i=0;i<=top;i++)	printf("%c",post[i]);
	printf("\n");


	return 0;
}
node* maketree(char c)
{
	node *p=getnode();
	p->info=c;
	p->l=NULL;
	p->r=NULL;
	return p;
}
node* design(char *pre,char *in)
{
	int i;
	node *p;
	char leftpart[20],rightpart[20],ch;
	ch = pre[top++];
	if(!ch)	
        return NULL;
	if(!strlen(in))	
        {
           top--;  
           return NULL;
        }
	if(strlen(in)==1)	
        {
          return maketree(ch);
        }

	p=maketree(ch);
	for(i=0;in[i]!=ch;i++);

	strcpy(leftpart,in);	strcpy(rightpart,in+i+1);
	leftpart[i]='\0';

	//////////////////////
	p->l=design(pre,leftpart);
	p->r=design(pre,rightpart);
	return p;
}

void postorder(node *tree)
{
	if(tree==NULL)	
          return;
	postorder(tree->l);
	postorder(tree->r);
	post[top++]=tree->info;
}
