/*
 * Seleccion entre dos funciones usando punteros a funcion
 * GCC : gcc -o ej1_pfunc ej1_pfunc.c -Wall
 */

#include <stdio.h>
#include <stdlib.h>
#include "getch.h"
#include <stdio_ext.h>

int sumar(int,int);
int restar(int,int);

int main(void)
{
	int a, b, i;
	// Vector de 2 posiciones de punteros a funcion
	int (*p[2])();

	p[0] = sumar;
	p[1] = restar;

	a = 8;
	b = 5;

	system("clear");

	printf( "\n\n\nIngrese opcion     :" );
	printf( "\n\n\t0  -  SUMAR\t\t\t1  -  RESTAR\n\n" );
	scanf( "%d" , &i );

	// Validamos la entrada
	if(i<0 || i>1) {
		printf("Solo 0 y 1 son opciones validas\n");
		exit(EXIT_FAILURE);
	}

	printf( "\n\nResultado = %d\n\n" , (*p[i])(a,b) );

	// Saca el "enter" del llamado a scanf()
	__fpurge(stdin);

	// Espera que se presione una tecla
	getch();

	return 0;
}

int sumar( int x , int y )
{
	return x + y;
}

int restar( int x , int y )
{
	return x - y;
}
