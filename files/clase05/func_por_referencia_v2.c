#include <stdio.h>

int mifunc(int *pa, int *pb) {
	int a,b;

	a=*pa;
	b=*pb;

	printf("\n\n---- Entramos a la funcion...");
	printf("\nDireccion contenida o puntero A o direccion de A: %p",pa);
	printf("\nDireccion contenida o puntero B o direccion de B: %p",pb);
	printf("\nDireccion del puntero A: %p",&pa);
	printf("\nDireccion del puntero B: %p",&pb);

	a++;
	b=b+2;

	printf("\nValor de A y B dentro de la funcion\n");
	printf("A: %d | B: %d\n",a,b);

	*pa=a;
	*pb=b;

	printf("---- Salimos de la funcion...");

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

	printf("\nDireccion contenida o puntero A o direccion de A: %p",pa);
	printf("\nDireccion contenida o puntero B o direccion de B: %p",pb);
	printf("\nDireccion del puntero A: %p",&pa);
	printf("\nDireccion del puntero B: %p",&pb);

	c=mifunc(pa,pb);

	printf("\n\nValores de A, B y C luego de terminar la funcion\n");
	printf("A: %d | B: %d | C: %d\n",a,b,c);
}
