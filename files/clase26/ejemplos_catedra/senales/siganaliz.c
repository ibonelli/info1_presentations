#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int fdout;

void multisignal_hand(int senial)
{
  char m[256];
  sprintf (m,"Llego señal:%d\n",senial);
  printf("%s",m);		// mensaje por stdout
  write (fdout,m,strlen(m));	// mensaje por archivo de log
  return;
}

//************************************************************
int main(void)
{
  int i;
  //archivo para loguear actividad
  fdout = open("signals.log", O_WRONLY | O_CREAT);
  //instalo signal handlers
  for (i=1;i<32;i++)
  {
    if (i==9 || i==19) 
      i++;
    // las 9 y 19 son SIGKILL y SIGSTOP, no se pueden trapear
    if (signal(i, multisignal_hand) == SIG_ERR )
    {
      perror ("signal");
      exit (1);
    }
  }
  printf("Listo para comenzar a recibir señales...camon! hit me..!\n");
  while (1)
    sleep(1);
  return(0);
}