// Ejemplo usando fork y sock-lib2.h + sock-lib2.c
// Modificadas para poder tomar el port y crear childs que usen distintos puertos

// Compilar con:
//              gcc -o server fork_server.c sock-lib2.c

#include "sock-lib2.h"

int main (int argc, char **argv)
{
	pid_t pid;				/* Usado para guardar el PID del hijo y ademÃ¡s identificar al hijo del padre */
	int cant_hijos = 0;
	int srv_port;

	int sockfd; /* File Descriptor del socket por el que el servidor "escucharÃ¡" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	/* contendrÃ¡ la direcciÃ³n IP y el nÃºmero de puerto local */
	int sockdup; 

	if (argc == 1) {
		srv_port = htons(PORT);
	} else {
		srv_port = htons(atoi(argv[1]));
	}

	if ((sockfd = Open_conection (srv_port, &my_addr)) == -1)
	{
		perror ("FallÃ³ la creaciÃ³n de la conexiÃ³n"); 
		exit (1);
	}

	while(1)
	{
		sockdup = Aceptar_pedidos (sockfd);
		pid = fork();
		if(pid == 0) {
			// Atendiendo el cliente en un hijo
			printf("Child process %d\n", getpid());
			if (write (sockdup, message , sizeof (message)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
			sleep(10);
			printf("Child process %d finished.\n", getpid());
			close(sockdup);
		} else {
			if(pid == -1)
				perror("ERROR creating child process");
			printf("Parent process created child %d\n", pid);
			cant_hijos++;
		}
	}
	close(sockfd);
	exit(0);
}
