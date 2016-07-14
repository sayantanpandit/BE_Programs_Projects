#include "CliFuncDef.h"


int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256], command[256], arg[256], *occur;
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);    
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf(MAKE_RED_DARK"Start FTP Program\n"RESET_COLOR);
    printf(MAKE_YELLOW"1.Go 2. Exit\n"RESET_COLOR);
    printf(MAKE_GREEN_DARK"Enter UR Choice :: "RESET_COLOR);
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    
    while(strcmp(buffer,"exit\n"))       //Keep getting command prompt till exit
    {
        system("clear");
        printf(MAKE_GREEN_DARK"\nSN   Command Name          Syntax"RESET_COLOR);
        printf("\n--------------------------------------------------");
    	printf("\n1.      get            get  <fileName>");
    	printf("\n2.      get            get  *.<fileExtension>");
    	printf("\n3.      mget           mget <fileName> <fileName> ");    	    	    	
    	printf("\n4.      put            put  <fileName>");
    	printf("\n5.      put            put  *.<fileExtension>");
    	printf("\n6.      mput           mput <fileName> <fileName> ");    	    	    	
    	printf("\n7.      lcd            lcd  <folderName> ");
    	printf("\n8.      cd             cd   <folderName> ");    	
    	printf("\n9.      lls            lls  ");
    	printf("\n10.     ls             ls   ");
    	printf("\n11.     pwd            pwd   ");
    	printf("\n12.     lpwd           lpwd   ");
    	printf("\n13.     exit           exit\n\n\n");    	    	    	
    	
    	
    	if(!strcmp(buffer,"\n"))
    		;
    	else if(!strcmp(buffer, "go\n"))
    	     ;    	    	
    	else if(!strcmp(buffer, "pwd\n"))
    	{
    	    n = write(sockfd,buffer,255);
   	    if (n < 0) 
        	error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
	    //printf("%d\n",sockfd);            
    	    serPwd(sockfd);    	    	   
    	}
	else if(!strcmp(buffer, "lpwd\n"))
    	{
    	    char lPwd[256];
            printf(MAKE_GREEN_DARK"Present Working Directory-Client \n%s\n"RESET_COLOR, getcwd(lPwd, sizeof(lPwd)));  
    	}    	    	    	    	      	     
    	else if(!strcmp(buffer,"lcd\n"))
    		cd(NULL);	/*local cd*/
    	else if(!strcmp(buffer,"cd\n"))
    	{
    		n = write(sockfd,buffer,255);
    		if(n<0)
    		   error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
    		ccd(sockfd);		
    	}
    	else if(!strcmp(buffer,"lls\n"))
    		ls();	/*local ls*/
    	else if(!strcmp(buffer,"ls\n"))
    	{		
	     n = write(sockfd,buffer,255);
   	     if (n < 0) 
        	error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
	    // printf("%d\n",sockfd);
             lls(sockfd);
	}
    	else
    	{
    		bzero(command,256);
    		bzero(arg,256);	
    		occur=strchr(buffer,' ');
    		if(occur==NULL)
    		{
    			printf(MAKE_RED_DARK"\nEnter Command-->> "RESET_COLOR);
    			bzero(buffer,256);
    			fgets(buffer,255,stdin);
    			continue;
    		}
   		strcpy(command,buffer);
   		occur=strchr(command,' ');
   		if(occur==NULL)
    		{
    			printf(MAKE_RED_DARK"\nEnter Command-->> "RESET_COLOR);
    			bzero(buffer,256);
    			fgets(buffer,255,stdin);
    			continue;
    		}
   		*occur='\0';
   		strcpy(arg,occur+1);
   		occur=strchr(arg,'\n');
   		*occur='\0';
    		if(!strcmp(command,"get"))
    		{				
		     if((arg[0]=='*') && (arg[1]=='.'))
		     {
			bzero(buffer,256);
			strcpy(buffer,"getall ");
			strcat(buffer,arg);
			strcat(buffer,"\n");
			n = write(sockfd,buffer,255);
   			if (n < 0) 
        		    error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
			getall(arg,sockfd);
		     }
		     else
		     {
			n = write(sockfd,buffer,255);
   			if (n < 0) 
        			error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);
			getfile(arg,sockfd);
		     }
    		}
		else if(!strcmp(command,"put"))
    		{
    		    if((arg[0]=='*') && (arg[1]=='.'))
			putall(arg,sockfd);
		    else
		    {
			n = write(sockfd,buffer,255);
   			if (n < 0) 
        		   error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);			
			putfile(arg,sockfd);
		    }	
    		}
		else if(!strcmp(command,"mget"))
			mgetfile(arg,sockfd);
		else if(!strcmp(command,"mput"))
    			mputfile(arg,sockfd);
    		else if(!strcmp(command,"lcd"))
    			cd(arg);
    		else if(!strcmp(command,"cd"))
    		{
		     n = write(sockfd,buffer,255);
   		     if (n < 0) 
        		error(MAKE_RED_DARK"ERROR writing to socket"RESET_COLOR);			
		     ccd(sockfd);	
    		}
    		else
    		    	printf("Enter Command-->> ");
  	}
  	
    	printf("Enter Command-->> ");
    	bzero(buffer,256);
    	fgets(buffer,255,stdin);

    } //End of while
    
    if(!strcmp(buffer,"exit\n"))
    {
       	n = write(sockfd,buffer,255);
   	if (n < 0) 
            error("ERROR writing to socket");
            
        bzero(buffer,256);
    	read(sockfd,buffer,18);	
        printf("%s\n-----Exit-----\n",buffer);
    }
    return 0;
}
