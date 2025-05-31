/*
 * Cuando tomamos enteros o doubles por teclado, el ENTER queda en el buffer de teclado.
 * Si luego de tomar un enteros o doubles intentamos tomar otro, el ENTER será lo que tomamos.
 * Para evitar este problema hay que vaciar el buffer de teclado luego de hacer un scanf.
 */

#define STRC 40

#include <stdio.h>

void main(void) {
	char str[STRC];
	int val;
	int aux;

	printf("Ingresar un valor entero: ");
	scanf("%d", &val);
	while((aux = getchar()) != '\n' && aux != EOF);
	printf("Ingresar una cadena: ");
	fgets(str, STRC, stdin);

	printf("----\n");
	printf("val: %d\n", val);
	printf("str: %s\n", str);
}
