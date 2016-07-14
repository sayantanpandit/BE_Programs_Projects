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
#define BACKLOG 10 // how many pending connections queue will hold

int main(){

	char com[20];
	int sockfd, new_fd; // listen on sock_fd, new connection on new_fd
	struct sockaddr_in my_addr; // my address information
	struct sockaddr_in their_addr; // connector’s address information
	int sin_size;
	struct sigaction sa;
	int yes=1;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	
	/*if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1) {
		//perror("setsockopt");
		//exit(1);
	}*/
	
	my_addr.sin_family = AF_INET; // host byte order
	my_addr.sin_port = htons(MYPORT); // short, network byte order
	my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
	memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct
	
	if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))== -1) {
		perror("bind");
		exit(1);
	}
	
	printf("Server started with address %s\n", inet_ntoa(my_addr.sin_addr));
	
	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		exit(1);
	}

	while(1) { // main accept() loop
		sin_size = sizeof(struct sockaddr_in);
		if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr,&sin_size)) == -1) {
			perror("accept");
			continue;
		}
		
		printf("server: got connection from %s\n",inet_ntoa(their_addr.sin_addr));
	
	
		close(sockfd); // it doesn’t need the listener
			
		while(strcmp(com,"exit")){
			if (recv(new_fd, com, 20 , 0) == -1)	perror("recv");
			else printf("%s\n",com);
		}
			
		close(new_fd);
		exit(0);
	}	
	return 0;
}










