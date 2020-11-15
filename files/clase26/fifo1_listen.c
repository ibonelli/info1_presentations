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

	//CHEQUEAR SI EXISTE!!! (Como???)
	//if ((fd=mkfifo (FIFO_NAME, 0666))<0)
	//	fprintf (stderr, "Error creando la FIFO %s. Código de error %s\n",FIFO_NAME,strerror(fd));

	printf("Esperando un proceso escritor...\n");

	/*Este open va a bloquear el proceso si no hay ningún proceso que haya abierto la FIFO para escritura.*/

	fd = open(FIFO_NAME, O_RDONLY);

	/*Si bloquea, ni bien un proceso abra el FIFO para escritura se desbloquea este proceso y continúa con el printf siguiente*/

	printf("Conseguimos un escritor!!\n");

	do {
		if ((num = read(fd, s, 300)) == -1)
			fprintf(stderr, "Error en función read. Código de error %s\n", strerror(fd));
		else {
			s[num] = '\0';
			printf("tick: %d bytes leídos: \"%s\"\n", num, s);
		}
	} while (num > 0);

	close(fd);

	return 0;
}
