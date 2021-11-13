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

#define PORT 3490	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */

/* Cliente: Crea un socket que se conecta a un servidor remoto usando TCP
   - Toma: Los parámetros pasados por línea de comandos
           Por ejemplo: micliente 127.0.0.1 3490
   - Devuelve: El socket creado listo para ser usado (si es !=0)
*/

int	conectar (int argc, char **argv);

/* Servidor: Crea un socket TCP server y lo devuelve
    - Toma: La estructura con los datos del socket a configurar ya armada
    - Devuelve: El socket creado para aceptar conexiones (si es != 0)
*/

int	Open_conection (struct sockaddr_in *);

/* Servidor: Función que acepta una conexión entrante (bloqueante)
    - Toma: El socket creado por conectar()
    - Devuelve: Un socket ya conectado a un cliente.
*/

int	Aceptar_pedidos (int socket);
