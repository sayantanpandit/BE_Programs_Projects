#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pfd[2];
    if(pipe(pfd) == -1)
    {
       printf("Pipe Failed");
       exit(EXIT_FAILURE);
    }
    int b = fork();  
    if(b == 0)
    {
      if(strcmp(argv[2], "/") == 0)
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
          execl(argv[3], argv[3], NULL);
          close(pfd[0]);
          exit(1);
        }
        else
        {
          close(pfd[0]);   
          dup2(pfd[1], 1); 
          execl(argv[1], argv[1], NULL);
         // wait(NULL);
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
   }
}
