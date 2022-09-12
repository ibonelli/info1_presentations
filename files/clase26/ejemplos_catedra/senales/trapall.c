#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int sig)
{
  printf ("Se ha recibido la señal %d, cuyo comportamiento default.... cambió ;)\n",sig);
  return;
}

int main (int argc, char * argv[])
{
  if (argc < 2 )
  {
    printf ("Cantidad insuficiente de argumentos\nUso: noint [nro-señal]\n");
    exit (1);
  }
  /**
  Modificamos el handler de la señal recibida como argumento.*/
  if (signal(atoi(argv[1]),handler) == SIG_ERR)
  {
    printf ("No se puede trapear la señal %d\n", atoi(argv[1]));
    exit (1);
  }
  while (1)
    sleep(1);
  return;
}