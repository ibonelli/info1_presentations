#include <stdio.h>

typedef unsigned char uchar;

typedef struct {
	uchar b0:1;
	uchar b1:1;
	uchar b2:1;
	uchar b3:1;
	uchar b4:1;
	uchar b5:1;
	uchar b6:1;
	uchar b7:1;
} bin;

typedef union {
	bin b;
	uchar B;
} unbyte;

typedef union {
	int i;
	unbyte B[4];
} bytespacked;

void main(void) {
	int i, num;
	bytespacked aux;

	printf("Ingrese el numero: ");
	scanf("%d", &num);

	//aux.i=0x12345678;
	aux.i=num;

	printf("En decimal:\n\t");
	printf("%d\n",aux.i);

	printf("En hexa:\n\t");
	printf("%x'",aux.B[3].B); /* Muestra 0x12 */
	printf("%x'",aux.B[2].B); /* Muestra 0x34 */
	printf("%x'",aux.B[1].B); /* Muestra 0x56 */
	printf("%x\n",aux.B[0].B); /* Muestra 0x78 */

	printf("En binario:\n\t");
	for(i=3;i>-1;i--) {
		printf("%x",aux.B[i].b.b7);
		printf("%x",aux.B[i].b.b6);
		printf("%x",aux.B[i].b.b5);
		printf("%x",aux.B[i].b.b4);
		printf("'");
		printf("%x",aux.B[i].b.b3);
		printf("%x",aux.B[i].b.b2);
		printf("%x",aux.B[i].b.b1);
		printf("%x",aux.B[i].b.b0);
		if(i!=0)			// No imprimo al ultimo
			printf("'");
		else
			printf("\n");
	}
}
