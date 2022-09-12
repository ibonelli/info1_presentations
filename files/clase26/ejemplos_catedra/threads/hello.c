/**
****************************************************************************
* \file: hello.c
* \details "hello world" Pthreads program. Muestra como crear un thread y como terminarlo.

*****************************************************************************
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NTHREADS	10

void * Hola(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hola Mundo!Soy el thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t thread_array[NTHREADS];
  int rc;
  long t;
  for(t=0 ; t<NTHREADS ; t++)
  {
    if ((rc = pthread_create(&thread_array[t], NULL, Hola, (void *)t)))
    {
      perror("pthread_create");
      exit(-1);
    }
    printf("Programa principal: Estoy creando un thread %ld, con id %d\n", t, rc);
  }
  pthread_exit(NULL);
}
