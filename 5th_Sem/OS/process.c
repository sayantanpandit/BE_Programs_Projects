#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <dirent.h>
#include<string.h>
#include<sys/stat.h>
#include <errno.h>
void display(char *pro)
{
	char *buff;
	buff=(char *)malloc(sizeof(char)*50);
	getcwd(buff,50);
	printf("\n%s\tPID=%d\tPPID=%d\tUID=%d\tEUID=%d\tGID=%d\tEGID=%d\tCURRENT=%s\n",pro,getpid(),getppid(),getuid(),geteuid(),getgid(),getegid(),buff);
}
int main()
{
    int i,n;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    display("parent");
    for(i=0;i<n;i++)
    {
	pid_t pid=fork();
	if(pid==0)
	{		
		display("child");
		exit(0);
	}
	if (pid == -1) 
	{
      		perror("fork failed");
      		exit(EXIT_FAILURE);
   	}
	/*else if(pid>0)
	{
		display("parent");
	}*/
    }
}
