// To Compile:
//		gcc -o srv server.c sock-lib.c -lpthread -Wall

#include "sock-lib.h"

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define DELAY 5000
#define LIMIT 5
#define STRSIZE 20
#define THREAD_LIMIT 4

struct args {
	int socket;
	char clt_cnt;
	char message[STRSIZE];
	char msg_cnt;
};

int ret[BACKLOG];

void *doSomeThing(void *input) {
	int i,j;

	for(i=0;i<LIMIT;i++) {
		for(j=0; j<DELAY; j++) {
			usleep(1000);
		}
		((struct args*)input)->msg_cnt++;
		snprintf(((struct args*)input)->message, STRSIZE, "clt %d, msg %d\n", ((struct args*)input)->clt_cnt, ((struct args*)input)->msg_cnt);
		if(write(((struct args*)input)->socket, ((struct args*)input)->message, STRSIZE) == -1) {
			perror("Error escribiendo mensaje en socket");
			exit (1);
		}
	}

	close(((struct args*)input)->socket);

	i=((struct args*)input)->clt_cnt;
	ret[i]=100*(i+1);
	pthread_exit((void *)&ret[i]);

	return NULL;
}

int main () {
	int err;
	int thr_cnt;
	pthread_t tid[BACKLOG];

	int sockfd; /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */

	int i;
	int *ptr[BACKLOG];
	struct args svr[BACKLOG];

	thr_cnt=0;
	for(i=0;i<BACKLOG;i++) {
		svr[i].msg_cnt=0;
	}

	if ((sockfd = Open_conection (&my_addr)) == -1) {
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}

	while(thr_cnt<THREAD_LIMIT) {
		svr[thr_cnt].socket = Aceptar_pedidos (sockfd);
		svr[thr_cnt].clt_cnt = thr_cnt;

		err = pthread_create(&(tid[thr_cnt]), NULL, &doSomeThing, (void *)(&svr[thr_cnt]));
		if (err != 0)
			printf("\ncan't create thread: [%s]", strerror(err));
		else
			printf("\n Thread %d created successfully\n", thr_cnt);

		thr_cnt++;
	}

	for(i=0;i<thr_cnt;i++) {
		pthread_join(tid[i], (void**)&(ptr[i]));
		printf("\n return value from thread %d is [%d]\n", i, *ptr[i]);
	}

	exit(0);
}
