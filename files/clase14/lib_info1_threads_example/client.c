// To Compile:
//		gcc -o clt client.c sock-lib.c -lpthread -Wall

#include "sock-lib.h"

#define LIMIT 5
#define MAXDATASIZE 4096 /* máxima cantidad de bytes que puede recibir en una transacción*/

int main(int argc, char * argv[])
{
	int i;
	int sockfd;   /* File Descriptor para sockets */
	int numbytes; /* Contendrá el número de bytes recibidos por read() */
	char buf[MAXDATASIZE];  /* Buffer donde se reciben los datos de read() */

	/* Tratamiento de la línea de comandos. */
	if (argc < 2) {
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
	}

	sockfd = conectar (argc, argv);

	for(i=0;i<LIMIT;i++) {
		/* Recibimos los datos del servidor */
		if ((numbytes = read (sockfd, buf, MAXDATASIZE)) == -1) {
			perror("error de lectura en el socket");
			exit(1);
		}
		/* Visualizamos lo recibido */
		buf[numbytes] = '\0';
		printf("Recibido: %s\n",buf);
	}

	/* Devolvemos recursos al sistema */
	close(sockfd);
	return 0;
}
