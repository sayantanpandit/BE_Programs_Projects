#include "ShellInclude.h"

void printDetails()
{
   int j;
   struct dirent **filelist;
   int n = scandir(".", &filelist, 0, alphasort);
  
   for(j=0; j<n; j++)
   {
     struct stat filfold;
     stat(filelist[j]->d_name, &filfold);
     
     if(j == 0)
        printf(MAKE_RED_DARK"\t%d: Exit\n"RESET_COLOR,j);
     else if(j == 1 )
        printf("\t%d: .. (Parent Directory)\n",j); 
     else if(S_ISREG(filfold.st_mode))
        printf("\t%d: %s(file)\n", j, filelist[j]->d_name);
     else if(S_ISDIR(filfold.st_mode))
        printf(MAKE_GREEN_DARK"\t%d: %s(folder)\n"RESET_COLOR, j, filelist[j]->d_name);    
    }    
}

void pwd()
{
  char cwd[1024];
  if(getcwd(cwd, sizeof(cwd)) != NULL)
     printf(MAKE_RED_DARK"%s\n"RESET_COLOR, cwd);
  else
     perror("Error");
}

char* findPath(char *cmd)
{
   int i,j,n;
   struct dirent **filelist;
   char *arr[8];
   arr[0] = "/bin/";
   arr[1] = "/usr/local/bin/";
   arr[2] = "/usr/sbin/";
   arr[3] = "/usr/bin/";
   arr[4] = "/sbin/";
   arr[5] = "/usr/local/sbin/";
   arr[6] = "/usr/games/";
   arr[7] = "/usr/local/games/";
   
   for(i=0; i<8; i++)
   {
      n  = scandir(arr[i], &filelist, 0, alphasort);
      for(j=0; j<n; j++)
      {
         struct stat filfold;
         stat(filelist[j]->d_name, &filfold);
         if(strcmp(cmd, filelist[j]->d_name) == 0)
            return arr[i];
      }
   }
   return (char *)0;
}

int countWord(char *str)
{
   int i, count=1;
   while(*str)
   {
       if(*str == ' ' || *str == '\t')
           count++;
       ++str;
   }
   return count;
}

int noOfSpecialChar(char *str)
{
   int i=0, j=0, countSC=0;
   while(*str)
   {
       if(*str == '&' || *str == ';'|| *str == '!' || *str == '|' || *str == '{' || *str == '}' || *str == '(' || *str == ')')
       {
           countSC++;
           posSC[j++] = i;
       }
       ++str;
       i++;
   }
   return countSC;
}

int whatSpecialChar(char *str)
{
   
}

char *substring(char *string, int position, int length) 
{
   char *pointer;
   int c;
   pointer = malloc(length+1);
 
   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
   }
 
   for (c = 0 ; c < position -1 ; c++) 
      string++; 
 
   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *string;      
      string++;   
   }
 
   *(pointer+c) = '\0';
   return pointer;
}

void removeWhiteSpace(char *str)
{
   char *start;
   start = (char *)malloc(strlen(str)+1);
   int c = 0, d=0;
   if(start == NULL)
      exit(EXIT_FAILURE);
   while(*(str+c))
   {
      if(*(str+c) == ' ') {}
      else
      {
         *(start+d) = *(str+c);
         d++;
      }
      c++;
   }
   *(start+d) = '\0';
   strcpy(cmd, start);  
   printf("cmd=%s\n", cmd);
}

void operation(char *str)
{
   char s[2] = " ";
   //printf("cmd=%s\tstr=%s\n", cmd,str);
   if(strcmp(cmd, "exit") == 0)
      exit(1);
   else if(strcmp(cmd, "history") == 0)
   {
     int j;
     for(j=0; j<histCount; j++)
       printf("\t%d\t%s\n", (j+1), &history[j][0]);
   }
   else if(strcmp(cmd, "cd") == 0)
   {
     if(strcmp(cmd, token) == 0)
        chdir(getenv("PWD"));
     else
        chdir(strtok(NULL, s));   
   }
   else if(strcmp(cmd, "pwd") == 0)
      pwd();
   else if(count == 1)
   {
     if(fork() == 0)
        execl(path, path, NULL);
     else
        wait(NULL);
   }
   else if(count == 2)
   {
     strcpy(token, strtok(NULL, s));
     if(fork() == 0)
        execl(path, path, token, NULL);
     else
        wait(NULL);
   }
   else if(count == 3)
   {
      strcpy(token, strtok(NULL, s));  
      char token1[100];
      strcpy(token1, strtok(NULL, s));
      if(fork() == 0)
         execl(path, path, token, token1, (char *)0);
      else
          wait(NULL);
   }
   else
     printf(MAKE_RED_DARK"Command Not Found...\n"RESET_COLOR);
}
















void pipel(char *arg)
{
   //char *args[] = {"/bin/ls", "|", "/usr/bin/wc"};
  //printf("ARGS::%s\n", args);
   int i, pos=0, flag=0,len=posSC[0]; char *pointer, *SpecialChar;
   for(i=0; i<countSC; i++)
   {
      
   }
   //printf("%s\t%s\t%s\n", arg1, arg2, arg3);
    
   /*int pfd[2];
   if(pipe(pfd) == -1)
   {
       printf("Pipe Failed");
       exit(EXIT_FAILURE);
    }
    int b = fork();  
    if(b == 0)
    {
      if(strcmp(args[1], "|") == 0)
      {
        int pid = fork();
        if(pid < 0)
        {
          printf("Fork Failed");
          exit(-1);
        }
        else if (pid == 0)
        {
          close(pfd[1]);
          dup2(pfd[0], 0);
          execl(args[2], args[2], NULL);
          close(pfd[0]);
          exit(1);
        }
        else
        {
          close(pfd[0]);   
          dup2(pfd[1], 1); 
          execl(args[0], args[0], NULL);
          wait(NULL);
          close(pfd[1]); 
        }
      }
     else
     {
       printf("\nInvalid Input\nFormat : ./mainPipe exe1 / exe2\n");
     }
   }
   else
   {
       wait(NULL);
   }*/
   //printf("\n");
   exit(2);
}
