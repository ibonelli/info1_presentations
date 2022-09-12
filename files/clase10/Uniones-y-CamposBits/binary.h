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

void print_bits(unbyte aux) {
	printf("%x",aux.b.b7);
	printf("%x",aux.b.b6);
	printf("%x",aux.b.b5);
	printf("%x",aux.b.b4);
	printf("'");
	printf("%x",aux.b.b3);
	printf("%x",aux.b.b2);
	printf("%x",aux.b.b1);
	printf("%x",aux.b.b0);
}

typedef union {
	float f;
	unbyte B[4];
} bytespacked;

void print_b32(bytespacked aux) {
	int i;
	printf("En binario:\n\t");
	for(i=3;i>-1;i--) {
		print_bits(aux.B[i]);
		if(i!=0)			// No imprimo al ultimo
			printf("'");
		else
			printf("\n");
	}
}

