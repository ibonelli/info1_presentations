// Ejemplo usando fork y sock-lib.h + sock-lib.c

#include "sock-lib.h"

int main ()
{
	pid_t pid;				/* Usado para guardar el PID del hijo y además identificar al hijo del padre */
	int cant_hijos = 0;

	int sockfd; /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
	int sockdup; 

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
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
