#include "main.h"
#include "sock-lib.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXDATASIZE 4096/* mÃ¡xima cantidad de bytes que puede recibir en una transacciÃ³n*/

int main(int argc, char * argv[])
{
	int sock_client;  /*File Descriptor para sockets*/
	int numbytes;/*ContendrÃ¡ el nÃºmero de bytes recibidos por read () */
	char buf[MAXDATASIZE];  /* Buffer donde se reciben los datos de read ()*/
	long tel;

	/* Tratamiento de la lÃ­nea de comandos. */
	if (argc < 2)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
    }

	// Conectandonos al servidor
	sock_client = conectar (argc, argv);

	tel=pedirTel();

	// Comunicación con el servidor (conexion ya establecida)
    /** Envio el telefono del usuario */
    if(write(sock_client,tel,sizeof(tel)) == -1){
        perror("Error en la escritura del socket");
        exit(1);
    }

    /* Recibimos los datos del servidor del archivo a abrir */
	if ((numbytes = read (sock_client, buf, MAXDATASIZE)) == -1)
	{
		perror("error de lectura en el socket");
		exit(1);
	}

	// FALTA DESERIALIZACION
	/* Decidimos si debemos pedir los datos al usuario */
	if(buf[0] == TRUE) {
		printf("Existe\n");
		

	/* Devolvemos recursos al sistema */
	close(sock_client);

/****** SEGUNDA PARTE DEL EJERCICIO **********/
    //FILE *FP = fopen(buf,"r")


	return 0;
}
