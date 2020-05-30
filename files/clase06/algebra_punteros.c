#define TAM 3
#include <stdio.h>

int main(void) {
	int tabla[TAM];
	int *pi;
	char *pc;

	int i, ctam;
	pi = tabla;

	printf("pi[0]: %d | pi[1]: %d\n", *pi, *(pi+1));

	*pi = 789436;
	*(pi+1) = 6743;

	printf("--------------\n");
	printf("pi[0]: %d | pi[1]: %d\n", *pi, *(pi+1));

	pc = (char *) pi;

	printf("--------------\n");
	ctam = TAM*sizeof(int); // Tamaño de tabla en chars
	for(i=0;i<ctam;i++) {
		printf("pc[%d]: %d\n", i, *(pc+i));
	}

	*pc = 'x';
	*(pc+1) = 'y';
	*(pi+2) = 0;

	printf("--------------\n");
	printf("pi[0]: %d | pi[1]: %d\n", *pi, *(pi+1));
	for(i=0;i<ctam;i++) {
		printf("pc[%d]: %d\n", i, *(pc+i));
	}

	return 0;
}
