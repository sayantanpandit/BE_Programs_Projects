#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

union semun
{
  int val;
  struct semid_ds *buf;
  ushort *array;
}arg;

int main()
{
   key_t key = 8000;
   int semid, nsems = 1, nsops = 2; 
   int retval;
   //struct sembuf *sops = (struct sembuf *)malloc(2*sizeof(struct sembuf));
   struct sembuf sops[2];
    
   semid = semget(key, nsems, IPC_CREAT | 0666);
   
   if(semid < 0)
   {
     printf("Unable to allocate memory!!!\n");
   }
   
   printf("Program semb about to do a P-operation. \n");
   printf("Process id is %d\n", getpid());
   
   sops[0].sem_num = 0;
   sops[0].sem_op  = -1;
   sops[0].sem_flg = 0;
   arg.val = 1;
   
   if(semctl(semid,0, SETVAL,arg) < 0)
     perror("semctl");
   
   retval = semop(semid, sops, 1);
   if(retval == 0)
      printf("Successful V-operation by program semb. \n");
   else
      printf("sema: V-operation did not succeesd. \n");
}
