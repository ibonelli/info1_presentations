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

union join val;

val.B = 248;

if(val.bit.b0)
	printf("b0 = 1");
else
	printf("b0 = 0");

if(val.bit.b1)
	printf("b1 = 1");
else
	printf("b1 = 0");

if(val.bit.b2)
	printf("b2 = 1");
else
	printf("b2 = 0");

...
