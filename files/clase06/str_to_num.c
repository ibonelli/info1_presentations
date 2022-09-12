#include <string.h>
#include <stdio.h>

void main(void) {
	char *snum = "4625";
	long l;

	printf("%s\n", snum);
	printf("[0]: %x\n", snum[0]);
	printf("[1]: %x\n", snum[1]);
	printf("[2]: %x\n", snum[2]);
	printf("[3]: %x\n", snum[3]);

	// Acá lo que tomo es el puntero snum
	l = (long) snum;
	printf("snum: %p\n", snum);
	printf("l: %d\n", l);
	printf("l (hexa): %x\n", l);

	// Acá si tomamos el valor guardado en snum
	l = atol(snum);
	printf("l: %d\n", l);
}
