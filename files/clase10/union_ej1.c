#include <stdio.h>

union equivalencia {
    short i;
    char b[2];
};

void main(void) {
	union equivalencia x;

	printf("short: %d\n", (int) sizeof(short));
	printf("int: %d\n\n", (int) sizeof(int));

	x.i = 0x4892;
	printf("i: %hx\n",x.i);
	printf("b[0]: %hhx\n",x.b[0]);
	printf("b[1]: %hhx\n",x.b[1]);

	printf("------\n");
	printf("dir_i: %p\n", &x.i);
	printf("dir_b: %p\n", &x.b);

	printf("------\n");
	x.b[0] = 'a';
	printf("i: %hx\n",x.i);
}
