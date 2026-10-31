/*
 * semaforo.c
 * Ejemplo de máquina de estados: un semáforo simple.
 *
 * Compilar:  gcc semaforo.c -o semaforo
 * Ejecutar:  ./semaforo
 */

#include <stdio.h>
#include <unistd.h>   /* para sleep() */

/* Duración de cada estado, en segundos */
#define TIEMPO_ROJO      3
#define TIEMPO_VERDE     3
#define TIEMPO_AMARILLO  1

/*
 * Enumeración con los estados posibles del semáforo.
 * El compilador les asigna valores enteros automáticamente:
 * ROJO = 0, VERDE = 1, AMARILLO = 2.
 * Usar nombres en lugar de números hace el código más legible.
 */
enum estado_semaforo {
    ROJO,
    VERDE,
    AMARILLO
};

int main(void)
{
    enum estado_semaforo estado = ROJO;  /* estado inicial de la máquina */
    int ciclos;                          /* ciclos que pide el usuario     */
    int completados = 0;                 /* ciclos ya realizados           */

    printf("¿Cuántos ciclos completos querés simular? ");
    scanf("%d", &ciclos);

    /* Bucle principal: en cada vuelta se ejecuta el estado actual */
    while (completados < ciclos) {

        /* Según el estado actual, se hace una acción y se elige el próximo estado */
        switch (estado) {

        case ROJO:
            printf("ROJO     -> Detenerse\n");
            sleep(TIEMPO_ROJO);
            estado = VERDE;          /* transición: ROJO -> VERDE */
            break;

        case VERDE:
            printf("VERDE    -> Avanzar\n");
            sleep(TIEMPO_VERDE);
            estado = AMARILLO;       /* transición: VERDE -> AMARILLO */
            break;

        case AMARILLO:
            printf("AMARILLO -> Precaución\n");
            sleep(TIEMPO_AMARILLO);
            estado = ROJO;           /* transición: AMARILLO -> ROJO */
            completados++;           /* se volvió al inicio: un ciclo completo */
            printf("--- Ciclo %d terminado ---\n", completados);
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
