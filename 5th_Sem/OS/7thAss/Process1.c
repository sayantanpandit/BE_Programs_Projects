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
};

int main()
{
   key_t key = 8001;
   int semid, nsems = 2; 
   int retval;
   //struct sembuf *sops = (struct sembuf *)malloc(2*sizeof(struct sembuf));
   union semun arg;
   struct sembuf sops[2];
   arg.val = 0; 
    
   semid = semget(key, nsems, 0666 | IPC_CREAT);
   
   if(semid < 0)
   {
     printf("Unable to allocate memory!!!\n");
   }
   else
   {
     sops[0].sem_num = 0;
     sops[0].sem_op  = 1;
     sops[0].sem_flg = 1;
     
     if(semctl(semid,0, SETVAL,arg) < 0)
        perror("semctl");
        
     retval = semop(semid, sops, 1);
     if(retval == 0)
        printf("Successful V-operation by program sema. \n");
     else
     {
      printf("sema: V-operation did not succeesd. \n");
      perror("REASON");
     }   
   }
}
