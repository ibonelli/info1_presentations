/*
 * Mostrando pasaje por valor y referencia:
 *   v2 : Visualizando las direcciones de memoria.
 */

#include <stdio.h>

void proc(int valor) {
	int *pval = &valor;
	printf("2: %d\n", valor);
	printf("2 -> %p\n", pval);
	valor = 10;
	printf("3: %d\n", valor);
}

int main(void) {
	int valor = 7;
	int *pval = &valor;
	printf("1: %d\n", valor);
	printf("1 -> %p\n", pval);
	proc(valor);
	printf("4: %d\n", valor);
}
