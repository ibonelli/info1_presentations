/*
 * Transferencia de funcion como argumento de otra funcion
 * GCC : gcc -o ej2_pfunc ej2_pfunc.c -Wall
 */

#include <stdio.h>
#include <stdlib.h>
#include "getch.h"
#include <stdio_ext.h>

/*  Prototipos  */
int suma(int,int,int(*)(int));
int cuadrado(int);
int cubo(int);

int main(void)
{
	int a , b , seleccion ;
	int (*p[2])(int);

	p[0] = cuadrado;
	p[1] = cubo;

	system("clear");

	printf( "Suma de cuadrados : 0    Suma de cubos  :  1\n\n" ) ;
	scanf( "%d" , &seleccion ) ;

	// Validamos la entrada
	if(seleccion<0 || seleccion>1) {
		printf("Solo 0 y 1 son opciones validas\n");
		exit(EXIT_FAILURE);
	}

	printf( "\n\nIngrese dos valores \n\n" ) ;
	scanf("%d   %d" , &a , &b ) ;
	printf("\n\n\n\n\nResultado  =  %d" , suma(a, b, p[seleccion])) ;
	printf( "\n\n\n" ) ;

	__fpurge(stdin);
	getch();

	return 0;
}

int cuadrado( int x )
{
	return x * x ;
}

int cubo( int x )
{
	return x * x * x ;
}

int suma(int x, int y, int(*ptr)(int))
{
   return (*ptr)(x)+(*ptr)(y);
}
