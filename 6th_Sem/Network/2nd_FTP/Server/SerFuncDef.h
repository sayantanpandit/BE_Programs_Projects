#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <dirent.h>

#define RESET_COLOR       "\e[m"
#define MAKE_RED_DARK     "\e[1;31m"
#define MAKE_GREEN_DARK   "\e[1;32m"
#define MAKE_YELLOW       "\e[1;33m"
#define MAKE_MAGENTA_DARK "\e[1;35m"
#define MAKE_CYAN_DARK    "\e[1;36m"

// Function Defination 
void error(char *msg);

void dostuff(int); 
void get(char *, int);
void put(char *, int);
void getall(char*, int);
void cd(char* , int);
void ls(int);
void pwd(int );
