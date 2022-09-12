/*
 * Para compilar usar:
 * 			gcc -o ej Cola_Circular.c -lcurses
 * Instalando ncurses:
 * 			sudo apt-get install libncurses-dev
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>

#define MAX 5
#define STRINTSIZE 5

typedef struct {
	int lle;
	int vac;
	int sac;
	int pon;
} status;

status ingresa (int *vec, status estado);
status lee (int *vec, status estado);
void lista (int *vec, status estado);
void press_key(char *msg);

void main(void) 
{
	char c, op[STRINTSIZE];
	int da[MAX], el;
	status estado;

	estado.lle=0;
	estado.vac=1;
	estado.sac=0;
	estado.pon=0;

	do {
		system("clear");
		printf ("1 - Ingresa datos\n");
		printf ("2 - Lee datos\n");
		printf ("3 - Lista datos\n");
		printf ("4 - Salir\n\n");
		printf ("Ingrese una opcion ( 1 - 4 ) : ");
		setbuf(stdin, NULL);
		fgets(op,STRINTSIZE,stdin);
		el=atoi(op);
		switch (el) {
			case 1:
				estado=ingresa(da, estado);
				break;
			case 2:
				estado=lee(da, estado);
				break;
			case 3:
				lista(da, estado);
				break;
			case 4:
				exit(0);
				break;
			default:
				press_key("\nOpcion incorrecta\nPresione una tecla para continuar\n");
		}
	} while (el != 4);
	system("clear");
}

status ingresa(int *d, status estado) 
{
	char k, dato[STRINTSIZE];
	do {
		if (estado.lle) {
			press_key("\nCola llena\nPresione una tecla para continuar\n");
			return estado;
		}
		printf ("\n\nIngrese el dato : ");
		fgets(dato,STRINTSIZE,stdin);
		d[estado.pon]=atoi(dato);
		estado.vac = 0;
		(estado.pon)++;
		// Verificamos si llegamos al limite del vector para darle "circularidad"
		if (estado.pon == MAX)
			estado.pon = 0;
		// Solo aqui podemos darnos cuenta que se lleno el vector
		if (estado.pon == estado.sac)
			estado.lle = 1;
		printf("\nOtro dato ( S / N )? ");
		fgets(dato,STRINTSIZE,stdin);
		k = toupper(dato[0]);
	} while (k == 'S');
	return estado;
}

status lee(int *d, status estado)
{
	char k, dato[STRINTSIZE];
	do {
		if (estado.vac) {
			press_key("\nCola vacia\nPresione una tecla para continuar\n");
			return estado;
		}
		estado.lle = 0;
		printf ("\n\nEl dato es : %d\n", d[estado.sac]);
		(estado.sac)++;
		// Verificamos si llegamos al limite del vector para darle "circularidad"
		if (estado.sac == MAX)
			estado.sac = 0;
		if (estado.sac == estado.pon)
			estado.vac = 1;
		printf("\nOtro dato ( S / N )? : ");
		fgets(dato,STRINTSIZE,stdin);
		k = toupper(dato[0]);
	} while (k == 'S');
	return estado;
}

void lista(int *d, status estado)
{
	char k, dato[STRINTSIZE];
	system("clear");
	while (!estado.vac) {
		printf ("%d\t", d[estado.sac]);
		estado.sac++;
		if (estado.sac == MAX)
			estado.sac = 0;
		if (estado.sac == estado.pon)
			estado.vac = 1;
	}
	printf("\nDesea continuar ( S / N )? : ");
	fgets(dato,STRINTSIZE,stdin);
	k = toupper(dato[0]);
}

void press_key(char *msg)
{
	char input;

	initscr(); // entering ncurses mode
	raw();	 // CTRL-C and others do not generate signals
	noecho();  // pressed symbols wont be printed to screen
	cbreak();  // disable line buffering
	erase();
	mvprintw(1,0, msg);
	input = getch();
	endwin(); // leaving ncurses mode
}
