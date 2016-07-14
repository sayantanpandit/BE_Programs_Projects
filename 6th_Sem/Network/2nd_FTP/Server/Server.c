/* A simple server in the internet domain using TCP
   The port number is passed as an argument 
   This version runs forever, forking off a separate 
   process for each connection
   gcc server2.c -lsocket
*/

#include "SerFuncDef.h"

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno, clilen, pid;
     struct sockaddr_in serv_addr, cli_addr;

     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     while (1) 
     {
         newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
         if (newsockfd < 0) 
             error("ERROR on accept");
         pid = fork();
         if (pid < 0)
             error("ERROR on fork");
         if (pid == 0)  
         {
             close(sockfd);
             dostuff(newsockfd);
             exit(0);
         }
         else 
            close(newsockfd);
     } /* End of while */
     return 0; 
}

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void dostuff (int sock)
{
   int n, fd;
   char buffer[256], command[256], arg[256], *occur, path[256];
   do
   {
   		bzero(buffer,256);
   		n = read(sock,buffer,255);
   }while(n<0);
   
   while(strcmp(buffer,"exit\n"))
   {   
      bzero(command,256);
      if(!strcmp(buffer,"ls\n"))
    	  ls(sock);
      else if(!strcmp(buffer,"pwd\n"))
    	  pwd(sock);
      else if(!strcmp(buffer,"cd\n"))
    	  cd(NULL,sock);	
      else
      {	
   	occur=strchr(buffer,' ');
   	strcpy(command,buffer);
   	occur=strchr(command,' ');
   	*occur='\0';
   	strcpy(arg,occur+1);
   	occur=strchr(arg,'\n');
   	*occur='\0';   	   	
   	
   	if(!strcmp(command,"get"))
   		get(arg,sock);
   	if(!strcmp(command,"put"))
   		put(arg,sock);
   	if(!strcmp(command,"getall"))
   		getall(arg,sock);
        if(!strcmp(command,"cd"))
    	        cd(arg,sock);    	
     }
     do
     {
   	bzero(buffer,256);
	bzero(path,256);
	printf("Waiting\n%s\n",getcwd(path,255));
   	n = read(sock,buffer,255);
     }while(n<0);
   }
   n = write(sock,"Closing connection",18);
   return;
}
