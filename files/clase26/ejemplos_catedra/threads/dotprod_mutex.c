/**
*************************************************************************
* \file: dotprod_mutex.c
* \details:Ilustra el usode variables mutex en programas de threads.
Efectúa un producto de puntos. Los datos principales están en una esructura global. Cada thread trabaja sobre una parte diferente de los datos. El thread principal solo espera a que todos completen su cálculo e imprime el resultado de la suma
*************************************************************************
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/**   
La siguiente extructura contiene la iformación necesaria para permitir la información necesaria para que la función dotprod acceda a sus datos de entrada y coloque sus resultados.
*/

typedef struct 
 {
   double      *a;
   double      *b;
   double     sum; 
   int     veclen; 
 } DOTDATA;

/** 
Define variables y un mutex */

#define NUMTHRDS 4
#define VECLEN 100
   DOTDATA dotstr; 
   pthread_t callThd[NUMTHRDS];
   pthread_mutex_t mutexsum;

/**
La función dotprod se activa cuando se crea el thread.
Obtiene su entrada desde la estructura de tipo DOTDATA, y es allí donde escribe su salida.
*/

void *dotprod(void *arg)
{
   int 		i, start, end, len ;
   long		offset;
   double	mysum, *x, *y;
   
   offset = (long)arg;
   len = dotstr.veclen;
   start = offset*len;
   end   = start + len;
   x = dotstr.a;
   y = dotstr.b;

/**
realiza el producto de puntos y asigna el resultado a la variable correspondiente de la estructura. 
*/

   mysum = 0;
   for (i=start; i<end ; i++) 
    {
      mysum += (x[i] * y[i]);
    }

/**
Toma el mutex antes de actualizar el valor en la estructura compartida,y lo libera luego de actualizar.
*/
   pthread_mutex_lock (&mutexsum);
   dotstr.sum += mysum;
   pthread_mutex_unlock (&mutexsum);

   pthread_exit((void*) 0);
}

/**
El programa principal crea los threads que hacen el trabajo y luego imprime el resultado una vez completado.
Antes de crear los threads, crea los datos de entrada. Ya que todos los threads actualizan la misma estructura se necesita un mutex para exlusión mutua. El thread principal esparará a que se completen el resto de los threads. 
Se especifica un valor de thread attribute para poder hacer el join del thread principal con los threads que éste crea. Notar además que se liberan los handles a medida que no se los necesita.
*/

int main (int argc, char *argv[])
{
  long i;
  double *a, *b;
  void *status;
  
  pthread_attr_t attr;

/** Asigna storage y valores iniciales */

  a = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));
  b = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));
  for (i=0; i<VECLEN*NUMTHRDS; i++) 
  {
    a[i]=1;
    b[i]=a[i];
  }
  
  dotstr.veclen = VECLEN; 
  dotstr.a = a; 
  dotstr.b = b; 
  dotstr.sum=0;
  
  pthread_mutex_init(&mutexsum, NULL);
         
/**
Crea los threads para hacer el dotproduct  
*/
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for(i=0;i<NUMTHRDS;i++)
  {
  /** Cada thread trabaja sobre un set of datos diferente.
   * El offset se especifica con 'i'. El tamaño de los datos
   * para cada thread se establece con VECLEN.
   */
    pthread_create(&callThd[i], &attr, dotprod, (void *)i); 
   }

  pthread_attr_destroy(&attr);
  /** Espera al retso de los threads */

  for (i=0;i<NUMTHRDS;i++)
    pthread_join (callThd[i], &status);

  /** Una vez que los juntó, imprime el resultado y deja todo "limpio" */
  printf ("Sum =  %f \n", dotstr.sum);
  free (a);
  free (b);
  pthread_mutex_destroy(&mutexsum);
  pthread_exit(NULL);
}   

