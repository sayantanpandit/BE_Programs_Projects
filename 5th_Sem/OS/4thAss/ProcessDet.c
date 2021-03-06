#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
   int i,n, status=0; char *buff;
   printf("Enter the no. of processes :: ");
   scanf("%d", &n);
   
   for(i=1; i<=n; i++)
   {
      buff = (char *)malloc(sizeof(char) * 100);
      getcwd(buff, 100);
      pid_t pid = fork();
      
      if(pid == -1)
      {
          perror("fork");
          exit(-1);
      }
      else if(pid == 0)
      {
         printf("\n%d\tPID=%d\tPPID=%d",i,getpid(),getppid());
         printf("\tUID=%d\tEUID=%d", getuid(),geteuid());
         printf("\tGID=%d\tEGID=%d", getgid(),getegid());
         printf("\tPWD=%s\n", buff);        
         exit(1);
      }
      else 
      {
         wait(&status);
      }
   }
}
