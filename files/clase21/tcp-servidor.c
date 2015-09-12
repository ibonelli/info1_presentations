#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define MYPORT 3490    /*Numero de puerto donde se conectaran los clientes*/
#define BACKLOG 10     /* Tama¤o de la cola de conexiones recibidas */

main()
{
        int sockfd;     /* El servidor escuchara por sockfd */
        int newfd;      /*  las transferencias de datos se realizar 
                                mediante newfd */
        struct sockaddr_in my_addr;     /* contendra la direccion IP y el 
                                        numero de puerto local */
        struct sockaddr_in their_addr;  /* Contendra la direccion IP y 
                                        numero de puerto del cliente */
        int sin_size;   /* Contendra el tamanio de la escructura sockaddr_in */
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) /*Crea un socket
                                         y verifica si hubo algun error*/
        {
                perror("socket");
                exit(1);
        }

/* Asignamos valores a la estructura my_addr para luego poder llamar a la 
funcion bind() */
        my_addr.sin_family = AF_INET; 
        my_addr.sin_port = htons(MYPORT); /*debe convertirse a network byte 
                                        order porque es enviado por la red*/
        my_addr.sin_addr.s_addr = INADDR_ANY;   /* automaticamente usa la 
                                                IP local */
        bzero(&(my_addr.sin_zero), 8);  /* rellena con ceros el resto de 
                                        la estructura */
        if ( bind(sockfd, (struct sockaddr *)&my_addr, 
                        sizeof(struct sockaddr)) == -1)
        {
        perror("bind");
        exit(1);
        }
/* Habilitamos el socket para recibir conexiones, con una cola de 5 conexiones en espera como
maximo */
        if (listen(sockfd, BACKLOG) == -1)
        {
                perror("listen");
                exit(1);
        }
        while(1)        /* loop que llama a accept() */
        {
                sin_size = sizeof(struct sockaddr_in);
                /* Se espera por conexiones */
                if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, 
                                &sin_size)) == -1)
                {
                        perror("accept");
                        continue;  /* Si se produce un error se finaliza 
                                        el programa */
                }
                printf  ("server:  conexion desde:  %s\n", 
                        inet_ntoa(their_addr.sin_addr));
                if (!fork())
                {/* Aca comienza el proceso hijo */
                        if (send(newfd, "Hello, world!\n", 14, 0) == -1)
                        perror("send");
                        close(newfd);
                        exit(0);
                }
/* El proceso padre no necesita este descriptor, solo lo utiliza el proceso hijo, en la proxima
 * llamada a accept(), retornara con un nuevo descriptor de socket
 */
        close(newfd);
        }
}
