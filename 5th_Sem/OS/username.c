#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 

main() {
char *buf;
buf=(char *)malloc(10*sizeof(char));
getlogin_r(buf,10);
printf("\n %s \n",buf);
}
