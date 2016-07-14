#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N  5

int main( void )
{


int unsorted[N] , bucket[10][N]={{0}} , sorted[N] ;
int   j , k , m , p , flag = 0 ;

srand(time(NULL));

for(k=0 ;  k < N ; k++)
{
  sorted[k] = unsorted[k] = rand()%1000; 
  printf("%d", unsorted[k]);
}


for(p=1; flag != N ; p*=10){

flag = 0;

for(k=0;k<N;k++){
bucket[(sorted[k]/p)%10][k] = sorted[k];
if ( (sorted[k]/p)%10  == 0 ){
   flag++;
   }
}

if (flag == N){
   printf("");
   for(j=0 ;  j < N ; j++){
   printf("%d", sorted[j]);
   }
   return(EXIT_SUCCESS);
   }

for(j=0,m=0;j<10;j++){
for(k=0;k<N;k++){
if( bucket[j][k] > 0 ){
  sorted[m] = bucket[j][k];
  bucket[j][k] = 0 ;
  m++;
  }
}
}

}

return EXIT_SUCCESS ;
}

