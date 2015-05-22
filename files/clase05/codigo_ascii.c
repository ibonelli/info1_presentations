#include <stdio.h>

void main(void) {
	char c;
	printf("Ingrese un caracter: ");
	scanf("%c", &c);
	printf("Usted ingreso el caracter: \'%c\' \
		cuyo codigo ASCII es %d en decimal y %x hexa.\n", c, c, c);
}
