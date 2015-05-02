#include <stdio.h>

int main (void)
{
	int a, b, c;

	/* Entradas */
	printf("Ingrese a");
	scanf("%d", &a);
	printf("Ingrese b");
	scanf("%d", &b);
	printf("Ingrese c");
	scanf("%d", &c);

	/* Procesos */
	if(a>b) {
		if(a>c) {
			printf("El mayor es a = %d", a);
		} else {
			printf("El mayor es c = %d", c);
		}
	} else {
		if(b>c) {
			printf("El mayor es b = %d", b);
		} else {
			printf("El mayor es c = %d", c);
		}
	}
	
	return 0;
}

