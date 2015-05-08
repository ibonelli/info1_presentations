#include <stdio.h>

int main (void)
{
	int num1, num2, suma;

	/* Entradas */
	printf("Introduzca el numero 1?");
	scanf("%d", &num1);
	printf("Introduzca el numero 2?");
	scanf("%d", &num2);

	/* Procesos */
	suma = num1 + num2;
	printf("El resultado de la suma es %d", suma); /*Salidas*/

	return 0;
}
