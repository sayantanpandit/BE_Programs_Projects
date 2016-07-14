#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <dirent.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <time.h>
#include <pwd.h>


int main()
{
   char *arr[8];
   arr[0] = "/bin";
   arr[1] = "/usr/local/bin";
   arr[2] = "/usr/sbin";
   arr[3] = "/usr/bin";
   arr[4] = "/sbin";
   arr[5] = "/usr/local/sbin";
   arr[6] = "/usr/games";
   arr[7] = "/usr/local/games";
   
   char cmd[100];
   int i,j;
   struct dirent **filelist;
   int n;
   
   while(1)
   {
      printf("codziac1:$ ");
      scanf("%[^\n]%*c", cmd);
      
      for(i=0; i<8; i++)
      {
        n  = scandir(arr[i], &filelist, 0, alphasort);
        for(j=0; j<n; j++)
        {
          struct stat filfold;
          stat(filelist[j]->d_name, &filfold);
          
          if(strcmp(cmd, filelist[j]->d_name) == 0)
            printf("%s\n", arr[i]);
        }
      }
   }
}
