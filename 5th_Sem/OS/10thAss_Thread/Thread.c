#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t barrier1;

int num_threads, sum=0, prod=1;
char filelist[20][20];

void *FileCreation(void *arg)
{
   int num,val; FILE *fp;
   char *args = (char *)arg;
   
   pthread_mutex_lock(&mutex1);       
     fp = fopen(args, "w");
     fclose(fp); 
   pthread_mutex_unlock(&mutex1);
   
   pthread_barrier_wait(&barrier1);
  
   fp = fopen(args, "w");
   fprintf(fp, "%d", rand()%10);
   fclose(fp); 
   
   return 0;
}

void *Calculation(void *args)
{
  FILE *fp; int i=0; char num[10];
  while(i < num_threads)
  {
    if(strcmp(args, "+") == 0)
    {
      fp = fopen(filelist[i++], "r");
      fread(num, 3, 1, fp);
      sum = sum + atoi(num);
      fclose(fp);
    }
    else if(strcmp(args, "*") == 0)
    {
      fp = fopen(filelist[i++], "r");
      fread(num, 3, 1, fp);
      prod = prod * atoi(num);
      fclose(fp);
    }
  }
}

int main (int argc, char *argv[])
{
    num_threads = argc-2; 

    if (num_threads > 0) 
    {
       pthread_t threads[num_threads]; 
       int errorChk; long t;

       errorChk = pthread_barrier_init(&barrier1, NULL, num_threads);
       if(errorChk) 
       {
          fprintf(stderr, "pthread_barrier_init: %s\n", strerror(errorChk));
          exit(1);
       }

       for (t = 0; t<num_threads; t++) 
       {
          strcpy(filelist[t], argv[t+1]);
          errorChk = pthread_create(&threads[t], NULL, FileCreation, (void *) argv[t+1]);
          if (errorChk) 
          {
            printf("Error - Return Code ::  %d\n", errorChk);
            exit(-1);
          }
        }
          
        for (t = 0; t < num_threads; t++) 
            pthread_join(threads[t], NULL);
   
        errorChk = pthread_create(&threads[t], NULL, Calculation, (void *) argv[t+1]); 
        pthread_join(threads[t], NULL);

        if(strcmp(argv[t+1], "+") == 0)
           printf("Sum :: %d\n", sum);
        else if(strcmp(argv[t+1], "*") == 0)
           printf("Product :: %d\n", prod);                      
    }
    else 
    {
        printf("Error   :: Invalid Parameters\n");
        printf("Example :: ./Execute FileName1...N Operation\n");
        exit(-1);
    }
    return 0;
}
