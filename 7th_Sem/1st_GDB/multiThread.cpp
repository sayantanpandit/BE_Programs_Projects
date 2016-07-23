#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <array>

using namespace std;

#define NUM_THREADS     10

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}

void foo()
{
   int  *x = 0;
  *x =100;
}

void inf()
{
   while(1)
   {
      cout<< "inf" << endl;
   }
}

int main ()
{
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   int arr[] = {5,6,7,8,9,12,34,56,78};
  // cin >> arr[20]; 
   //foo();
   for( i=0; i < NUM_THREADS; i++ ){
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, 
                          PrintHello, (void *)i);
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
