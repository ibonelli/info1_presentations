/*
 * semaforo.c
 * Ejemplo de máquina de estados: un semáforo simple.
 *
 * Compilar:  gcc semaforo.c -o semaforo
 * Ejecutar:  ./semaforo
 */

#include <stdio.h>
#include <unistd.h>   /* para sleep() */
#include <time.h>

/* Duración de cada estado, en segundos */
#define TIEMPO_ROJO	  3
#define TIEMPO_VERDE	 3
#define TIEMPO_AMARILLO  1
#define SEGUNDOS_CNT  1000
/* Necesario para ajusar de usleep a segundos */
#define USECS2SECS 880

/*
 * Enumeración con los estados posibles del semáforo.
 * El compilador les asigna valores enteros automáticamente:
 * ROJO = 0, VERDE = 1, AMARILLO = 2.
 * Usar nombres en lugar de números hace el código más legible.
 */
typedef enum { ROJO, VERDE, AMARILLO } estado_semaforo;
struct timespec start, end;
typedef struct {
	int usecs;							/* cantidad de usecs transcurridos */
	int segundos;						/* cantidad de secs transcurridos  */
} timer;

/*
 * Funcion para verificar los tiempos
 */
void time_control_end() {
	clock_gettime(CLOCK_MONOTONIC, &end);
	long seconds = end.tv_sec - start.tv_sec;
	long nanoseconds = end.tv_nsec - start.tv_nsec;
	double elapsed_seconds = seconds + nanoseconds * 1e-9;
	printf("\tElapsed time: %.6f seconds\n", elapsed_seconds);
}

int main(void)
{
	estado_semaforo estado = ROJO;		/* estado inicial de la máquina	*/
	int ciclos;							/* ciclos que pide el usuario	*/
	int completados = 0;				/* ciclos ya realizados			*/
	long contador = 0;					/* cuenta ciclos de usleep()	*/

	printf("¿Cuántos ciclos completos querés simular? ");
	scanf("%d", &ciclos);

	/* Bucle principal: en cada vuelta se ejecuta el estado actual */
	while (completados < ciclos) {
		usleep(USECS2SECS);

		/* Según el estado actual, se hace una acción y se elige el próximo estado */
		switch (estado) {

		case ROJO:
			if ( contador == 0 ) {
				printf("ROJO	 -> Detenerse\n");
				clock_gettime(CLOCK_MONOTONIC, &start);
			}
			contador++;
			if (contador == TIEMPO_ROJO*SEGUNDOS_CNT) {
				estado = VERDE;			/* transición: ROJO -> VERDE */
				time_control_end();
				contador = 0;
			}
			break;

		case VERDE:
			if ( contador == 0 ) {
				printf("VERDE	-> Avanzar\n");
				clock_gettime(CLOCK_MONOTONIC, &start);
			}
			contador++;
			if (contador == TIEMPO_VERDE*SEGUNDOS_CNT) {
				estado = AMARILLO;		/* transición: ROJO -> VERDE */
				time_control_end();
				contador = 0;
			}
			break;

		case AMARILLO:
			if ( contador == 0 ) {
				printf("AMARILLO -> Precaución\n");
				clock_gettime(CLOCK_MONOTONIC, &start);
			}
			contador++;
			if (contador == TIEMPO_AMARILLO*SEGUNDOS_CNT) {
				estado = ROJO;			/* transición: ROJO -> VERDE */
				time_control_end();
				completados++;
				contador = 0;
				/* se volvió al inicio: un ciclo completo */
				printf("--- Ciclo %d terminado ---\n", completados);
			}
			break;

		default:
			/* No debería ocurrir nunca, pero es buena práctica contemplarlo */
			printf("Error: estado desconocido\n");
			return 1;
		}
	}

	printf("Fin de la simulación.\n");
	return 0;
}
