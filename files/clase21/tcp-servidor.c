#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define MYPORT 3490    /*Numero de puerto donde se conectaran los clientes*/
#define BACKLOG 10     /* Tama¤o de la cola de conexiones recibidas */
#define MAXDATASIZE 100 /* maxima cant. De bytes que se pueden enviar
						   en una llamada a send */

main()
{
	int sockfd;     /* El servidor escuchara por sockfd */
	int newfd;      /*  las transferencias de datos se realizar 
						mediante newfd */
	char buffer[MAXDATASIZE];  /* Buffer donde se reciben los datos */
	struct sockaddr_in my_addr;     /* contendra la direccion IP y el 
					numero de puerto local */
	struct sockaddr_in their_addr;  /* Contendra la direccion IP y 
					numero de puerto del cliente */
	int sin_size;   /* Contendra el tamanio de la escructura sockaddr_in */

	/* Espera didactica */
	int i;
	/*
	 * Vamos a deshabilitar Nagle's algorithm para que envie paquetes de 1byte
	 * 		https://en.wikipedia.org/wiki/Nagle%27s_algorithm
	 * 		http://www.unixguide.net/network/socketfaq/2.16.shtml
	 */
	int flag = 1, result;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) /*Crea un socket
					 y verifica si hubo algun error*/
	{
		perror("socket");
		exit(1);
	}


/* Asignamos valores a la estructura my_addr para luego poder llamar a la 
funcion bind() */
	my_addr.sin_family = AF_INET; 
	my_addr.sin_port = htons(MYPORT); /*debe convertirse a network byte 
					order porque es enviado por la red*/
	my_addr.sin_addr.s_addr = INADDR_ANY;   /* automaticamente usa la 
						IP local */
	bzero(&(my_addr.sin_zero), 8);  /* rellena con ceros el resto de 
					la estructura */
	if ( bind(sockfd, (struct sockaddr *)&my_addr, 
			sizeof(struct sockaddr)) == -1)
	{
	perror("bind");
	exit(1);
	}
/* Habilitamos el socket para recibir conexiones, con una cola de 5 conexiones en espera como
maximo */
	if (listen(sockfd, BACKLOG) == -1)
	{
		perror("listen");
		exit(1);
	}
	while(1)	/* loop que llama a accept() */
	{
		sin_size = sizeof(struct sockaddr_in);
		/* Se espera por conexiones */
		if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, 
				&sin_size)) == -1)
		{
			perror("accept");
			continue;  /* Si se produce un error se finaliza 
					el programa */
		}
		printf  ("server:  conexion desde:  %s\n", 
			inet_ntoa(their_addr.sin_addr));
		if (!fork())
		{/* Aca comienza el proceso hijo */
			strcpy(buffer,"Hello, world!\n");
			if (send(newfd, buffer, strlen(buffer), 0) == -1)
				perror("send");
		/* Vamos a deshabilitar Nagle's algorithm */
			result = setsockopt(newfd,            /* socket affected */
				IPPROTO_TCP,     /* set option at TCP level */
				TCP_NODELAY,     /* name of option */
				(char *) &flag,  /* the cast is historical cruft */
				sizeof(int));    /* length of option value */
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
/* El proceso padre no necesita este descriptor, solo lo utiliza el proceso hijo, en la proxima
 * llamada a accept(), retornara con un nuevo descriptor de socket
 */
	close(newfd);
	}
}
