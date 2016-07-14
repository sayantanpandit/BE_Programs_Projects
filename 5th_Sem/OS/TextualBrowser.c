#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>

#define RESET_COLOR "\e[m"
#define MAKE_RED_DARK "\e[1;31m"
#define MAKE_GREEN_DARK "\e[1;32m"
#define MAKE_YELLOW "\e[1;33m"

void list_fileNfolder();
void list_childFileNfolder(int );
void sortList(int );
void printPermission(int ,int ,int ,int ,int ,int ,int ,int ,int );
void printDetails(int );
int compare_names(void *, void *);

typedef struct listFileNFolder
{
    int sn;
    char *name;
  //  char type[5]; 
}listDir;
listDir listDetails[500];

int i;
char *scd = NULL;

int main()
{
  system("clear");
  int choice;
  list_fileNfolder();
  
  while(1)
  {
    printf("Give the number corresponding to the above options :: ");
    scanf("%d", &choice);

    if(choice == 0)
      exit(1); 
    else if(choice == 1)
    {
      chdir("..");
      list_fileNfolder(".");  
    }
    else
    {
      list_childFileNfolder(choice);
    }
  }
  return 0;
}


void list_fileNfolder()
{
  char *s;
  int k=0;
  DIR *d;
  struct dirent *dir;
  d = opendir(".");

  if(d)
  {
    i = 0;
    while((dir = readdir(d)) != NULL)
    {
      listDetails[i].sn   = i;   
      listDetails[i].name = dir->d_name; 
      i++;        
    }   
    closedir(d);
    sortList(i);
    printDetails(i);
  }
}

void list_childFileNfolder(int choice)
{
   DIR *d;
   struct dirent *dir;
   d = opendir("./");
   int child_choice = choice;

   if(d)
   {
      if(child_choice < i)      
           scd = listDetails[child_choice].name; 
      else
      {
           printf(MAKE_RED_DARK"\nYour choice is %d but the list contains %d", choice, (i-1));
           printf("\nInvalid Input....Try Again...\n\n"RESET_COLOR);
          return;
       }
      closedir(d);
   }
   
   struct stat fileFoldStatus;
   stat(scd, &fileFoldStatus);

   struct passwd *own=getpwuid(fileFoldStatus.st_uid);
    
   int user_read, user_write, user_execute;
   int group_read, group_write, group_execute;
   int other_read, other_write, other_execute;
   
   if((S_ISREG(fileFoldStatus.st_mode)))
   {
        printf(MAKE_RED_DARK"\nFile Name :: %s\n"RESET_COLOR, scd);
        user_read  = ((fileFoldStatus.st_mode &S_IRUSR) ? 1 : 0);
        user_write = ((fileFoldStatus.st_mode &S_IWUSR) ? 1 : 0);
        user_execute = ((fileFoldStatus.st_mode &S_IXUSR) ? 1 : 0);
        
        group_read = ((fileFoldStatus.st_mode &S_IRGRP) ? 1 : 0);
        group_write = ((fileFoldStatus.st_mode &S_IWGRP) ? 1 : 0);
        group_execute = ((fileFoldStatus.st_mode &S_IXGRP) ? 1 : 0);
        
        other_read = ((fileFoldStatus.st_mode &S_IROTH) ? 1 : 0);
        other_write = ((fileFoldStatus.st_mode &S_IWOTH) ? 1 : 0);
        other_execute = ((fileFoldStatus.st_mode &S_IXOTH) ? 1 : 0);
        
        printf("File User  ID  = %d\n", fileFoldStatus.st_uid);
        printf("File Group ID  = %d\n", fileFoldStatus.st_gid);
        printf("File User Name = %s\n", own->pw_name);

        printPermission(user_read, user_write, user_execute, group_read, group_write, group_execute, other_read, other_write, other_execute);
        
   }
   else if(S_ISDIR(fileFoldStatus.st_mode))
   {
       printf(MAKE_RED_DARK"\nDirectory :: %s\n"RESET_COLOR, scd);
       
       DIR *dc;
       struct dirent *dirc;
       
       dc = opendir(scd);
       chdir(scd); 
       
       if(dc)
       {
          i = 0;
          while((dirc = readdir(dc)) != NULL)
          {
              //printf("\t%d\t%s\n", i, dirc->d_name);
              listDetails[i].sn   = i;   
              listDetails[i].name = dirc->d_name;   
              i++;
          }
          sortList(i);
          printDetails(i);
          closedir(dc);
       }
       
       user_read  = ((fileFoldStatus.st_mode &S_IRUSR) ? 1 : 0);
       user_write = ((fileFoldStatus.st_mode &S_IWUSR) ? 1 : 0);
       user_execute = ((fileFoldStatus.st_mode &S_IXUSR) ? 1 : 0);
        
       group_read = ((fileFoldStatus.st_mode &S_IRGRP) ? 1 : 0);
       group_write = ((fileFoldStatus.st_mode &S_IWGRP) ? 1 : 0);
       group_execute = ((fileFoldStatus.st_mode &S_IXGRP) ? 1 : 0);
        
       other_read = ((fileFoldStatus.st_mode &S_IROTH) ? 1 : 0);
       other_write = ((fileFoldStatus.st_mode &S_IWOTH) ? 1 : 0);
       other_execute = ((fileFoldStatus.st_mode &S_IXOTH) ? 1 : 0);
        
       printPermission(user_read, user_write, user_execute, group_read, group_write, group_execute, other_read, other_write, other_execute);
        
   }
   list_fileNfolder(".");
}

void sortList(int counter)
{
   listDir temp;
   int j,k;
   char *a, b[100];
   
   for(j=0; j<counter; j++)
   {
     for(k=j+1; k<counter; k++)
     {
      if(strcmp(listDetails[j].name, listDetails[k].name) > 0)
       {
           temp.name       = listDetails[j].name;
           listDetails[j].name = listDetails[k].name;
           listDetails[k].name = temp.name;
        }
      }
   }
}


void printPermission(int uread, int uwrite, int uexecute, int gread, int gwrite, int gexecute, int oread, int owrite, int oexecute)
{

  printf("\t\t       Permission Table\n"); 
  printf("\t-----------------------------------------------\n");
  printf("\t|         |   Read    |   Write   |  Execute  |\n");
  printf("\t-----------------------------------------------\n");
  printf("\t|  User   |");
   if(uread == 1) 
       printf("    Yes    |");
   else 
       printf("     No    |");
   if(uwrite == 1) 
       printf("    Yes    |");
   else 
       printf("    No     |");
   if(uexecute == 1) 
       printf("    Yes    |\n");
   else 
       printf("    No     |\n");
       
   printf("\t|  Group  |");    
   if(gread == 1) 
       printf("    Yes    |");
   else 
       printf("    No     |");
   if(gwrite == 1) 
       printf("    Yes    |");
   else 
       printf("    No     |");
   if(gexecute == 1) 
       printf("    Yes    |\n");
   else 
       printf("    No     |\n");
    
    printf("\t|  Other  |");
    if(oread == 1) 
       printf("    Yes    |");
   else 
       printf("    No     |");
   if(owrite == 1) 
       printf("    Yes    |");
   else 
       printf("    No     |");
   if(oexecute == 1) 
       printf("    Yes    |\n");
   else 
       printf("    No     |\n");
       
  printf("\t-----------------------------------------------\n");
}

void printDetails(int noOfList)
{
   int j;
   struct dirent **filelist;
   int n = scandir(".", &filelist, 0, alphasort);
  
   for(j=0; j<noOfList; j++)
   {
     struct stat filfold;
     stat(filelist[j]->d_name, &filfold);
     
     if(j == 0)
         printf("\t%d: Exit\n",j);
     else if(j == 1 )
         printf("\t%d: .. (Parent Directory)\n",j); 
     else if(S_ISREG(filfold.st_mode))
          printf("\t%d: %s(file)\n", j, filelist[j]->d_name);
     else if(S_ISDIR(filfold.st_mode))
          printf(MAKE_GREEN_DARK"\t%d: %s(folder)\n"RESET_COLOR, j, filelist[j]->d_name);    
    }                     
}
