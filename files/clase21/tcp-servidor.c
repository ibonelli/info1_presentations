#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>

#define MYPORT 3490			/* Numero de puerto donde se conectaran los clientes */
#define BACKLOG 10			/* Tamaño de la cola de conexiones recibidas */
#define MAXDATASIZE 100		/* maxima cant. De bytes que se pueden enviar
								en una llamada a send */

void main(void)
{
	int sockfd;					/* El servidor escuchara por sockfd */
	int newfd;					/* Las transferencias de datos se realizar 
									mediante newfd */
	int rv;						/* Usado para el wait del server al hijo */
	char buffer[MAXDATASIZE];	/* Buffer donde se reciben los datos */
	struct sockaddr_in my_addr;	/* contendra la direccion IP y el 
									numero de puerto local */
	struct sockaddr_in their_addr;	/* Contendra la direccion IP y 
										numero de puerto del cliente */
	int sin_size;		/* Contendra el tamaño de la escructura sockaddr_in */
	int i, status=1;	/* Espera didactica */

	/*
	 * Vamos a deshabilitar Nagle's algorithm para que envie paquetes de 1byte
	 * 		https://en.wikipedia.org/wiki/Nagle%27s_algorithm
	 * 		http://www.unixguide.net/network/socketfaq/2.16.shtml
	 */
	int flag = 1, result;

	/* Crea un socket y verifica si hubo algun error */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	/* Asignamos valores a la estructura my_addr para luego poder llamar a la 
		funcion bind() */
	my_addr.sin_family = AF_INET; 
	my_addr.sin_port = htons(MYPORT);		/*debe convertirse a network byte 
												order porque es enviado por la red*/
	my_addr.sin_addr.s_addr = INADDR_ANY;	/* automaticamente usa la 
												IP local */
	bzero(&(my_addr.sin_zero), 8);  		/* rellena con ceros el resto de 
												la estructura */
	if ( bind(sockfd, (struct sockaddr *)&my_addr, 
			sizeof(struct sockaddr)) == -1) {
	perror("bind");
	exit(1);
	}

	/* Habilitamos el socket para recibir conexiones, con una cola de
	 * BACKLOG conexiones en espera como maximo */
	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		exit(1);
	}

	while(status)	/* loop que llama a accept() */
	{
		sin_size = sizeof(struct sockaddr_in);
		/* Se espera por conexiones */
		if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, 
				&sin_size)) == -1) {
			perror("accept");
			/* Si se produce un error se debe finalizar el programa */
			status = 0;
		}
		printf  ("server:  conexion desde:  %s\n", 
			inet_ntoa(their_addr.sin_addr));
		if (!fork() && status) {
			/* Aca comienza el proceso hijo */
			strcpy(buffer,"Hello, world!\n");
			if (send(newfd, buffer, strlen(buffer), 0) == -1)
				perror("send");
			/* Vamos a deshabilitar Nagle's algorithm */
			result = setsockopt(newfd,	/* socket affected */
				IPPROTO_TCP,			/* set option at TCP level */
				TCP_NODELAY,			/* name of option */
				(char *) &flag,			/* the cast is historical cruft */
				sizeof(int));			/* length of option value */
			if (result < 0)
				perror("TCP_NODELAY");
			for(i=0;i<10;i++) {
				sleep(1);
				strcpy(buffer,"SEND-WAIT-FRAME");
				if (send(newfd, buffer, strlen(buffer), 0) == -1)
					perror("send");
			}
			sleep(1);
			strcpy(buffer,"SEND-EXIT-FRAME");
			if (send(newfd, buffer, strlen(buffer), 0) == -1)
				perror("send");
			close(newfd);
			exit(0);
		}
	}

	/* El proceso padre no necesita este descriptor, solo lo utiliza el proceso hijo, en la proxima
	 * llamada a accept(), retornara con un nuevo descriptor de socket
	 */
	close(newfd);
	wait(&rv);

	// TODO - Manejar el cierre de los hijos si quedaron corriendo
	// De ./files/clase26/zombies2.txt
	//		* Opc1 - Using wait() system call
	//		* Opc2 - Ignoring the SIGCHLD signal
	//		* Opc3 - Using a signal handler (Mi opción preferida!)
}
