/*
 * Ejemplo de threads y una cola circular:
 * 		1. Main lee la cola circular y la vacía.
 * 		2. Hay un thread que genera valores aleatorios.
 * 		3. Hay 4 threads que van agregando datos a la cola circular.
 * El valor que va a la cola circular tiene empacado:
 * 		- En los dos bytes altos (<< 16) el ID
 * 		- En los dos bytes bajos el valor aleatorio capturado
 *
 * threads_colacircular.c - compile with:
 *           gcc -o tcc threads_colacircular.c -lpthread
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define MAX_BUFFER 9

unsigned int valorAleatorio = 0, bufferFull = 0;
unsigned int inxIn = 0;
unsigned int inxOut = 0;
unsigned int bufferDatos[MAX_BUFFER];

pthread_mutex_t mutex;

void *DatoAleatorio(void *unused) {
	(void)unused;

	while (1) {
		valorAleatorio = rand() % 65536;
		usleep(250000);
	}
	return NULL;
}

void *IngresoDeDatos(void *id) {
	while (1) 	{
		pthread_mutex_lock(&mutex);

		if (bufferFull < MAX_BUFFER) {
			//			putc( (char) (*((unsigned int * ) id ) & 0xf) + '0',stderr);
			putc((char)bufferFull + '0', stderr);
			bufferDatos[inxIn] = (valorAleatorio << 16) | *((unsigned int *)id);
			inxIn++;
			inxIn %= MAX_BUFFER;
			bufferFull++;
		}
		pthread_mutex_unlock(&mutex);
		usleep(valorAleatorio * 100);
	}
	return NULL;
}

int main() {
	pthread_t thread_id, thread_id1, thread_id2, thread_id3, thread_id4;

	unsigned int a, b, c, d;

	srand((unsigned int)time(NULL));

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&thread_id, NULL, DatoAleatorio, NULL);

	a = 0xa2;
	pthread_create(&thread_id1, NULL, IngresoDeDatos, &a);
	usleep(250000);

	b = 0xa1;
	pthread_create(&thread_id2, NULL, IngresoDeDatos, &b);
	usleep(250000);

	c = 0xa0;
	pthread_create(&thread_id3, NULL, IngresoDeDatos, &c);
	usleep(250000);

	d = 0xa3;
	pthread_create(&thread_id4, NULL, IngresoDeDatos, &d);
	usleep(250000);

	pthread_detach(thread_id);
	pthread_detach(thread_id1);
	pthread_detach(thread_id2);
	pthread_detach(thread_id3);
	pthread_detach(thread_id4);

	while (1) {
		getchar();
		printf("inxIn: %03d - inxOut : %03d\n", inxIn, inxOut);

		while (bufferFull != 0) {
			pthread_mutex_lock(&mutex);

			printf("ID: %04x - Dato : %04x\n", bufferDatos[inxOut] & 0x0000ffff, bufferDatos[inxOut] >> 16);
			inxOut++;
			inxOut %= MAX_BUFFER;
			bufferFull--;

			pthread_mutex_unlock(&mutex);
		}
	}
	return 0;
}
