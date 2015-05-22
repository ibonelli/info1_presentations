#include <stdio.h>

int mifunc(int a, int b) {
	a++;
	b=b+2;

	printf("\nValor de A y B dentro de la función\n");
	printf("A: %d | B: %d\n",a,b);

	return a+b;
}

void main(void) {
	int a,b,c;

	printf("Ingrese el valor de A: ");
	scanf("%d",&a);
	printf("Ingrese el valor de B: ");
	scanf("%d",&b);

	printf("\nValores de A y B ingresados\n");
	printf("A: %d | B: %d\n",a,b);

	c=mifunc(a,b);

	printf("\nValores de A, B y C luego de terminar la función\n");
	printf("A: %d | B: %d | C: %d\n",a,b,c);
}
