/*-------------- cliente.c -------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 3490			/* El puerto donde se conectara, servidor */
#define MAXDATASIZE 100		/* Máxima cantidad de bytes que se pueden recibir
							en una llamada a recv */

int main(int argc, char *argv[]) 
{
	int sockfd, numbytes;	/* Contendra el numero de bytes recibidos
								despues de llamar a recv() */
	char buf[MAXDATASIZE];	/* Buffer donde se reciben los datos */
	struct hostent *he;		/* Se utiliza para convertir el nombre del
								host a su direccion IP */
	struct sockaddr_in their_addr;	/* direccion del server donde se
										conectara */
	int i;					/* Espera didactica */

	/* Tratamiento de la linea de comandos. */
	if (argc != 2) {
		fprintf(stderr,"usage: client hostname\n");
		exit(1);
	}

	/* Convertimos el nombre del host a su direccion IP */
	if ((he=gethostbyname(argv[1])) == NULL) {
		herror("gethostbyname");
		exit(1);
	}

	/* Creamos el socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	/* Establecemos their_addr con la direccion del server */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(PORT);
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

	/* Intentamos conectarnos con el servidor */
	if (connect(sockfd, (struct sockaddr *)&their_addr,
				sizeof(struct sockaddr)) == -1) {
		perror("connect");
		exit(1);
	}

	/* Recibimos los datos del servidor */
	if ((numbytes=recv(sockfd, buf, MAXDATASIZE, 0)) == -1) {
		perror("recv");
		exit(1);
	}

	/* Visualizamos lo recibido */
	buf[numbytes] = '\0';
	printf("Recibido: %s\n",buf);

	i=1;
	/*
	 * Por un buffer de printf() debo hacer lo siguiente
	 * 		http://stackoverflow.com/questions/1716296/why-does-printf-not-flush-after-the-call-unless-a-newline-is-in-the-format-strin
	 */
	setbuf(stdout, NULL);	/* Lo mismo que hacer fflush() */

	/* Luego de recibir me quedo esperando... */
	while(i==1) {
		recv(sockfd, buf, MAXDATASIZE, 0);
		if(!strcmp(buf,"SEND-EXIT-FRAME")) {
			i=0;
		} else {
			if(!strcmp(buf,"SEND-WAIT-FRAME")) {
				//printf(".\n");
				printf(".");
			} else {
				printf("Error recepcion...\n");
				i=0;
			}
		}
	}
	printf("Termino!\n");

	/* Devolvemos recursos al sistema */
	close(sockfd);
	return 0;
}
