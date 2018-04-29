/*
 * Por problemas con el buffer y scanf() debo usar setbuf()
 *       http://stackoverflow.com/questions/1716296/why-does-printf-not-flush-after-the-call-unless-a-newline-is-in-the-format-strin
 */
 
#include <stdio.h>
int main (void)
{
	int num1, num2, suma;

	/* Entradas */
	printf("Introduzca el número 1?");
	scanf("%d", &num1);
	setbuf(stdin, NULL);
	printf("Introduzca el número 2?");
	scanf("%d", &num2);
	setbuf(stdin, NULL);

	/* Procesos */
	suma = num1 + num2;
	printf("El resultado de la suma es %d", suma); /*Salidas*/

	return 0;
}
