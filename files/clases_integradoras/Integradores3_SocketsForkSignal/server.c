#include "sock-lib.h"
#define MAXDATASIZE 4096
#define TRUE 1
#define FALSE 0

int flag_srv=1;
int cant_hijos=0;

void sigchld() {
	// Can not use printf, see: "man 7 signal-safety"
	char str[50] = "Aceptando el cierre del cliente.";
	wait(NULL);
	// stdout for write is 1
	write(1,str,strlen(str));
	cant_hijos--;
}

void sigproc(void) {
	char str[50] = "Recibimos ctrl-c, saliendo del server.\n";
	flag_srv=0;
	write(1,str,strlen(str));
	exit(0);
}

int main () {
	int sock_server;		/* File Descriptor del socket por el que el servidor "escucharÃ¡" conexiones*/
	int sock_client; 

	pid_t pid;				/* Usado para guardar el PID del hijo y además identificar al hijo del padre */
	int i;

	char message[] = "Mensaje desde el servidor!";

	signal(SIGINT, (__sighandler_t) sigproc);

	struct sockaddr_in my_addr;	/* contendrÃ¡ la direcciÃ³n IP y el nÃºmero de puerto local */

	if ((sock_server = Open_conection (&my_addr)) == -1) {
		perror ("Fala la creacion de la conexion"); 
		exit (1);
	}

	while(flag_srv) {
		// Llamado bloqueante del que se sale cuando tenemos una conexion del cliente
		printf("ESCUCHANDO PEDIDOS (#hijos: %d\n", cant_hijos);
		sock_client = Aceptar_pedidos(sock_server);

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

			i=10;
			while(i>0) {
				printf("."); fflush(stdout);
				i--;
				sleep(2);
			}

			if (write (sock_client, message , sizeof (message)) == -1) {
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
			close(sock_client);
			// Cierro el child del server
			exit(0);
		} else {
			if(pid == -1)
				perror("ERROR creating child process");
			printf("Parent process created child %d\n", pid);
			signal(SIGCHLD, sigchld);
			cant_hijos++;
		}
	}
	close(sock_server);
	exit(0);
}
