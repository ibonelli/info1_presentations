#include <stdlib.h>
#include <stdio.h>

void main(void) {
	char *str, tam;

	printf("Ingrese el tamaño de cadena deseado: ");
	scanf(" %d", &tam);
	setbuf(stdin, NULL);

	// Reservo la memoria para el string
	str = (char *) malloc ( sizeof(char) * tam );

	printf("Ingrese su cadena: ");
	fgets(str, tam, stdin);

	printf("\nSu cadena es: %s",str);
}
