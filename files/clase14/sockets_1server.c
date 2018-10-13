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

     sockfd = socket(AF_INET, SOCK_STREAM, 0);

     if (sockfd < 0) 
        error("ERROR opening socket");

     // Armando la estructura "sockaddr_in"
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     memset((void *) &(serv_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura

     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
              error("ERROR on binding");

     listen(sockfd,5);

     clilen = sizeof(cli_addr);

     printf("Esperando conexiones...\n");
     // Llamado bloqueante a accept()
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     printf("Conexion aceptada!\n");

     if (newsockfd < 0) 
          error("ERROR on accept");

     memset((void *) buffer, '\0', 256);

     n = read(newsockfd,buffer,255);

     if (n < 0) error("ERROR reading from socket");

     printf("Este es su mensaje: %s\n",buffer);
     n = write(newsockfd,"Recibí tu mensaje!",18);

     if (n < 0) error("ERROR writing to socket");

     close(newsockfd);

     close(sockfd);

     return 0; 
}
