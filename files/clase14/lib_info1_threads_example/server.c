#include "sock-lib.h"

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[BACKLOG];
int thread_count;
char msg_counter;
char message[20];

void set_msg(void) {
	if (msg_counter != 'Z') {
		message[15]=msg_counter;
		msg_counter++;
	else {
		msg_counter='A';
		message[15]=msg_counter;
	}
}

void *doSomeThing(void *arg) {
	set_msg();

	if (write (sockdup, message , sizeof (message)) == -1) {
		perror("Error escribiendo mensaje en socket");
		exit (1);
	}
	close(sockdup);

    return NULL;
}

int main ()
{
	int sockfd; /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
	int sockdup;

	int i;
    int *ptr[2];

	strcpy(message,"Server message  ");
	msg_counter='A';

	thread_count=0;

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}

	while(1)
	{
		sockdup = Aceptar_pedidos (sockfd);

        err = pthread_create(&(tid[thread_count]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");

		thread_count++;
	}

	for(i=0;i<thread_count;i++) {
	    pthread_join(tid[i], (void**)&(ptr[0]));
		printf("\n return value from first thread is [%d]\n", *ptr[0]);
	}

	exit(0);
}
