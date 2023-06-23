/*
 * Mostrando pasaje por valor y referencia:
 *   v5 : Haciendo explicito el puntero a puntero.
 */

#include <stdio.h>

void proc(int *pval) {
	int **ppval = &pval;
	printf("2: %d\n", *pval);
	printf("2 -> %p\n", pval);
	printf("2 -> 2p -> %p\n", ppval);
	*pval = 10;
	printf("3: %d\n", *pval);
}

int main(void) {
	int valor = 7;
	int *pval = &valor;
	int **ppval = &pval;
	printf("1: %d\n", valor);
	printf("1 -> %p\n", pval);
	printf("1 -> 1p -> %p\n", ppval);
	proc(pval);
	printf("4: %d\n", valor);
}
