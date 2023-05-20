/*
 * Mostrando pasaje por valor y referencia:
 *   v4 : ¿Pasaje por referencia o por valor?
 */

#include <stdio.h>

void proc(int *pval) {
	printf("2: %d\n", *pval);
	printf("2 -> %p\n", pval);
	printf("2 -> 2p -> %p\n", &pval);
	*pval = 10;
	printf("3: %d\n", *pval);
}

int main(void) {
	int valor = 7;
	int *pval = &valor;
	printf("1: %d\n", valor);
	printf("1 -> %p\n", pval);
	printf("1 -> 1p -> %p\n", &pval);
	proc(pval);
	printf("4: %d\n", valor);
}
