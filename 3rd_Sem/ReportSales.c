#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>

//Design View
void header();
void mainPage();
void footer();
//Admin Function
void AdminLogin();
void AdminHome();
void AdminPagebyPage();
void AdminModProd();
void AdminEntireRegions();
//Guest Function
void GuestHome();
void GuestEntireRegions();
void GuestRegionWise();
void GuestSelectRegion(); 

int store[4][6];
int prod[8];

int main()
{
  FILE *fp;
  int prod[8] = {10,15,12,20,25,7,5,8};
  //int store[4][6];
  char ch;
  int row,col,j,k,y,z;
  int choice;
  int procode;
  
  //Initialing all elements of array 'store' = 0
  for(y=0; y<4; y++)
  {
    for(z=0; z<6; z++)
       store[y][z] = 0;
  }
   
  fp = fopen("Sales.txt", "r");
  while(1)
  {
    ch = fgetc(fp);
    if(ch == EOF)
        break;
   else if(ch>=48 && ch<=122)
    {
     //Fetching 1st character from Code for Regions
      if(ch == 'N')  
         row = 0;
      else if(ch == 'E')
         row = 1;
      else if(ch == 'W')
         row = 2;
      else if(ch == 'S')
         row = 3;  

      //Fetching 2nd Character from code for SalesPersons
      ch = fgetc(fp);
      k = ch;
      for(j=65; j<=88; j++)
      {
        if(k == j)
        {
           if(k >= 65 && k<=70)
               col = j-65;
           else if(k>70 && k<=76)
               col = j-71;
           else if(k>76 && k<=82)
               col = j-77;
           else if(k>82 && k<=88)
               col = j-83; 
          break;
        }
      }    
      
      //Fetching 3rd & 4th Character for Products Code
       ch = fgetc(fp);
       procode = (ch-48)*10;
       ch = fgetc(fp);
       procode = procode + (ch-48);

      //Fetching no. of Products
        int n = 2, nop = 0;
        while(n>=0)
        {
          ch  = fgetc(fp);
          nop = nop + ((ch-48) * pow(10,n));
          n = n-1;
        }
       
      //Calculation
        for(y=1; y<=8; y++)
        {
          int t = (y*10)+y;
          if(procode == t)
               store[row][col] = store[row][col] + (prod[y-1] * nop);
         }       
     }
  }
  fclose(fp);    
  mainPage();
}

void header()
{
  system("clear");
  printf("\t \t \t \t   Welcome \n");
  printf("\t \t \t \t     To\n");
  printf("\t \t \t WebMaker Corporation Ltd. \n");
  printf("\t \t   26, Heaven-Hell Road, Graveyard - 000000\n");
  int i = 0;
  for(i=0; i<80; i++)
     printf("=");
  printf("\n");
}

void footer()
{
 int i;
 for(i=0; i<4; i++)
    printf("\n"); 
  for(i=0; i<80; i++)
     printf("=");
  printf("\n\t \t    Designed and Created by SAYANTAN PANDIT. \n");
 for(i=0; i<80; i++)
     printf("=");
 printf("\n");
}

void mainPage()
{
  header();
  int i, choice;
  for(i=0; i<4; i++)
    printf("\n");
  printf("\t \t \t         MENU \n");
  printf("\t \t \t A. Admin        Press 1\n"); 
  printf("\t \t \t B. Guest        Press 2\n");
  printf("\t \t \t C. Exit         Press 3\n");
  printf("\t \t \t Select UR Choice :: ");
  scanf("%d", &choice);
  if(choice == 1)
     AdminLogin();
  else if(choice == 2)
     GuestHome();
  else if(choice == 3)
     exit(2);
  else
       printf("Wrong Input\n");
  footer();      
}


void GuestHome()
{
  header();
  int i, guestChoice;
  printf(" HOME | Entire Regions Report | Region Wise Report | Select Region Report | EXIT\n");
  for(i=0; i<80; i++)
     printf("=");
  printf(" Welcome \n\t   This is a HomePage of WebMaker Corporation Ltd. \n\t   Select ur Choice from the above tabs. \n\t   For Example \n");
  printf("\t \t\t A. Home                     Press 1\n"); 
  printf("\t \t\t B. Entire Regions Report    Press 2\n"); 
  printf("\t \t\t C. Region Wise Report       Press 3\n");
  printf("\t \t\t D. Select Region Report     Press 4\n");
  printf("\t \t\t E. Exit                     Press 5\n");
  printf("\t \t\t Select UR Choice :: ");
  scanf("%d", &guestChoice);

  if(guestChoice == 1)
     mainPage();
  else if(guestChoice == 2)
     GuestEntireRegions();
  else if(guestChoice == 3)
     GuestRegionWise();
  else if(guestChoice == 4)
     GuestSelectRegion();
  else if(guestChoice == 5)
  {
      footer();
      exit(1);
  }
  footer();
}

void GuestEntireRegions()
{ 
   header();
   int i,j, guestChoice;
   printf("    HOME    |    Entire Regions Report   |   Region Wise Report    |   EXIT  \n");
  for(i=0; i<80; i++)
     printf("=");
   printf("\n\n\t \t \t Entire Regions Report\n");
   printf("\t \t \t ---------------------\n");  
   //For Displaying in Regions
     printf("\t\t S1 \t S2 \t S3 \t S4 \t S5 \t S6 \n");
     for(i=0; i<4; i++)
     {
       printf("Regions %d\t", (i+1));
       for(j=0; j<6; j++)
         printf("%d \t", store[i][j]);
       printf("\n");
     } 
    printf("\n\n\t\tGo to HomePage     Press 1");
    printf("\n\t\tExit               Press 2");
    printf("\n\n\t\tSelect UR Choice :: ");
    scanf("%d", &guestChoice);
    if(guestChoice == 1)
        GuestHome();
    else if(guestChoice == 2)
    {
        footer();
        exit(1);
    }
    else
      GuestEntireRegions();
}

void GuestRegionWise()
{
 int i, region = 1, n;
 while(1)
 {
  header();
  int i;
  printf(" HOME | Entire Regions Report | Region Wise Report | Select Region Report | EXIT\n");
  for(i=0; i<80; i++)
     printf("=");
  printf("\n\t\t\tRegion %d -->\n", region);
  for(i=0; i<6; i++)
   printf("\t\tSalesman %d :: %d\n",(i+1),store[region-1][i]);
  
  printf("\n\t --- UR Choice --- ");
  if(region > 1 && region <=4)
    printf("\n\t > Previous Region     Press 1");
  if(region >= 1 && region <4) 
    printf("\n\t > Next Region         Press 2");
    printf("\n\t > Go to Guest HomePage Press 0");
   printf("\n\t Select ur Choice :: ");
   scanf("%d", &n);
     if(n == 0)
       GuestHome();
     else if(n == 1)
       region = region-1;
     else if(n == 2)
       region = region+1;
   }
   footer();
}


void GuestSelectRegion()
{
  header();
  int i;
  printf("    HOME    |    Entire Regions Report   |   Region Wise Report    |   EXIT  \n");
  for(i=0; i<80; i++)
     printf("=");
  
  int region,n=1;
 while(n == 1)
 {
  printf("\n\n\tSelect Region :: ");
  scanf("%d", &region);
  
   //For Displaying Regions-wise-Salesman
  if(region == 1 || region == 2 || region == 3 || region == 4)
  { 
    printf("\n\t\tRegion %d -->\n", region);
    for(i=0; i<6; i++)
     printf("\t\tSalesman %d :: %d\n",(i+1),store[region][i]);
    printf("Do u want to continue ? \n");
    printf("1. Yes    2.No  :: ");
    scanf("%d", &n);
    header();
    printf("    HOME    |    Entire Regions Report   |   Region Wise Report    |   EXIT  \n");
    for(i=0; i<80; i++)
     printf("=");

  }
  else
  {
    printf("You have to enter between 1 to 4.\n");
    printf("You have entered a wrong input....\n");
    printf("Do u want to continue ? \n");
    printf("1. Yes    2.No  :: ");
    scanf("%d", &n);
  }
   if(n == 2)
       GuestHome();
 }
}

void AdminLogin()
{
  header();
  char username[20];
  char password[20];
  //char *in = password;
  int attempt = 0;
  while (attempt < 3)
  {
   printf("\n\nEnter Username --> \n");
   scanf("%s",username);
   char *in = password;
   struct termios  tty_orig;
   char c;
   tcgetattr( STDIN_FILENO, &tty_orig );
   struct termios tty_work = tty_orig;

   puts("Enter Password --> ");
   tty_work.c_lflag &= ~( ECHO | ICANON );  // | ISIG );
   tty_work.c_cc[ VMIN ]  = 1;
   tty_work.c_cc[ VTIME ] = 0;
   tcsetattr( STDIN_FILENO, TCSAFLUSH, &tty_work );

   while (1) {
      if (read(STDIN_FILENO, &c, sizeof c) > 0) {
          if ('\n' == c) {
             break;
               }
             *in++ = c;
           write(STDOUT_FILENO, "*", 1);
           }
        }
      tcsetattr( STDIN_FILENO, TCSAFLUSH, &tty_orig );

        *in = '\0';
        fputc('\n', stdout);
   
   if((strcmp(username,"Admin") == 0) && (strcmp(password,"Admin") == 0))
      AdminHome();
   else
   {
      header(); 
      printf("\n\tLogin Attempt :: %d out of 3", ++attempt);
   }
  }
  if(attempt == 3)
  {
      printf("\n\n\nSorry...Your account is blocked !!!\n");
      footer();
      exit(1);
  }
}

void AdminHome()
{
   header();
   int i, adminChoice;
  printf(" HOME | Modify Products | Entire Region Report | Page-by-Page Report | LOGOUT\n");
  for(i=0; i<80; i++)
     printf("=");
  printf(" Welcome \n\t   This is a HomePage of WebMaker Corporation Ltd. \n\t   Select ur Choice from the above tabs. \n\t   For Example \n");
  printf("\t \t\t A. Home                     Press 1\n"); 
  printf("\t \t\t B. Modify Products          Press 2\n"); 
  printf("\t \t\t C. Entire Region Report     Press 3\n");
  printf("\t \t\t D. Page-by-Page Report      Press 4\n");
  printf("\t \t\t E. LOGOUT                   Press 5\n");
  printf("\t \t\t Select UR Choice :: ");
  scanf("%d", &adminChoice);

  if(adminChoice == 1)
     AdminHome();
  else if(adminChoice == 2)
     AdminModProd();
  else if(adminChoice == 3)
     AdminEntireRegions();
  else if(adminChoice == 4)
     AdminPagebyPage();
  else if(adminChoice == 5)
      mainPage();
}

void AdminModProd()
{
  header(); 
  int prod[8] = {10,15,12,20,25,7,5,8};
  int i, prodCode, prodPriceNow;
  printf(" HOME | Modify Products | Entire Region Report | Page-by-Page Report | LOGOUT\n");
  for(i=0; i<80; i++)
     printf("=");
  printf("\n\nProduct's Code :: ");
  scanf("%d", &prodCode);
  while(prodCode != 11 && prodCode != 22 && prodCode != 33 && prodCode != 44 && prodCode != 55 && prodCode != 66 && prodCode != 77 && prodCode != 88 && prodCode != 99)
  {
    printf("\nYou have entered wrong INPUT...\n");
    printf("\nProduct's Code :: ");
    scanf("%d", &prodCode);
    if(prodCode == 11 || prodCode == 22 || prodCode == 33 || prodCode == 44 || prodCode == 55 || prodCode == 66 || prodCode == 77 || prodCode == 88 || prodCode == 99)
      break;
  }
  int c1 = prodCode%10;
  printf("\nProduct's Old Price :: %d", prod[c1-1]);
  printf("\nProduct's New Price :: ");
  scanf("%d", &prodPriceNow);
  prod[c1-1] = prodPriceNow;  

  //Calculation
  FILE *fp;
  char ch;
  int row,col,j,k,y,z;
  int choice;
  int procode;
   
  //Initialing all elements of array 'store' = 0
  for(y=0; y<4; y++)
  {
    for(z=0; z<6; z++)
       store[y][z] = 0;
  } 
 
  fp = fopen("Sales.txt", "r");
  while(1)
  {
   ch = fgetc(fp);
   if(ch == EOF)
        break;
   else if(ch>=48 && ch<=122)
   {
    //Fetching 1st character from Code for Regions
      if(ch == 'N')  
         row = 0;
      else if(ch == 'E')
         row = 1;
      else if(ch == 'W')
         row = 2;
      else if(ch == 'S')
         row = 3;  

   //Fetching 2nd Character from code for SalesPersons
     ch = fgetc(fp);
     k = ch;
     for(j=65; j<=88; j++)
     {
      if(k == j)
      {
        if(k >= 65 && k<=70)
          col = j-65;
        else if(k>70 && k<=76)
          col = j-71;
        else if(k>76 && k<=82)
          col = j-77;
        else if(k>82 && k<=88)
          col = j-83; 
        break;
      }
     }    
      
   //Fetching 3rd & 4th Character for Products Code
     ch = fgetc(fp);
     procode = (ch-48)*10;
     ch = fgetc(fp);
     procode = procode + (ch-48);

   //Fetching no. of Products
     int n = 2, nop = 0;
     while(n>=0)
     {
       ch  = fgetc(fp);
       nop = nop + ((ch-48) * pow(10,n));
       n = n-1;
     }
       
  //Final Calculation
  for(y=1; y<=8; y++)
  {
    int t = (y*10)+y;
    if(procode == t)
      store[row][col] = store[row][col] + (prod[y-1] * nop);
   }       
  }
  }
   fclose(fp);
   AdminEntireRegions();
}

void AdminEntireRegions()
{
   header();
   int i,j, adminChoice;
   printf(" HOME | Modify Products | Entire Region Report | Page-by-Page Report | LOGOUT\n");
  for(i=0; i<80; i++)
     printf("=");
   printf("\n\n\t \t \t Entire Regions Report\n");
   printf("\t \t \t ---------------------\n");  
   //For Displaying in Regions
     printf("\t\t S1 \t S2 \t S3 \t S4 \t S5 \t S6 \n");
     for(i=0; i<4; i++)
     {
       printf("Regions %d\t", (i+1));
       for(j=0; j<6; j++)
         printf("%d \t", store[i][j]);
       printf("\n");
     } 
    printf("\n\n\t\tGo to HomePage     Press 1");
    printf("\n\t\tExit               Press 2");
    printf("\n\n\t\tSelect UR Choice :: ");
    scanf("%d", &adminChoice);
    if(adminChoice == 1)
        AdminHome();
    else if(adminChoice == 2)
    {
        footer();
        exit(1);
    }
    else
    {
       AdminEntireRegions();
    }
  
}

void AdminPagebyPage()
{
 int i,j, p = 1, count = 0, tcount = 0, carry = 0, page = 1, adminChoice;
 while(p>0 && p<5)
 { 
  header();
    printf(" HOME | Modify Products | Entire Region Report | Page-by-Page Report | LOGOUT\n");
  for(i=0; i<80; i++)
     printf("=");
  printf("\n\t\t\tPage :: %d", page);
  printf("\n\n\tRegions\tSalesman's Name\tProduct Sell(in Rs.)");
   int k = 0;
   for(j=carry; j<8; j++)
   {
     if((carry+k) == 6)
     {
       j = 0;
       if(p < 4)
         p = p + 1;
     } 
      if((p == 1) && ((65+j)<=70))
       printf("\n\t    %d     \t%c\t        %d", p,(65+j), store[p-1][j]);
      else if((p == 2) && ((71+j)<=76))
       printf("\n\t    %d     \t%c\t        %d", p,(71+j), store[p-1][j]);
      else if((p == 3) && ((77+j)<=82))
       printf("\n\t    %d     \t%c\t        %d", p,(77+j), store[p-1][j]);
      else if((p == 4) && ((83+j)<=88))
       printf("\n\t    %d     \t%c\t        %d", p,(83+j), store[p-1][j]);     
    count = count + 1;
    tcount = tcount + 1;
    //printf("\t%d\t%d\t%d", count, p ,carry);
    if(count == 8) 
       break;  
    k++;
   }
    count = 0;
    if(p>2)
      printf("\n\tA. Previous Page    Press 1");
    if(p<4)
      printf("\n\tB. Next Page        Press 2");
    printf("\n\tC. Go to HomePage   Press 3");
    printf("\n\tSelect UR Choice :: ");
    scanf("%d", &adminChoice);
    if(adminChoice == 1)
    {
         carry = carry - 2;
         p = p - 2;
         page  = page - 1;
    }
    else if(adminChoice == 2)
    {
       if(count == 6)
         p = p + 1;
       if(j < 6)
         carry = j+1;
        page = page + 1;
    }
    else if(adminChoice == 3)
      AdminHome();
    else
      AdminPagebyPage();
  }
}
