#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_ARG			1005
#define MAX_LEN			100
#define MAX			256
#define FILE DOES NOT EXIST	"-1"
#define FILE_READ 		"2"
#define FILE_WRITTEN		"3"
#define READ			"0"
#define WRITE			"1"


void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    char arg[MAX_ARG][MAX_LEN];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct dirent **cdir; 
    char buffer[MAX];
    if (argc < 3) 
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);

    
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    char ack[20]={'\0'},req[20]={'\0'},*file,*com,*name,path[MAX]="/bin/";
    int m=0;
    while(1)
    {	
        printf(">>> ");
    	int sys=0;
    	bzero(buffer,MAX);
    	fflush(stdin);
    	char str[1000]={'\0'};
    	
    	gets(str);
    	file = strtok(str," ");
   	com = file;
   	n = write(sockfd,com,strlen(com)+1); //sending command to server
   	int flag=0,fd=0,success=0,count=0;
   	if(!strcmp(com,"get"))	//client requesting file from server
   	{
   	   flag=0;
   	   fflush(stdin);
    	   file = strtok(NULL," ");
   	   
    	   do
    	   {
    	      while(1)
   	      {
   		bzero(ack,20);
   		bzero(buffer,MAX);
   		bzero(req,20);
   		n = read(sockfd,ack,20);
   		if(!strcmp(ack,"<<ACK>>"))
   		      break;   			
   	      }
   	      printf(">>>Requesting server for %s.....\n",file);
   	      creat(file,0777);
   	      fd = open(file,O_WRONLY);	
   	      write(sockfd, "<<REQ>>",10);
   	      while(1)
   	      {
   		 n = read(sockfd,ack,20);
   		 if(!strcmp(ack,"<<ACK>>"))
   		 {
   		     write(sockfd,file,strlen(file)+1);
   		     break;
   		 }
   	      }
   	      printf("Downloading %s....\n",file);
   	      bzero(buffer,MAX);
   	      while(! (n=read(sockfd, buffer, 100)) )    
   	               printf("Empty\n");

   	      do
	      {
   		write(fd, buffer, n);
		if(n<100)	
		  break;
	      }while(n=read(sockfd, buffer, 100));		
			
	      close(fd);
	      bzero(buffer,255);
	      printf(">>>Downloading %s complete.\n",file);
	      file = strtok(NULL," ");
	      //printf(">>>Next file %s....\n",file);
    	      count++;
	      if(file!=NULL)	
	        n = write(sockfd,"<<CONTINUE>>",14);			  
	      else		
	        n = write(sockfd,"<<TERMINATE>>",14);
	   }while(file!=NULL);
			printf("%d files downloaded successfully...\n",count);
	 }
   	 else if(!strcmp(com,"put"))	//client uploading single file to server
   	 {
   	     flag=0;
   	     file = strtok(NULL," ");
    	     do{
    		bzero(ack,20);
   		bzero(buffer,MAX);
   		bzero(req,20);
    		while(1)
   		{
   		    n = read(sockfd,ack,20);
   		    if(!strcmp(ack,"<<ACK>>"))
   		    {
   			write(sockfd,file,strlen(file)+1);
   			fd = open(file,O_RDONLY);	
   			break;
   		    }
   		 }
   		
   		while(1)
   		{
   		  n = read(sockfd,ack,20);
   		  if(!strcmp(ack,"<<REQ>>"))
   			 break;
   		}
   		
   		printf(">>>Uploading %s to server.....\n",file);
   		
   		bzero(buffer,MAX);
   		n = 100;
   		while(n==100)
    		{
    		  int m = 0;
    		  bzero(buffer,100);
    		  n = read(fd,buffer,100);
    				n = write(sockfd,buffer,n);
    				if (n < 0) 
    				{
    					error("ERROR writing to socket");
    					success=1;
    					break;
    				}
  			}
			close(fd);
			printf(">>>%s uploaded to server.\n",file);
			file = strtok(NULL," ");
    			//printf(">>>Next file %s....\n",file);
    			count++;
    			while(!read(sockfd,ack,20))
    			{
    				if(!strcmp(ack,"<<OK>>"))
    					break;
    			}
			if(file!=NULL)	{n = write(sockfd,"<<CONTINUE>>",14);/*printf("hola!!!\n");*/continue;}
			else		{n = write(sockfd,"<<TERMINATE>>",14);/*printf("cola!!!\n");*/break;}
			}while(file!=NULL);
			printf("%d file(s) uploaded successfully...\n",count);
		}
		else if(!strcmp(com,"ls"))
		{
    			int m=scandir(".",&cdir,0,alphasort),i=2;
    			printf("Current working directory: %s\n",(char *)get_current_dir_name());  
    			printf("1)..(Parent Directory)\n"); 
    			while(i<m)
    			{
				printf("%d) %s",i,cdir[i]->d_name);
				if(cdir[i]->d_type==DT_DIR)	printf("(directory)\n");
				else				printf("(file)\n");        
				i++;
        		}
		}
		else if(!strcmp(com,"lls"))
		{
			bzero(buffer,MAX);
			/*while(1)
			{
				read(sockfd,ack,20);
				if(!strcmp(ack,"<<ACK>>"))
				{
					write(sockfd,"<<REQ>>",10);
					break;
				}
			}*/
			while(!read(sockfd,buffer,MAX));
			printf("Server is operating in \"%s\"\n",buffer);
			write(sockfd,"<<REQ>>",10);
			bzero(buffer,MAX);
			//while(!read(sockfd,buffer,MAX));
			printf("1)..(Parent Directory)\n");
			int i=2;
			while(1)
			{
				while(!read(sockfd,buffer,MAX));
				if(!strcmp(buffer,"<<OK>>"))
					break;
				printf("%d) %s\n",i,buffer);
				bzero(buffer,MAX);
				write(sockfd,"<<ACK>>",10);
				i++;
			}
		}
		else if(!strcmp(com,"cd"))
		{
			bzero(buffer,MAX);
			name = strtok(NULL," ");
			struct stat owner;
			stat(name,&owner);	
                   	if(S_ISDIR(owner.st_mode))
			{
                   		chdir(name);
                   		//system("clear");
		       		//opendir(ownerfer);	
                       		printf(">>>You are currently in: \"%s\"\n",(char *)get_current_dir_name());
		   	}         
		   	else if (S_ISREG(owner.st_mode))
		   	{
		   		printf(">>>ERROR : \"%s\" is a file!!!",name);
		   	}	
		   	else
		   	{
		   		printf(">>>ERROR : \"%s\" does not exist...",name);
		   	}
		}
		else if(!strcmp(com,"lcd"))
		{
			bzero(buffer,MAX);
			name = strtok(NULL," ");
			while(1)
			{
				read(sockfd,ack,10);
				if(!strcmp(ack,"<<ACK>>"))
				{
					write(sockfd,name,strlen(name));
					break;
				}	
			}
			while(!read(sockfd,buffer,MAX));
			if(!strcmp(buffer,"<<NAK>>"))
			{
				printf("ERROR : \"%s\" is a file...\n",name);
			}	
			else 	
                   		printf("Server is now in : \"%s\"\n",buffer);
		}
		else if(!strcmp(com,"exit"))
		{
			break;
		}
		else
		{
			printf("\"%s\" : Invalid command!!!\n",com);
		}
			
	}
   		//printf("%s\n",buffer);
//    }
    return 0;
}
