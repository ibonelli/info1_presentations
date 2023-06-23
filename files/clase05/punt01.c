/*
 * Mostrando pasaje por valor y referencia:
 *   v1 : Pasaje por valor, implicancias.
 */

#include <stdio.h>

void proc(int valor) {
	printf("2: %d\n", valor);
	valor = 10;
	printf("3: %d\n", valor);
}

int main(void) {
	int valor = 7;
	printf("1: %d\n", valor);
	proc(valor);
	printf("4: %d\n", valor);
}
