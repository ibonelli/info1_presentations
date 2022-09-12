/*
 * Muestro los bits de un byte utilizando campos de bit
 */

#include <stdio.h>

struct byte {
	unsigned char b0:1;
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
};

union join {
	unsigned char B;
	struct byte bit;
};

int main(void) {
	union join val;

	val.B = 248;

	if(val.bit.b0)
		printf("b0 = 1\n");
	else
		printf("b0 = 0\n");

	if(val.bit.b1)
		printf("b1 = 1\n");
	else
		printf("b1 = 0\n");

	if(val.bit.b2)
		printf("b2 = 1\n");
	else
		printf("b2 = 0\n");

	if(val.bit.b3)
		printf("b3 = 1\n");
	else
		printf("b3 = 0\n");

	if(val.bit.b4)
		printf("b4 = 1\n");
	else
		printf("b4 = 0\n");

	if(val.bit.b5)
		printf("b5 = 1\n");
	else
		printf("b5 = 0\n");

	if(val.bit.b6)
		printf("b6 = 1\n");
	else
		printf("b6 = 0\n");

	if(val.bit.b7)
		printf("b7 = 1\n");
	else
		printf("b7 = 0\n");

	return 0;
}
