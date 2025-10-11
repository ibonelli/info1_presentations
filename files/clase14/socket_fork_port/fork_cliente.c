// Ejemplo usando fork y sock-lib2.h + sock-lib2.c
// Modificadas para poder tomar el port y crear childs que usen distintos puertos

// Compilar con:
//              gcc -o client fork_cliente.c sock-lib2.c

#include "sock-lib2.h"

#define MAXDATASIZE 4096/* máxima cantidad de bytes que puede recibir en una transacción*/

int main(int argc, char * argv[])
{
	int sockfd;  /*File Descriptor para sockets*/
	int srv_port;
	int numbytes;/*Contendrá el número de bytes recibidos por read () */
	char buf[MAXDATASIZE];  /* Buffer donde se reciben los datos de read ()*/
	int wait;

/* Tratamiento de la línea de comandos. */
	if (argc < 2)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
        }

	if (argc == 2) {
		srv_port = htons(PORT);
	} else {
		srv_port = htons(atoi(argv[2]));
	}

	sockfd = conectar (srv_port, argv[1]);

/* Recibimos los datos del servidor */
	if ((numbytes = read (sockfd, buf, MAXDATASIZE)) == -1)
	{
		perror("error de lectura en el socket");
		exit(1);
	}

/* Visualizamos lo recibido */
	buf[numbytes] = '\0';
	printf("Recibido: %s\n",buf);
	for(wait=0;wait<10;wait++) {
		printf("."); fflush(stdout);
		sleep(1);
	}
	printf("\nTerminado el cliente con pid %d.\n", getpid());

/* Devolvemos recursos al sistema */
	close(sockfd);
	return 0;
}
