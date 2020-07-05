/* Calcula el factorial de un entero N
 *        utilizando una funcion recursiva.
 *
 * Debemos compilarlo sin optimización para
 * que reserve la memoria del stack/pila en
 * factorial():
 *        gcc -O0 -o ej ej-fact-stack.c
 */

#include <stdio.h>

#define MAX 1000000

unsigned long int factorial(int N);

int main(void)
{
	char c;
	int N;
	do {
		printf("\nIngrese un numero: ");
		scanf("%d",&N);
		fflush(stdin);
		printf("\n\t%12d\t\t	%12lu\n",N,factorial(N));
		printf("\n\nOtro numero? (s/n): ");
		// Hacemos un segundo getchar para tomar el ENTER
		getchar();
		c=getchar();
	} while(c=='s');
}

unsigned long int factorial(int N)	 /*	FUNCION RECURSIVA	*/
{
	char vec[MAX], i; /* Tomamos memoria de la pila */
	printf("\n %d \t %p ",N,&N);

	if (!N) return 1 ;
	return N * factorial(N-1);
}
