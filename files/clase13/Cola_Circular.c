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

void ingresa (int *, int **, int *, int *, int *);
void lee (int *, int **, int *, int *, int *);
void lista (int *, int *, int *, int);
void press_key(char *msg);

void main(void) 
{
	char c, op[STRINTSIZE];
	int lle = 0, vac = 1, el, da[MAX], *sac = da, *pon = da;
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
				ingresa(da, &pon, &lle, &vac, sac);
				break;
			case 2:
				lee(da, &sac, &vac, &lle, pon);
				break;
			case 3:
				lista(da, sac, pon, vac);
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

void ingresa(int *d, int **pon, int *lle, int *vac, int *sac) 
{
	char k, dato[STRINTSIZE];
	do {
		if (*lle) {
			press_key("\nCola llena\nPresione una tecla para continuar\n");
			return;
		}
		printf ("\n\nIngrese el dato : ");
		fgets(dato,STRINTSIZE,stdin);
		**pon=atoi(dato);
		*vac = 0;
		(*pon)++;
		// Verificamos si llegamos al limite del vector para darle "circularidad"
		if (*pon == d + MAX)
			*pon = d;
		// Solo aqui podemos darnos cuenta que se lleno el vector
		if (*pon == sac)
			*lle = 1;
		printf("\nOtro dato ( S / N )? ");
		fgets(dato,STRINTSIZE,stdin);
		k = toupper(dato[0]);
	} while (k == 'S');
}

void lee(int *d, int **sac, int *vac, int *lle, int *pon) 
{
	char k, dato[STRINTSIZE];
	do {
		if (*vac) {
			press_key("\nCola vacia\nPresione una tecla para continuar\n");
			return;
		}
		*lle = 0;
		printf ("\n\nEl dato es : %d\n", **sac);
		(*sac)++;
		// Verificamos si llegamos al limite del vector para darle "circularidad"
		if (*sac == d + MAX)
			*sac = d;
		if (*sac == pon)
			*vac = 1;
		printf("\nOtro dato ( S / N )? : ");
		fgets(dato,STRINTSIZE,stdin);
		k = toupper(dato[0]);
	} while (k == 'S');
}

void lista(int *d, int *sac, int *pon, int vac) 
{
	char k, dato[STRINTSIZE];
	system("clear");
	while (!vac) {
		printf ("%d\t", *sac);
		sac++;
		if (sac == d + MAX)
			sac = d;
		if (sac == pon)
			vac = 1;
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
