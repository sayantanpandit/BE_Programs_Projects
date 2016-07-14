#define NUMBER_OF_ARG 10
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#define MYPORT 3490 // the port users will be connecting to
#define PORT 9034
#define BACKLOG 10 // how many pending connections queue will hold

int main(){

	char com[100];
	int sockfd, new_fd; // listen on sock_fd, new connection on new_fd
	struct sockaddr_in my_addr; // my address information
	struct sockaddr_in their_addr; // connector’s address information
	int sin_size=sizeof(their_addr);
	struct hostent *he;
	char client_addr[20];
	
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	
	
	my_addr.sin_family = AF_INET; // host byte order
	my_addr.sin_port = htons(MYPORT); // short, network byte order
	my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
	memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct
	
	
	if (bind(sockfd, (struct sockaddr *)&my_addr, sin_size)== -1) {
		perror("bind");
		exit(1);
	}
	
	printf("Server started\n");
	

	while(1) {
	
		while(strcmp(com,"exit")){
			if (recvfrom(sockfd, com, 100 , 0, (struct sockaddr*)&their_addr, &sin_size ) == -1){
				perror("recvfrom");
				exit(1);
			}
			else printf("%s\n",com);
		}
			
		close(new_fd);
		exit(0);
	}	
	return 0;
}
