/*
 * A simple server in the internet domain using TCP
 * The port number is passed as an argument
 * Version Original de - http://www.linuxhowtos.org/C_C++/socket.htm
 * GCC: gcc -o server sockets_1server.c
 * Ej. Uso: ./server 8888
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
	printf("%s\n",msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}

	// Paso1 crear el socket() de listen/accept del servidor
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0)
		error("ERROR opening socket");

	// Armando la estructura "sockaddr_in" que va a usar el bind
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;				// Usamos IPv4
	serv_addr.sin_addr.s_addr = INADDR_ANY;		// Vamos a aceptar cualquier dirección de cliente
	serv_addr.sin_port = htons(portno);			// El puerto donde vamos a quedarnos esperando conexiones de clientes
	memset((void *) &(serv_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura
		// Lo mismo que hacer:
		//			for(i=0;i<8;i++) serv_addr.sin_zero[i] = 0;

	// Paso2 hacer el bind() del programa servidor al puerto del sistema operativo
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
			error("ERROR on binding");

	// Paso3 listen() que nos deja al server escuchando el puerto definido en bind()
	listen(sockfd,1);

	clilen = sizeof(cli_addr);

	printf("Esperando conexiones...\n");
	// Paso4 accept() que se queda (bloqueado) esperando una conexión del cliente
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		// Importante notar que accept() nos devuelve un newsockfd que nos permitira comunicarnos con el cliente
		// El sockfd solo se usara para aceptar conexiones nuevas listen()/accept()
		// De estos sockets tendremos uno por cliente (cuando podamos aceptar más de un cliente en programas futuros)
	printf("\tConexion aceptada!\n");

	// Paso5 -> Ya nos podemos comunicar a través de newsockfd
	if (newsockfd < 0)
		error("ERROR on accept");

	// Com1 (Paso6) -> El servidor recibe el mensaje del cliente
	memset((void *) buffer, '\0', 256);
	n = read(newsockfd,buffer,255);

	if (n < 0)
		error("ERROR reading from socket");
	printf("Este es su mensaje: %s\n",buffer);

	// Com2 (Paso7) -> El servidor le confirma la recepcion al cliente
	n = write(newsockfd,"Recibí tu mensaje!",18);

	if (n < 0) error("ERROR writing to socket");

	// Paso 8 -> Cerramos los sockets usados
	close(newsockfd);
	close(sockfd);

	return 0;
}
