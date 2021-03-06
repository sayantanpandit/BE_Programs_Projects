#include "CliFuncDef.h"

void error(char *msg)
{
    perror(msg);
    exit(0);
}

void getfile(char *arg, int sockfd)
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
    printf("File opened in server %s\n",buffer);
    fd=creat(filename, 0666);
    if(fd<0)
    {
		printf("ERROR!!! File cannot be created\n");
		n = write(sockfd,"ncreate",7);
		if(n<0) 
		   perror("ERROR writing to socket");
		return;
    }
    n = write(sockfd,"created",7);
    if (n<0) 
        printf("ERROR writing to socket");
    int i=0;
    do
    {
    	bzero(buffer,256);
    	n = read(sockfd,buffer,100);
    }while(n<0);
    
    while((n>0) && strcmp(buffer,"EOF"))
    {
    	//printf(": %s\n",buffer);
    	if(!strcmp(buffer,"EOF")) 
    	     break;
    	if(n<100)
    		n = write(fd,buffer,strlen(buffer));
    	else 
    		n = write(fd,buffer,100);
    	printf("RECEIVED %d BYTES\n",n);
    	n = write(sockfd,"received",8);
    	do
    	{
    		bzero(buffer,256);
    		n = read(sockfd,buffer,100);
    	}while(n<=0);	
    }
    printf(MAKE_GREEN_DARK"DOWNLOADED SUCCESSFULLY\n"RESET_COLOR);  
    return;  
}

void mgetfile(char *arg, int sock)
{
	//printf("sock%d\n",sock);
	int n, i=0;
	char signal[10], filename[256], temp[256], *occur;
	//bzero(signal, 256);
	//printf("sock%d\n",sock);
	do
	{
		bzero(filename,256);
		strcpy(filename,arg);
		occur=strchr(filename,' ');
		if(occur==NULL)
		{
			printf("WRONG COMMAND\n");
			break;
		}
		*occur='\0';
		occur=strchr(arg,' ');
		if(occur==NULL)
		{
			printf("WRONG COMMAND\n");
			break;
		}
		occur++;
		strcpy(arg,occur);
		//printf("%d.filename=%s arg=%s\n",i++,filename,arg);
		bzero(temp,256);
		strcpy(temp,"get ");
		strcat(temp,filename);
		strcat(temp,"\n");
		printf("%s\n",temp);
		n = write(sock,temp,255);
		if (n<0) 
		    error("ERROR writing to socket");
		//printf("before call %s %d_\n",filename,sock);
		getfile(filename, sock);
		//printf("after call\n");
		occur=strchr(arg,' ');
	}while(occur!=NULL);
	bzero(temp,256);
	strcpy(temp,"get ");
	strcat(temp,arg);
	strcat(temp,"\n");
	printf("%s\n",temp);
	n = write(sock,temp,255);
	if (n<0) 
	    error("ERROR writing to socket");
	getfile(arg, sock);
	printf(MAKE_GREEN_DARK"DOWNLOADING COMPLETED!!!\n"RESET_COLOR);
	return;
}

void getall(char *arg, int sock)
{
	int n, count=0;
	char buffer[256], filename[20];
	do
	{
		bzero(buffer,256);
		n = read(sock,buffer,255);
	}while(strcmp(buffer,"start"));
	n = write(sock,"received",9);
		if(n<0) error("ERROR writing to socket");
	do
	{
		do
		{
			bzero(buffer,256);
			n = read(sock,buffer,255);
		}while(n<=0);
		//printf("%s, bufflen %d bytes read %d\n",buffer,(int)strlen(buffer),n);
		if(!strcmp(buffer,"over"))
		{
			printf("DOWNLOADING COMPLETED...\n");
			break;
		}	
		n = write(sock,"received",9);
			if(n<0) error("ERROR writing to socket");
		bzero(filename,20);
		strcpy(filename,buffer);
		getfile(buffer,sock);
		count++;
		n = write(sock,"nextfile",9);
			if(n<0) error("ERROR writing to socket");
		printf("nextfile\n");
	}while(1);
	printf("No. of Files Downloaded :: %d\n",count);
	return;
}

void putfile(char *arg, int sock)
{
	int fd,n,n1;
	char buffer[256], chk[10];
	fd=open(arg,O_RDONLY);
   	if (fd<0)
   	{
   		n = write(sock,"unopen",6);
   		printf("ERROR opening file\n");
		return;
	}
	n = write(sock,"opened",6);
   	if (n<0) 
   	     perror("ERROR writing to socket");
   	printf("Opened\n");
   	do
   	{
   		bzero(buffer,256);
   		n = read(sock,buffer,7);
   	}while(n<0);
   	if(strcmp(buffer,"created"))		
   		return;

   	printf(MAKE_YELLOW"Transferring file to Server ...\n"RESET_COLOR);
   	bzero(buffer,256);
   	n = read(fd,buffer,100);
   	while(n>0)
   	{
   		if(n<100)
   		{
   			n1 = write(sock,buffer,n);
   			bzero(chk,10);
   			n = read(sock,chk,8);
   			if(!strcmp(chk,"received"))
   			     printf(MAKE_GREEN_DARK"SEND SUCCESSFULLY\n"RESET_COLOR);
   			break;	
   		}
   		else
   			n = write(sock,buffer,100);
   		if (n < 0) error("ERROR writing to socket");
   		printf("Sent %d bytes\n",n);
   			bzero(chk,10);
   			n = read(sock,chk,8);
   		if(!strcmp(chk,"received"))
   			printf(MAKE_GREEN_DARK"SEND SUCCESSFULLY\n"RESET_COLOR);
   		//printf("chk=%s\n",chk);
   		bzero(buffer,256);
   		n = read(fd,buffer,100);
   	}
   	n = write(sock,"EOF",100);
   	if (n < 0) 
   	    error(MAKE_RED_DARK"ERROR writing to socket after finish"RESET_COLOR);
   	bzero(buffer,256);
   	n = read(sock,buffer,50);
   	printf(MAKE_GREEN_DARK"%s\n"RESET_COLOR,buffer);
   	if (n < 0) 
   	     error(MAKE_RED_DARK"ERROR reading from socket after finish"RESET_COLOR);
   	close(fd);
}

void mputfile(char *arg, int sock)
{
	char sing_arg[256], temp[256], signal[10],*occur;
	int i=0,n;
	do
	{
		bzero(sing_arg,256);
		strcpy(sing_arg,arg);
		occur=strchr(sing_arg,' ');
		if(occur==NULL)
		{
			printf(MAKE_RED_DARK"WRONG COMMAND\n"RESET_COLOR);
			break;
		}
		*occur='\0';
		occur=strchr(arg,' ');
		if(occur==NULL)
		{
			printf(MAKE_RED_DARK"WRONG COMMAND\n"RESET_COLOR);
			break;
		}		
		occur++;
		strcpy(arg,occur);
		
		bzero(temp,256);
		strcpy(temp,"put ");
		strcat(temp,sing_arg);
		strcat(temp,"\n");
		printf("temp :%s_\n",temp);
		n = write(sock,temp,255);
		if (n<0) 
		   error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
		putfile(sing_arg,sock);
		occur=strchr(arg,' ');
	}while(occur!=NULL);	
	//printf("%d.sing arg=%s arg=%s\nout\n",i,sing_arg,arg);
	bzero(temp,256);
	strcpy(temp,"put ");
	strcat(temp,arg);
	strcat(temp,"\n");
	//printf("temp=%s_\n",temp);
	n = write(sock,temp,255);
	if (n<0) 
	   error("ERROR writing to socket");
	putfile(arg,sock);
	printf(MAKE_GREEN_DARK"UPLOADED SUCCESSFULLY\n"RESET_COLOR);
	return;
}

void putall(char* arg, int sock)
{
	int n, count = 0;
	char buffer[256], extn[10], *occur;
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			//printf("%s\n", dir->d_name);
			occur=strchr(dir->d_name,'.');
			if(occur==NULL)
				continue;
			bzero(extn,10);
			strcpy(extn,occur);
			if(!strcmp(extn,arg+1))
			{
				bzero(buffer,256);
				strcpy(buffer,"put ");
				strcat(buffer,dir->d_name);
				strcat(buffer,"\n");
				n = write(sock,buffer,255);
				if (n<0) 
				   error("ERROR wriring to socket");
				putfile(dir->d_name,sock);
				count++;
			}
		}
	    closedir(d);
	}
	printf("No. of Files sent: %d\n",count);
}

void cd(char *path)
{
	int n;
	char newpath[100], home[100];
	if(path==NULL)
	{
		strcpy(home,getenv("HOME"));
		n = chdir(home);
	}	
	else
		n = chdir(path);
	if(n == -1)
		printf("ERROR dir cant be changed\n");
	else
	{
		getcwd(newpath,sizeof(newpath));
		printf(MAKE_GREEN_DARK"Changed directory %s\n"RESET_COLOR,newpath);
	}
	return;
}

void ls()
{
  /*DIR *d; int count=1;
  struct dirent *dir;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%d>\t%s\n",count++, dir->d_name);
    }
    closedir(d);
  }*/
  struct dirent **cdir;
  int m = scandir(".",&cdir,0,alphasort),i=2; char dirFile[256];
  printf(MAKE_GREEN_DARK"Present Working Directory: %s\n\n"RESET_COLOR, getcwd(dirFile, sizeof(dirFile)));  
  printf("1> .. \t\t(Parent Directory)\n"); 
  while(i<m)
  {
	printf("%d> %s ",i,cdir[i]->d_name);
	if(cdir[i]->d_type==DT_DIR)	
	      printf(MAKE_YELLOW"(directory)\n"RESET_COLOR);
	else			
	      printf(MAKE_GREEN_DARK"(file)\n"RESET_COLOR);        
	      i++;
   }
}

void ccd(int sock)
{
	int n;
	char oldpath[256], newpath[256];
	bzero(oldpath,256);
	n = read(sock,oldpath,255);
	if (n<0) 
	    error(MAKE_RED_DARK"ERROR reading from socket"RESET_COLOR);
	printf(MAKE_RED_DARK"Old Path :: %s\n"RESET_COLOR,oldpath);
	n = write(sock,"received",8);
	if(n<0) 
	    error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
	bzero(newpath,256);
	n = read(sock,newpath,255);
	if (n<0) 
	    error(MAKE_RED_DARK"ERROR reading from socket"RESET_COLOR);
	printf(MAKE_GREEN_DARK"New Path :: %s\n"RESET_COLOR,newpath);
	n = write(sock,"received",8);
	if(n<0) 
	    error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
	return;
}

void lls(int sock)
{
	int n, count = 1;
	char buffer[256];
	//printf("%d in lls\n",sock);
	do
	{
		bzero(buffer,256);
		n = read(sock,buffer,255);
	}while(n<0);
	do
	{
		if(!strcmp(buffer,"over"))
			break;
		
		printf("%d>\t%s\n", count++, buffer);
		n = write(sock,"received",8);
		if(n<0) 
		   error("ERROR writing to socket");
		do
		{
		  bzero(buffer,256);
		  n = read(sock,buffer,255);	
		}while(n<0);
	}while(1);
	return;	
}

void serPwd(int sock)
{
   int n;   
   char buffer[256];
   bzero(buffer,256);
   n = read(sock,buffer,255);
   if(n<0)
        error("ERROR reading from socket");
   printf(MAKE_GREEN_DARK"Present Working Directory-Server \n%s\n"RESET_COLOR, buffer);  
}
