/*
 *
 *  Informática I - UTN.BA
 * 
 *  Ejercicio 2.47
 *
 *  Autor: Leandro Beretta <lea.beretta@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CLEAR "clear"

int main() {

	/* Declaración de variables locales */
	
    /* 
     * Recordar que coordenadaX y coordenadaY pueden no ser inicializadas
     * debido a que antes de usarlas para realizar calculos van a tener un
     * valor ingresado por teclado 
     */
    
	int coordenadaX = 0;
    int coordenadaY = 0;
	
	int contadorPrimerCuadrante = 0;
	int contadorSegundoCuadrante = 0;
	int contadorTercerCuadrante = 0;
	int contadorCuartoCuadrante = 0;

	float acumDistanciaPrimerCuadrante = 0;
	float acumDistanciaSegundoCuadrante = 0;
	float acumDistanciaTercerCuadrante = 0;
	float acumDistanciaCuartoCuadrante = 0;

	/* Se borra todo lo que esté escrito en la terminal previo a la ejecución del programa*/

	system(CLEAR);

	/* Se obtiene por teclado las coordenadas de los puntos hasta que se ingrese x=0 e y=0 */

	do {
		printf("Ingrese la coordenada X: ");
		scanf("%d", &coordenadaX);
                fpurge(stdin);
        
		printf("Ingrese la coordenada Y: ");
		scanf("%d", &coordenadaY);
                fpurge(stdin);

        /*
         * Una vez ingresado el par de valores, se procesa la informacion:
         *
         * Si x es menor a 0, el punto pertenece al segundo o tercer cuadrante, de lo contario
         * al primer o cuarto cuadrante. Con el mismo criterio se evalua la coordenada y
         */

		if (coordenadaX < 0) {
			if (coordenadaY < 0) {
				// Cuadrante 3
				
				printf("\nEl punto (%d,%d) pertenece al tercer cuadrante \n", coordenadaX, coordenadaY);

				contadorTercerCuadrante++; // contadorTercerCuadrante = contadorTercerCuadrante + 1
				acumDistanciaTercerCuadrante = acumDistanciaTercerCuadrante + sqrt(coordenadaX*coordenadaX + coordenadaY*coordenadaY);
			}
			else if (coordenadaY > 0) {
				// Cuadrante 2

				printf("\nEl punto (%d,%d) pertenece al segundo cuadrante \n", coordenadaX, coordenadaY);

				contadorSegundoCuadrante++;
				acumDistanciaSegundoCuadrante = acumDistanciaSegundoCuadrante + sqrt(coordenadaX*coordenadaX + coordenadaY*coordenadaY);
			}
		} else if (coordenadaX > 0) {
		  if (coordenadaY > 0) {
				  // Cuadrante 1

				  printf("\nEl punto (%d,%d) pertenece al primer cuadrante \n", coordenadaX, coordenadaY);

				  contadorPrimerCuadrante++;
				  acumDistanciaPrimerCuadrante = acumDistanciaPrimerCuadrante + sqrt(coordenadaX*coordenadaX + coordenadaY*coordenadaY);
			}
			else if (coordenadaY < 0) {
				  // Cuadrante 4 

				  printf("\nEl punto (%d,%d) pertenece al cuarto cuadrante \n", coordenadaX, coordenadaY);

				  contadorCuartoCuadrante++;
				  acumDistanciaCuartoCuadrante = acumDistanciaCuartoCuadrante + sqrt(coordenadaX*coordenadaX + coordenadaY*coordenadaY);
			}
		}

		if ((coordenadaX == 0 && coordenadaY != 0) || (coordenadaX != 0 && coordenadaY == 0))
		  printf("\nPar de valores no validos\n");

		printf("\n+-------------------------------------------------------------+\n\n");
		printf("Puntos en el primer cuadrante: %d \n", contadorPrimerCuadrante);
		printf("Acumulador de distancia al origen del primer cuadrante: %f \n", acumDistanciaPrimerCuadrante);
		printf("Puntos en el segundo cuadrante: %d \n", contadorSegundoCuadrante);
		printf("Acumulador de distancia al origen del segundo cuadrante: %f \n", acumDistanciaSegundoCuadrante);
		printf("Puntos en el tercer cuadrante: %d \n", contadorTercerCuadrante);
		printf("Acumulador de distancia al origen del tercer cuadrante: %f \n", acumDistanciaTercerCuadrante);
		printf("Puntos en el cuarto cuadrante: %d \n", contadorCuartoCuadrante);
		printf("Acumulador de distancia al origen del cuarto cuadrante: %f \n", acumDistanciaCuartoCuadrante);
		printf("\n+-------------------------------------------------------------+\n\n");


	} while ((coordenadaX != 0) || (coordenadaY != 0));

	printf("\nSe ha ingresado (0,0) \n\n");

 	return 0;
}
