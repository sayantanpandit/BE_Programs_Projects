#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define PORT 3490 // the port client will be connecting to
#define MYPORT 9034
#define MAXDATASIZE 100 // max number of bytes we can get at once

int main(int argc, char *argv[]){

	int i;
	char com[20];
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct hostent *he;

	struct sockaddr_in my_addr,their_addr; // connector’s address information
	if (argc != 2) {
		fprintf(stderr,"usage: client hostname\n");
		exit(1);
	}
	if ((he=gethostbyname(argv[1])) == NULL) { // get the host info
		perror("gethostbyname");
		exit(1);
	}
	
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	their_addr.sin_family = AF_INET; // host byte order
	their_addr.sin_port = htons(PORT); // short, network byte order
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	memset(&(their_addr.sin_zero), '\0', 8); // zero the rest of the struct
	

	
	while(strcmp(com, "exit")){
	
		printf("Client>>");
		
		// Take input
		i=0;
		do{
			com[i++]=getchar();
		}while(com[i-1]!='\n');
		com[i-1]='\0';
		
		if(i==1)	continue;
	
		if (sendto(sockfd, com , strlen(com)+1 , 0, (struct sockaddr*)&their_addr, sizeof(struct sockaddr)) == -1) {
			perror("sendto");
			exit(1);
		}
		
	}
	
	
	close(sockfd);
	return 0;
}











