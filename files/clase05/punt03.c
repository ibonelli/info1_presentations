/*
 * Mostrando pasaje por valor y referencia:
 *   v3 : Pasaje por referencia.
 */

#include <stdio.h>

void proc(int *pval) {
	printf("2: %d\n", *pval);
	*pval = 10;
	printf("3: %d\n", *pval);
}

int main(void) {
	int valor = 7;
	int *pval = &valor;
	printf("1: %d\n", valor);
	proc(pval);
	printf("4: %d\n", valor);
}
