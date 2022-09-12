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
	unsigned char dato, i;
	int datoi;

	while ( 1 ) {
		printf("Ingrese un numero de 0 a 7\tValor: ");
		scanf("%d",&dato);
		switch(dato) {
			case 0: alarma1(); break;
			case 1: alarma2(); break;
			case 2: alarma3(); break;
			case 3: alarma4(); break;
			case 4: alarma5(); break;
			case 5: alarma6(); break;
			case 6: alarma7(); break;
			case 7: alarma8(); break;
		}
	}

	return 0;
}
