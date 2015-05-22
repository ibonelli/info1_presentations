#include <stdio.h>

void main(void) {
	int i, j;
	int c;
	printf("\nTabla ASCII\n");
	printf("Sume el valor de la fila con el de la columna para obtener el codigo\n\n");
	printf("     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n\n");
	for (i = 2; i < 8; i++) {
		printf("%4d", i*16);
		for(j = 0; j < 16; j++) {
			c = 16*i + j;
			printf("%2c ", c);
		}
		printf("\n\n");
	}
	printf("Nota: Solo imprimimos la parte baja (primeros 128 codigos) \n\
	y evitamos los primeros 32 que no son imprimibles\n\n");
}
