#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RESET_COLOR "\e[m"
#define MAKE_RED_DARK "\e[1;31m"
#define MAKE_GREEN_DARK "\e[1;32m"
#define MAKE_YELLOW "\e[1;33m"
#define MAKE_MAGENTA_DARK "\e[1;35m"
#define MAKE_CYAN_DARK "\e[1;36m"

void header();
void mainPage();
void insertAtBegin();
void insertBefore();
void insertAfter();
void deleteAnyNo();
void insertEnd();
void display();
void displayBefore();
void swap(int *,int *);

struct node
{
  int info;
  struct node *next;
}*head, *var, *trav, *f;
typedef struct node node;

node *sortList(node *c)
{
  node *i,*p;
  int m;
  if(c->next == NULL)
        return f;
     m = c->info;
     p = c;
   for(i=c->next;i!=NULL;i=i->next)
   {
      if((i->info) < m)
      {
         m = i->info;
         p = i;
      }
   }
     p->info = c->info; 
     c->info = m;
     return (sortList(c->next));  
}



int main()
{
  mainPage();
}

void mainPage()
{
   int choice,contd=1;
   //header();
   while(contd)
   {
    header();
    printf(MAKE_YELLOW"\t\t\t1.  "MAKE_GREEN_DARK  "Insert at Begin         "MAKE_CYAN_DARK"Press 1"RESET_COLOR"\n");
    printf(MAKE_YELLOW"\t\t\t2.  "MAKE_GREEN_DARK  "Insert Before           "MAKE_CYAN_DARK"Press 2"RESET_COLOR"\n");
    printf(MAKE_YELLOW"\t\t\t3.  "MAKE_GREEN_DARK  "Insert After            "MAKE_CYAN_DARK"Press 3"RESET_COLOR"\n");
    printf(MAKE_YELLOW"\t\t\t4.  "MAKE_GREEN_DARK  "Delete Any No.          "MAKE_CYAN_DARK"Press 4"RESET_COLOR"\n");
    printf(MAKE_YELLOW"\t\t\t5.  "MAKE_GREEN_DARK  "Insert at End           "MAKE_CYAN_DARK"Press 5"RESET_COLOR"\n");
    printf(MAKE_YELLOW"\t\t\t6.  "MAKE_GREEN_DARK  "Sort Linked List        "MAKE_CYAN_DARK"Press 6"RESET_COLOR"\n");
    printf(MAKE_YELLOW"\t\t\t7.  "MAKE_RED_DARK    "Exit                    "              "Press 0"RESET_COLOR"\n");   
    
    printf(MAKE_MAGENTA_DARK"Enter ur choice :: "RESET_COLOR);
    scanf("%d", &choice);
    if(choice<0 && choice>7)
    {
      printf("You have entered wrong input.\n");
      printf("Do you want to continue?\n");
      printf("1.Yes   2.No\n");
      printf("Enter UR Choice :: ");
      scanf("%d", &contd);
      if(contd == 2)
         exit(1);
    }
    else
    {
      if(choice == 1)
        insertAtBegin();
      else if(choice == 2)
        insertBefore();
      else if(choice == 3)
        insertAfter();
      else if(choice == 4)
        deleteAnyNo();
      else if(choice == 5)
        insertEnd();
      else if(choice == 6)
      {
         sortList(head);
         display();
      }
      else if(choice == 0)
        exit(2);
    }
   }  
}

void header()
{
   int i = 0;
   system("clear");
   printf("\t\t\t\t@     $  ##    #  @  @  ####  &&&&     #     @  $$$$  &&&&&\n");
   printf("\t\t\t\t@     $  # #   #  @ @   #     &  &     #     @  $       #\n");
   printf("\t\t\t\t@     $  #  #  #  @@    ###   &  &     #     @  $$$$    #\n");
   printf("\t\t\t\t@     $  #   # #  @ @   #     &  &     #     @     $    #\n");
   printf("\t\t\t\t@@@@  $  #    ##  @  @  ####  &&&&     ####  @  $$$$    #\n");
   for(i=0; i<144; i++)
      printf("=");
   printf("\n");
}


void insertAtBegin()
{
  int value;
  printf("\nEnter the Value to be inserted :: ");
  scanf("%d", &value);
  
  var = (struct node *)malloc(sizeof (struct node));
  var->info = value;
  
  if(head == NULL)
  {
    head       = var;
    head->next = NULL;
  }
  else
  {
      var->next = head;
      head = var;
  } 
  display();     
}


void insertBefore()
{
  int value,loc;
  struct node *var2, *var3, *temp;
  displayBefore();
  printf("\nEnter the Value to be inserted :: ");
  scanf("%d", &value);
  printf("\nEnter the Postion Before which U want to be inserted :: ");
  scanf("%d", &loc);
  temp = head;
  var = (struct node *)malloc(sizeof (struct node));
  var->info = value;
  
  if(head == NULL)
  {
    head       = var;
    head->next = NULL;
  }
  else
  {
    while(temp->info != loc)
    {
      var2 = temp;
      temp = temp->next;
    }
    if(temp == head)
    {
      var->next = temp;
      head = var;
      display();
      return;
    }
    var3 = var2->next;
    var2->next = var;
    var->next = var3;
  }    
 display();
}



void insertAfter()
{
  int value,loc;
  struct node *var2, *temp;
  displayBefore();
  printf("\nEnter the Value to be inserted :: ");
  scanf("%d", &value);
  printf("\nEnter the Postion after which u want to be inserted :: ");
  scanf("%d", &loc);
  temp = head;
  var = (struct node *)malloc(sizeof (struct node));
  var->info = value;
  
  if(head == NULL)
  {
    head       = var;
    head->next = NULL;
  }
  else
  {
    while(temp->info != loc)
      temp = temp->next;
    var2 = temp->next;
    temp->next = var;
    var->next = var2;
  }    
 display();
}

void deleteAnyNo()
{
   int value;
   displayBefore();
   printf("Enter the Value to be deleted :: ");
   scanf("%d", &value);
   struct node *temp, *var;
   temp = head;
   while(temp != NULL)
   {
       if(temp->info == value)
       {
         if(temp == head)
         {
             head = temp->next;
             free(temp);
         }
         else
         {
              var->next = temp->next;
              free(temp);
         }
       }
       else
       {
            var = temp;
            temp = temp->next;
       }
   }
   printf("Data Deleted from list :: %d\n", value);
   display();
}

void insertEnd()
{
  struct node *temp;
  int value;
  temp = head;
  printf("\nEnter the Value to be inserted :: ");
  scanf("%d", &value);
  
  var = (struct node *)malloc(sizeof (struct node));
  var->info = value;
  
  if(head == NULL)
  {
    head       = var;
    head->next = NULL;
  }
  else
  {
     while(temp->next != NULL)
       temp = temp->next;
     var->next = NULL;
     temp->next = var;
  }     
  display(); 
}

void display()
{
    trav=head;
    int c = 0,k,l,c1,k1,l1;
    if(trav == NULL)
    {
       printf("\nList is Empty\n");
    }
    else
    {
       printf("\nElements in the List :: ");
       while(trav != NULL)
       {
           printf(" -> %d ",trav->info);
           trav = trav->next;
           ++c;
       }
      k = l = c;
      k1 = l1 = c1 = c-1; 
      // For Displaying  Front and Rear
      printf("\n                            ^");
      
      while(--c)
        printf("     ");
      if(c1>2)
      {
       while(--c1)
        printf(" ");
      }
      printf("^");
      printf("\n                            |");
      
      while(--k)
        printf("     ");
      if(k1>2)
      {
       while(--k1)
        printf(" ");
      }
      printf("|");
      printf("\n                        Front");
      
      while(--l)
        printf("     ");
      if(l1>2)
      {
       while(--l1)
        printf(" ");
      }
      printf("Rear\n\n");
       
      c = c1 = k = k1 = l = l1 = 0;
    }
    
    int desire;
    while(1)
    { 
     printf("\t\tDo you want to continue? \n");
     printf("\t\t1. Yes       Press 1\n");  
     printf("\t\t2. No        Press 2\n");
     printf("\t\tEnter UR Choice :: ");
     scanf("%d", &desire);
     
     if(desire == 1)
        mainPage();
     else if(desire == 2)
        exit(3);
     else
        printf(MAKE_RED_DARK"\t\tYou have entered wrong Input..."RESET_COLOR"\n\n");
    }
}

void displayBefore()
{ 
    trav=head;
    if(trav == NULL)
    {
       printf("\nList is Empty");
    }
    else
    {
       printf("\nElements in the List: ");
       while(trav != NULL)
       {
           printf(" -> %d ",trav->info);
           trav = trav->next;
       }
      printf("\n\n");
    } 
}




void swap(int *a,int *b)
{
	int t;
	t  = *a;
	*a = *b;
	*b = t;
}




