#include<stdio.h>
struct node
{
    struct node *next;
    char name[10];
}*start;

typedef struct node *Nodeptr;
//Add a node
void add(char namePassed[])
{
  Nodeptr temp=(struct node *)malloc(sizeof(struct node));
  Nodeptr move;
  move=start;
  if(temp==NULL)
  {
    printf("OverFlow\n");
    return;
  }
  while((move->next)!=NULL)
  move=move->next;
  strcpy(temp->name,namePassed);
  temp->next=NULL;
  move->next=temp;
}

int main()
{
 char choice[20];
 start=(Nodeptr)malloc(sizeof(struct node));
 printf("                                                    Josephus Problem\n");
 printf("                                          Enter the name :: ");//Enter the begining node
 scanf("%s",start->name);
 start->next = NULL;
 printf("Enter end to stop entering data otherwise Enter the name :: ");
 scanf("%s",choice);
 while(strcmp(choice,"end") != 0)
 {
  add(choice);
  printf("Enter end to stop entering data otherwise Enter the name :: ");
  scanf("%s",choice);
 }
 Nodeptr move=start;
 while((move->next)!=NULL)
 move=move->next;
 move->next=start;//Make the list circular by making the end point to start
 move=start;
 int count;//takes the count after which the soldier is removed
 char begin[20];//stores name of soldier to begin with
 printf("Enter the count after which deletion is to happen and Enter the name of starting soldier\n");
 scanf("%d%s",&count,begin);
 int ctr=0;
 while(strcmp(move->name,begin)!=0)
 move=move->next;//move to the soldier which user told to start with
 int pass=1;
 while(move->next!=move)//when move->next==move than we have only one soldier left
 {
  ctr++;
  if(ctr==count-1)//delete next node
  {
    Nodeptr temp=move->next;
    move->next=temp->next;
    printf("The soldier who eliminated in pass number %d is %s\n",pass,temp->name);
    free(temp);//free space
    ctr=0;
    pass++;
  }
  move=move->next;
 }
 printf("The soldier who escapes is %s\n",move->name);
}

