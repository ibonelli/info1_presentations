/**
****************************************************************************
* \file: hello32.c
* \details: Versión de "hola mundo" con Pthreads que crea muchos threads por  
por proceso. sleep() trata de que todos los threads vivan lo suficiente como 
para coexistir. Además cada thread hace algún cáculo denso para ver como el 
scheduler incide en el orden en que finalizan ;).
    Compilar con  gcc -o hola32 hola32.c -lpthread.
*****************************************************************************
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NTHREADS	32

void *Hello(void *threadid)
{
   int i;
   double result=0.0;
   sleep(5);
   for (i = 0; i < 10000; i++) 
     result = result + sin(i) * tan(i);
   printf("%ld: Hola Mundo!\n", threadid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[NTHREADS];
  int rc; 
  long t;
  for(t=0;t<NTHREADS;t++)
  {
    if (rc = pthread_create(&threads[t], NULL, Hello, (void *)t))
    {
      perror("pthread_create");
      exit(-1);
    }
   }
   printf("main(): Created %ld threads.\n", t);
   pthread_exit(NULL);
}