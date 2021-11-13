#include "main.h"
#include "sock-lib.h"
#define MAXDATASIZE 4096
#define TRUE 1
#define FALSE 0

void atenderCliente(void) {
	// Comunicación cliente (conexion ya establecida)
	int numBytes;
	char buf[MAXDATASIZE];
	long tel;
	char cmd[300];

	if ((fd=mkfifo (FIFO_IDA, 0666))<0)
		fprintf (stderr, "Error creando la FIFO %s. Código de error %s\n",FIFO_NAME,strerror(fd));

	printf("Esperando lectores...\n");

	/*Este open va a bloquear el proceso si no hay ningún proceso que haya abierto la FIFO para escritura.*/

	fd = open(FIFO_IDA, O_WRONLY);

	/*Si bloquea, ni bien un proceso abra el FIFO para escritura se desbloquea este proceso y continúa con el printf siguiente*/

	printf("Encontré un lector.\n");

	if ((numBytes = read(sock_client, tel, sizeof(tel))) == -1){
		perror("error de lectura en el socket");
		exit(1);
	}

	cmd 
	// Escribo en la fifo el cmdFifo y el telefono
	if ((num = write(fd, cmd, strlen(cmd))) == -1)
		fprintf (stderr, "Error escribiendo en la FIFO %s. Código de error %s\n", FIFO_NAME, strerror(num));
	else
		printf("speak: %d bytes escritos\n", num);


	if ((numBytes = read(sock_client, buf, MAXDATASIZE)) == -1){
		perror("error de lectura en el socket");
		exit(1);
	}

	/* Visualizamos lo recibido */
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
}
