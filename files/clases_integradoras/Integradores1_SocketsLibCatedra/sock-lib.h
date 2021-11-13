#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 3490	/* El puerto donde se conectarÃ¡, servidor */
#define BACKLOG 10	/* TamaÃ±o de la cola de conexiones recibidas */

int	conectar (int, char **);

int	Open_conection (struct sockaddr_in *); /* FunciÃ³n que crea la conexiÃ³n*/

int	Aceptar_pedidos (int);	/* FunciÃ³n que acepta una conexiÃ³n entrante*/