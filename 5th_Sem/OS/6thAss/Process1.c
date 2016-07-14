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
    int n1, n2;
    int *shm, shmid;
    key_t key;
 
    key = 5677;
 
    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if ((shm = (int *)shmat(shmid, NULL, 0)) == (int *) -1)
        die("shmat");    

    //Putting data into the memory for the other process to read.
    scanf("%d", &n1);
    shm[0] = n1;
    
  /*Wait until the other process changes the first character of 
    our memory to 0, indicating that it has read what we put there.*/
    while (*shm != 0)
        wait(1);
    printf("Factorial = %d\n", shm[1]);    
    shmdt(shm);
    exit(0);
}
