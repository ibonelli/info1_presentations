#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/**
    Parametros para print_function.
*/
struct char_print_parms
{
/** El caracter a presentar. */
  char	character;
/** Número de veces que se va a presentar. */
  int	count;
/** Delay en segundos entre un caracter y el siguiente. */
  int	delay;
};

/**
  Imprime por stderr una cantidad de caracteres dados por param, que es finalmente un puntero a  una struct char_print_parms. 
*/
void* char_print (void* parameters)
{
/** Casteamos el puntero para usar el tipo correcto. */
  struct char_print_parms* p = (struct char_print_parms*) parameters;
  int i;
  for (i = 0; i < p->count; ++i)
  {
    fputc (p->character, stderr);
    sleep (p->delay);
  }
  return NULL;
}

/**
  Programa Principal
*/
int main ()
{
  pthread_t thread1_id;
  pthread_t thread2_id;
  struct char_print_parms thread1_args;
  struct char_print_parms thread2_args;
  
/** Crea un nuevo thread para imprimir 5 ’x’s una cada 10 segundos. */
  thread1_args.character = 'x';
  thread1_args.count = 5;
  thread1_args.delay = 10;
  pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
  
/** Crea un nuevo thread para imprimir 2 o’s. cada 20 segundos */
  thread2_args.character = 'o';
  thread2_args.count = 2;
  thread2_args.delay = 20;
  pthread_create (&thread2_id, NULL, &char_print, &thread2_args);

/**Comentar las dos líneas siguientes para ver el sincronismo*/  
/** Esta línea se asegura que el primer thread haya finalizado. */
  pthread_join (thread1_id, NULL);
/** Esta línea se asegura que el segundo thread haya finalizado. */
  pthread_join (thread2_id, NULL);
/** ahora podemos salir de manera segura ;). */

  return 0;
}
