#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "info1"

int main()
{
	char s[300];
	int num, fd;

	if ((fd=mkfifo (FIFO_NAME, 0666))<0)
		fprintf (stderr, "Error creando la FIFO %s. Código de error %s\n",FIFO_NAME,strerror(fd));

	printf("Esperando lectores...\n");

	/*Este open va a bloquear el proceso si no hay ningún proceso que haya abierto la FIFO para escritura.*/

	fd = open(FIFO_NAME, O_WRONLY);

	/*Si bloquea, ni bien un proceso abra el FIFO para escritura se desbloquea este proceso y continúa con el printf siguiente*/

	printf("Encontré un lector--tipee algo\n");

	while (fgets(s,300,stdin), !feof(stdin)) 
	{
		if ((num = write(fd, s, strlen(s))) == -1)
			fprintf (stderr, "Error escribiendo en la FIFO %s. Código de error %s\n", FIFO_NAME, strerror(num));
		else
			printf("speak: %d bytes escritos\n", num);
	}
	return 0;
}
