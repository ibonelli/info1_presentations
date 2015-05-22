#include <stdio.h>

int mifunc(int *pa, int *pb) {
	int a,b;

	a=*pa;
	b=*pb;

	printf("\nDireccion/puntero A: %p\n",pa);
	printf("Direccion/puntero B: %p\n",pb);

	a++;
	b=b+2;

	printf("\nValor de A y B dentro de la funcion\n");
	printf("A: %d | B: %d\n",a,b);

	*pa=a;
	*pb=b;

	return a+b;
}

void main(void) {
	int a,b,c;
	int *pa,*pb;

	printf("Ingrese el valor de A: ");
	scanf("%d",&a);
	printf("Ingrese el valor de B: ");
	scanf("%d",&b);

	printf("\nValores de A y B ingresados\n");
	printf("A: %d | B: %d\n",a,b);

	pa=&a;
	pb=&b;

	c=mifunc(pa,pb);

	printf("\nValores de A, B y C luego de terminar la funcion\n");
	printf("A: %d | B: %d | C: %d\n",a,b,c);
}
