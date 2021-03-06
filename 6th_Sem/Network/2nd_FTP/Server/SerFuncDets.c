#include "SerFuncDef.h"

void get(char *arg, int sock)
{
	int fd,n,n1;
	char buffer[256], chk[256];
	fd=open(arg,O_RDONLY);
   	if (fd<0)
   	{
   		n = write(sock,"unopen",6);
   		printf("ERROR opening file\n");
   		return;
   	}	
   	n = write(sock,"opened",6);
   	if (n<0) 
   	     perror(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
   	printf("CREATED\n");
	bzero(buffer,256);
	n = read(sock,buffer,7);
   	
   	if(strcmp(buffer,"created"))
   		return;
   	printf(MAKE_GREEN_DARK"DOWNLOADING to CLIENT %s\n"RESET_COLOR,buffer);	
   	bzero(buffer,256);
   	n = read(fd,buffer,100);
   	while(n>0)
   	{
   	    if(n<100)
   	    {
   		n1 = write(sock,buffer,n);
   		bzero(chk,255);
		n = read(sock,chk,8);
   		if(!strcmp(chk,"received"))
   			printf("SENT %d BYTES\n",n1);
   		break;
   	    }
   	    else
   		n = write(sock,buffer,100);
   	    if (n < 0) 
   	       error("ERROR writing to socket");
   	    
   	    bzero(chk,255);
	    n = read(sock,chk,8);
   	    if(!strcmp(chk,"received"))
   		  printf("SENT 100 BYTES\n");
   	    bzero(buffer,256);
   	    n = read(fd,buffer,100);
   	}
   	n = write(sock,"EOF",100);
   	if (n < 0) 
   	   error(MAKE_RED_DARK "ERROR Writing to socket"RESET_COLOR);
   	close(fd);
}

void put(char *arg, int sockfd)
{
   int fd, n;
   char buffer[256],filename[256];
   strcpy(filename,arg);
   do
   {
	bzero(buffer,256);
    	n = read(sockfd,buffer,6);
   }while(n<0);
    
    if((n>0)&&(strcmp(buffer,"opened")))
    {
    	printf("ERROR opening file %s\n",arg);
    	return;
    }
    printf("File opened in client\n");
    fd=creat(filename, 0666);
    if(fd<0)
    {
    	printf("File can't be created\n");
    	n = write(sockfd,"ncreate",7);
    	return;
    }
    n = write(sockfd,"created",7);
    printf(MAKE_YELLOW"Uploading in server...\n"RESET_COLOR);
    bzero(buffer,256);
    n = read(sockfd,buffer,100);
   
    int i=0;
    while((n>0) && strcmp(buffer,"EOF"))
    {    	
    	if(!strcmp(buffer,"EOF")) 
    	   break;
    	if(n<100)
    		n = write(fd,buffer,strlen(buffer));
    	else
    		n = write(fd,buffer,100);
    	//printf("%s\n",buffer);
    	printf("RECEIVED %d BYTES\n",n);
    	n = write(sockfd,"received",8);
    	do
    	{
    		bzero(buffer,256);
    		n = read(sockfd,buffer,100);
    	}while(n<=0);	
    }
    printf(MAKE_GREEN_DARK"UPLOADING COMPLETED SUCCESSFULLY\n"RESET_COLOR);   
    write(sockfd,"UPLOADING COMPLETED SUCCESSFULLY",50);  
    return;  
}

void getall(char* arg, int sock)
{
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	char extn[10], *occur, buffer[256];
	int n;
	//printf("in get all\n");
	n = write(sock,"start",255);
		if(n<0) error("ERROR writing to socket");
	do
	{
		bzero(buffer,256);
		n = read(sock,buffer,9);
	}while(strcmp(buffer,"received"));
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			printf("%s\n",dir->d_name);
			occur=strchr(dir->d_name,'.');
			if(occur==NULL)
				continue;
			bzero(extn,10);
			strcpy(extn,occur);
			if(!strcmp(extn,arg+1))
			{
				printf("%s\n",dir->d_name);
				n = write(sock,dir->d_name,255);
				if(n<0) error("ERROR writing to socket");
				do
				{
					bzero(buffer,256);
					n = read(sock,buffer,9);
				}while(strcmp(buffer,"received"));
				printf(MAKE_GREEN_DARK"FILE RECEIVED\n"RESET_COLOR);
				get(dir->d_name,sock);
				do
				{
					bzero(buffer,256);
					n = read(sock,buffer,9);
				}while(strcmp(buffer,"nextfile"));
				printf("next %s\n",extn);
			}	
			printf(MAKE_YELLOW"NEXT FILE\n"RESET_COLOR);
		}
		closedir(d);
	}
	n = write(sock,"over",255);
	if(n<0) 
	  error("ERROR writing to socket");
	printf(MAKE_GREEN_DARK"COMPLETED\n"RESET_COLOR);
	return;
}

void cd(char* path, int sock)
{
	int n;
	char oldpath[256],newpath[256],signal[10],home[256];
	bzero(oldpath,256);
	bzero(newpath,256);
	bzero(signal,10);
	getcwd(oldpath,sizeof(oldpath));
	n = write(sock,oldpath,255);
	if(n<0) 
	     error("ERROR writing to socket");
	printf("%s oldpath\n",oldpath);
	bzero(signal,10);
	n = read(sock,signal,8);
	if(!strcmp(signal,"received"))
		printf(MAKE_RED_DARK"RECEIVED OLDPATH\n"RESET_COLOR);
	if(path==NULL)
	{
		strcpy(home,getenv("HOME"));
		n = chdir(home);
	}	
	else
		n = chdir(path);
	if(n == -1)
		printf("ERROR dir cant be changed\n");
	getcwd(newpath,sizeof(newpath));
	n = write(sock,newpath,255);
	if(n<0) 
	     error("ERROR writing to socket");
	bzero(signal,10);
	n = read(sock,signal,8);
	if(!strcmp(signal,"received"))
		printf(MAKE_GREEN_DARK"RECIEVED NEWPATH\n"RESET_COLOR);
	return;
}

void ls(int sock)
{
	int n;
	char signal[10], path[256], dirname[256];
	DIR *d;
	struct dirent *dir;
	bzero(path,256);
	getcwd(path,sizeof(path));
	d = opendir(path);
	//printf("in lls\n");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			printf("%s\n", dir->d_name);
			bzero(dirname,255);
			strcpy(dirname,dir->d_name);
			n = write(sock,dirname,255);
			if(n<0) 
			    error("ERROR writing to socket");
			do
			{
			  bzero(signal,10);
			  n = read(sock,signal,8);
			}while(strcmp(signal,"received"));
			
			if(!strcmp(signal,"received"))
				printf("received\n");
		}
	    closedir(d);
	}
	n = write(sock,"over",255);
	if(n<0) 
	    error("ERROR writing to socket");
	printf("over\n");
	return;
}

void pwd(int sock)
{
   int n;
   char dirPath[256], getPath[256];
   bzero(dirPath, 256);
   bzero(getPath, 256);
   
   getcwd(dirPath, sizeof(dirPath)); 
   
   printf("dirPath :: %s\n", dirPath);     
   n = write(sock,dirPath, 255);
   
   return;
}
