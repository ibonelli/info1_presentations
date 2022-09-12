#include <stdio.h>

int main(void) {
	int a=100;
	int b=100;

	int *p=&a;
	int *q=&a;
	int *r=&b;

	printf("En decimal:\n");
	printf("\ta: %d, b: %d\n",a,b);
	printf("Como hexa:\n");
	printf("\ta: %x, b: %x\n",a,b);
	printf("Como hexa:\n");
	printf("\tp: %lx, q: %lx, r: %lx\n",(unsigned long)p,(unsigned long)q,(unsigned long)r);
	printf("Como punteros:\n");
	printf("\tp: %p, q: %p, r: %p\n",p,q,r);
	printf("Direccion de las variables punteros:\n");
	printf("\t&p: %p, &q: %p, &r: %p\n",&p,&q,&r);

	return 0;
}
