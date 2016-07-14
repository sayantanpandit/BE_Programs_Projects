#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXSIZE 100
int top;
int position[500];
char data[500];
typedef struct
{
  int pos1;
  int pos2;
}parr;
void push(char ch,int pos)
{
  if(top==MAXSIZE-1)
  {
    printf("\nStack Overflow");
    return;
  }
top++;
data[top]=ch;
position[top]=pos;
return;
}
int empty()
{
  if(top==-1)
  {
    return 1;
  }
return 0;
}
char pop(int *p)
{
 char c;
  (*p)=position[top];
   c=data[top];
   top--;
   return c;

}
int main()
{
  char c[100],p,symb;/*p=popped element*/
  int i,j,flag=0,flag1=0,pos,pn,k=0,k1=0,pix,ind,count,stlngth,x,marker[100]={0},whitecount=0,erpos[100],ep=0,y,brckpos[100]={0},a=0,b=0,pi;
  parr arr[50],arr1[50];
  top=-1;
  /*i=index*/

  printf("\nEnter the expression:\n");
  scanf("%[^\n]",c);
  //displaying the string caracterwise*/
  for(i=0;c[i]!='\0';i++)
  {
    symb=c[i];
    if(isspace(symb)==0)
    {
    pos=i+1;
    if(symb=='('||symb=='{'||symb=='[')
	{
	 push(symb,pos);
	 brckpos[a++]=pos;
	 /*printf("\n position=%d",i);*/
	}
    if(symb==')'||symb=='}'||symb==']')
	{
	brckpos[--a]=0;
	 if(empty())
	 {
	  flag1=2;
	  marker[i]=1;
	  erpos[ep++]=pos;
	 }
	 else
	 {
	   p=pop(&pn);
	   if(symb==')'&&p!='(')
		{
		
			arr1[k1].pos1=pn;
			arr1[k1].pos2=pos;
			k1++;
			flag=1;
			marker[i]=1;
			
		}

	   if(symb=='}'&&p!='{')
		{
		  flag=1;
		 arr1[k1].pos1=pn;
		 arr1[k1].pos2=pos;
		 k1++;
		 marker[i]=1;
		  
		}
	    if(symb==']'&&p!='[')
		{
		  flag=1;
		  arr1[k1].pos1=pn;
		  arr1[k1].pos2=pos;
		  k1++;
		  marker[i]=1;

		}
	    else
	    {
	     arr[k].pos1=pn;
	     arr[k].pos2=pos;
	     k++;
	    }
	  }/*closing of else statement block*/
	 }/*closing of if statement block*/
	}/*closing of if statement which checks for the whitespace*/
	else if(isspace(symb))
	{ //that means symbol is a whitespace
		whitecount++;
	}

   }/*closing of for loop*/
   	for(b=0;b<100;b++)
   	{
   		if(brckpos[b]!=0)
   		{
   			pi=brckpos[b];
   			pix=pi-1;
   			marker[pix]=1;
   		}
   	}
   			
	printf("\n\n");
	stlngth=strlen(c);
     	count=strlen(c)-whitecount;
     		if(flag!=0||flag1!=0||top>-1)
	{
		for(i=0;c[i]!='\0';i++)
		{
			if(isspace(c[i])==0)
			{
			 printf("%c ",c[i]);
			}
		}
		printf("\n\n");
		for(x=0;x<count;x++)
		{
			if(marker[x]==0)
			{
				printf("  ");
			}
			else if(marker[x]==1)
			{
				printf("^ ");
			}
		}
		printf("\n");
		for(x=0;x<count;x++)
		{
			if(marker[x]==0)
			{
				printf("  ");
			}
			else if(marker[x]==1)
			{
				printf("| ");
			}
		}
		printf("\n");
	}

 if(flag==0&&flag1==0&&top==-1)/*after the operation stack must be empty*/
 {
   for(ind=0;ind<k;ind++)
   {
     printf("\nMatch Found=(%d,%d)",arr[ind].pos1,arr[ind].pos2);
   }
   printf("\n\nBalanced\n");
 }


 if(flag==1||flag1==2||(flag==0&&flag1==0&&top>-1))
 {
  if(flag==0&&flag1==0&&top>-1)
{
	printf("\n opening bracket exists and no respective closing brackets at:");
	for(a=0;a<=top;a++)
	{
	  printf("%d ",position[a]);
	}
	 }
  if(flag1==2)
  {
  printf("\nMismatch due to closing bracket before opening bracket at -> ");
  for(y=0;y<ep;y++)
  {
		printf("%d ",erpos[y]);
  }
}
  for(ind=0;ind<k1;ind++)
  {
   printf("\nMismatch found = (%d,%d)",arr1[ind].pos1,arr1[ind].pos2);
  }
   printf("\nThe braces are not balanced\n");
 }
 
return 0;
}
