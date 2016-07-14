#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <dirent.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <time.h>
#include <pwd.h>

#define RESET_COLOR "\e[m"
#define MAKE_RED_DARK "\e[1;31m"
#define MAKE_GREEN_DARK "\e[1;32m"
#define MAKE_YELLOW "\e[1;33m"

char cmd[100], history[100][100], path[100];
char letcmd[100], token[100];
int count, countSC, histCount;
int posSC[100];

void printDetails();
void pwd();
char* findPath(char *);
int countWord(char *);
int noOfSpecialChar(char *);
int whatSpecialChar(char *);
char* substring(char* ,int , int );
void removeWhiteSpace(char *);
void operation(char *);

void pipel(char  *);
void sequential(char *);
