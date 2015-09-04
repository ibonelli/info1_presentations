/* Seleccion de funciones de alarma usando punteros a funcion  */
/* GCC : gcc -o alarmas ej3_alarmas.c -g -ggdb -Wall               */
#include <stdio.h>

/*  Prototipos  */
void alarma1( ) {
	printf("Alarma1\n"); }

void alarma2( ) {
	printf("Alarma2\n"); }

void alarma3( ) {
	printf("Alarma3\n"); }

void alarma4( ) {
	printf("Alarma4\n"); }

void alarma5( ) {
	printf("Alarma5\n"); }

void alarma6( ) {
	printf("Alarma6\n"); }

void alarma7( ) {
	printf("Alarma7\n"); }

void alarma8( ) {
	printf("Alarma8\n"); }


int main(void)
{
	void (*pf[])( ) = { alarma1 , alarma2 , alarma3 , alarma4 , \
			    alarma5 , alarma6 , alarma7 ,alarma8 };
	unsigned char dato, mascara, i;
	int datoi;

	while ( 1 ) {
		scanf("%d",&datoi);
		dato = (unsigned char) datoi;
		mascara = 1 ;
		for( i = 0 ; i < 8 ; i++ , mascara <<=1 )
			if( dato & mascara )
				(*pf[i])( ) ;
	}

	return 0;
}
