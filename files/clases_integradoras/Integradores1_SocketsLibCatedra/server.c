#include "sock-lib.h"
#define MAXDATASIZE 4096
#define TRUE 1
#define FALSE 0

int main ()
{
	int sock_server; /* File Descriptor del socket por el que el servidor "escucharÃ¡" conexiones*/
	int sock_client; 

	char message[] = "Arch.txt";

	struct sockaddr_in my_addr;	/* contendrÃ¡ la direcciÃ³n IP y el nÃºmero de puerto local */

	if ((sock_server = Open_conection (&my_addr)) == -1)
	{
		perror ("Fala la creacion de la conexion"); 
		exit (1);
	}

    printf("ESCUCHANDO PEDIDOS\n");
	while(TRUE)
	{
		sock_client = Aceptar_pedidos (sock_server);

        int numBytes;
        char buf[MAXDATASIZE];

        if ((numBytes = read (sock_client, buf, MAXDATASIZE)) == -1){
		    perror("error de lectura en el socket");
		    exit(1);
	    }

        /* Visualizamos lo recibido */
	    buf[numBytes] = '\0';
	    printf("Recibido primer mensaje del cliente: %s\n",buf);
		
		if (write (sock_client, message , sizeof (message)) == -1)
		{
			perror("Error escribiendo mensaje en socket");
			exit (1);
		}
		close(sock_client);
    }
    close(sock_server);
	exit(0);
}