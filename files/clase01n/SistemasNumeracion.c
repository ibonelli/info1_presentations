#include <stdio.h>

int main(void) {
	int numero = 0;

	printf("Ejemplo: Conversión a octal/hexadecimal/ascii \n");
	printf("Ingrese el numero a convertir \n");
	scanf("%d", &numero);

	printf("Dec: %d - Oct: %o - Hex: %x - Ascii: %c \n", \
		numero, numero, numero, numero);

	return 0;
}
