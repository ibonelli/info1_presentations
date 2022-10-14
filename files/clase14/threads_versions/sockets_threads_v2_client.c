#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

void DieWithError(char *errorMessage);  /* Error handling function */
int main(int argc, char *argv[])
{
    int sock;                           /* Socket descriptor */
    struct sockaddr_in server_addr;     /* Server address */
    unsigned short server_port;         /* Server port */
    char *server_ip;                    /* Server IP address (dotted quad) */
    char server_response[300];   /* Buffer to hold response from the server */
    char* username;

    /* Test for correct number of arguments */
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port> <username>\n", argv[0]);
        exit(1);
    }

    server_ip = argv[1];            /* Second arg: server IP address (dotted quad) */
    server_port = atoi(argv[2]);    /* Third arg: server port number */
    username = argv[3];             /* Fourth arg: username */

    /* Create a reliable, stream socket using TCP */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    /* Construct the server address structure */
    memset(&server_addr, 0, sizeof(server_addr));       /* Zero out structure */
    server_addr.sin_family      = AF_INET;              /* Internet address family */
    server_addr.sin_addr.s_addr = inet_addr(server_ip); /* Server IP address */
    server_addr.sin_port        = htons(server_port);   /* Server port */

    /* Establish the connection to the server */
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
        DieWithError("connect() failed, could not find server.");

    printf("connected\n");

    memset(&server_response, 0, 300);
    if (recv(sock, server_response, 300, 0) < 0)
        DieWithError("recv() for initial response failed");

    printf("received initial reponse\n");
}

void DieWithError(char* errorMessage) {
    fprintf(stderr, "Dying with error sadface: %s\n", errorMessage);
    exit(1);
}
 
