#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[]) 
{
  int i=0, status = 0;
  int fd1, fd2;
  printf("\ncmdline args count=%d", argc);
  printf("\nexe name=%s\n", argv[0]);

  if((argc-1)%3 != 0)
  {
       printf("\nInvalid No. Of Argument...\n\n");
       exit(0);
  }  

  for (i=1; i< argc; i=i+3)
  {
     pid_t pid = fork();
     
     if(pid == -1)
      {
          perror("fork");
          exit(-1);
      }
      else if(pid == 0)
      {
         printf("arg%d=%s\t", i, argv[i]);
         printf("PID=%d\n",getpid());
         
         fd1 =  open(argv[i+1], O_RDONLY); 
         fd2 =  open(argv[i+2], O_WRONLY); 
         dup2(fd1, 0);
         dup2(fd2, 1);
         execl(argv[i], argv[i], NULL);
         exit(1);
      }
      else 
      {
         wait(&status);
      }
  }
}
