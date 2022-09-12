/*
 * A simple client of server.c
 * From - http://www.linuxhowtos.org/C_C++/socket.htm
 * GCC: gcc -o client sockets_2client.c
 * Ej. Uso: ./client 127.0.0.1 8888
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
	if (argc < 3) {
		fprintf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}

	// Paso1 crear el socket() con el que el cliente se va a comunicar con el servidor
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0)
		error("ERROR opening socket");

	// Del servidor al que me voy a conectar:
	//    -> 1ro configuro el puerto
	portno = atoi(argv[2]);
	//    -> 2do consigo la IP ya sea con el nombre DNS o la IP
	server = gethostbyname(argv[1]);

	if (server == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	// Inicializo la estructura del serv_addr con ceros
	memset((void *) &serv_addr, '\0', sizeof(serv_addr));

	// Usamos IPv4
	serv_addr.sin_family = AF_INET;

	// Copio de la estructura devuelta por gethostbyname() a serv_addr.sin_addr.s_addr
	bcopy((char *)server->h_addr,
		  (char *)&serv_addr.sin_addr.s_addr,
		  server->h_length);

	// Configuro el puerto y lo convierto de formato host a network con htons()
	serv_addr.sin_port = htons(portno);

	// Paso2 hacer el connect() al server
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");

	// Paso3 -> Ya nos podemos comunicar a través de sockfd
	printf("Escriba su mensaje: ");

	// Com1 (Paso4) -> El cliente envía un mensaje
	memset((void *) buffer, '\0', 256);
	fgets(buffer,255,stdin);
	n = write(sockfd,buffer,strlen(buffer));

	if (n < 0)
		error("ERROR writing to socket");

	// Com2 (Paso5) -> El cliente recibe la confirmacion del servidor
	memset((void *) buffer, '\0', 256);
	n = read(sockfd,buffer,255);

	if (n < 0)
		  error("ERROR reading from socket");
	printf("%s\n",buffer);

	// Paso6 -> Cerramos el socket
	close(sockfd);

	return 0;
}
