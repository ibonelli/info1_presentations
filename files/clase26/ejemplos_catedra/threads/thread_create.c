#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
/** Imprime x’s por stderr.
    Parámetros: nada.
    Retorna: nada.
    Utilidad: Nula :). Solo para entender lo trivial....
    Compilar con  gcc -o thrd1 thread_create.c -lpthread
*/

void* print_xs (void* unused)
{
    while (1)
    {
      fputc('x', stderr);
      sleep(20);
    }
    return NULL;
}
/** Programa Principal.
*/
int main ()
{
    pthread_t thread_id;
/** Crea un nuev thread. EL nuevo thread ejecutará la función print_xs.*/
    pthread_create (&thread_id, NULL, print_xs, NULL);

/**
El programa principal se queda imprimiendo o's por sdterr
*/    
    while (1)
    {
      fputc ('o', stderr);
      sleep (20);
    }
    return 0;
}
