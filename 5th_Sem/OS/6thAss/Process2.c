#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE     27
 
void die(char *s)
{
    perror(s);
    exit(1);
}
 
int main()
{
    int shmid, *shm;
    int n1, n2,i;
    key_t key;
   
    key = 5677;
 
    if ((shmid = shmget(key, MAXSIZE, 0666)) < 0)
        die("shmget");
    if ((shm = (int *)shmat(shmid, NULL, 0)) ==  (int *)-1)
        die("shmat"); 
        
    //Now read what the server put in the memory.
    n1 = *shm, n2 = 1; 
    for(i=2; i<=n1; i++)
       n2 = n2 * i;
    shm[1] = n2;
   
    /*Change the first character of the segment to 0
      indicating we have read the segment. */
    *shm = 0;
    shmdt(shm);
    exit(0);
}
