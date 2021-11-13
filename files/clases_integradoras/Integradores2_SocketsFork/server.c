#include "sock-lib.h"
#define MAXDATASIZE 4096
#define TRUE 1
#define FALSE 0

int main ()
{
	int sock_server;		/* File Descriptor del socket por el que el servidor "escucharÃ¡" conexiones*/
	int sock_client; 

	//int rv;					/* Usado para el wait del server al hijo */
	pid_t pid;				/* Usado para guardar el PID del hijo y además identificar al hijo del padre */
	int cant_hijos = 0;
	int i;

	char message[] = "Arch.txt";

	struct sockaddr_in my_addr;	/* contendrÃ¡ la direcciÃ³n IP y el nÃºmero de puerto local */

	if ((sock_server = Open_conection (&my_addr)) == -1)
	{
		perror ("Fala la creacion de la conexion"); 
		exit (1);
	}

	while(TRUE)
	{
		// Llamado bloqueante del que se sale cuando tenemos una conexion del cliente
		printf("ESCUCHANDO PEDIDOS (#hijos: %d\n", cant_hijos);
		sock_client = Aceptar_pedidos (sock_server);

		// Levanto un hijo
		pid = fork();
		if(pid == 0) {
			// Comunicación cliente (conexion ya establecida)
			int numBytes;
			char buf[MAXDATASIZE];

			if ((numBytes = read (sock_client, buf, MAXDATASIZE)) == -1){
				perror("error de lectura en el socket");
				exit(1);
			}

			/* Visualizamos lo recibido */
			buf[numBytes] = '\0';
			printf("Recibido primer mensaje del cliente: %s\n",buf);

			i=20;
			while(i>0) {
				printf(".");
				i--;
				sleep(3);
			}

			if (write (sock_client, message , sizeof (message)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
			close(sock_client);
		} else {
			if(pid == -1)
				perror("ERROR creating child process");
			printf("Parent process created child %d\n", pid);
			cant_hijos++;
		}
	}
	close(sock_server);
	exit(0);
}
