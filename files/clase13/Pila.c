/*
 * Para compilar usar:
 * 			gcc -o ej Pila.c -lcurses
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>

#define MAX 5
#define STRINT 10

void ingresa(int *pr, int *d);
void lee(int *pr, int *d);
void lista(int pr, int *d);
void press_key(char *msg);

void main(void) {
	int	co=0, i;
	int da[MAX];
	char op[STRINT];

	do {
		system("clear");
		printf("1 - Ingresa datos\n");
		printf("2 - Lee datos\n");
		printf("3 - Lista datos\n");
		printf("4 - Salir\n\n");
		printf("Ingrese una opcion ( 1 - 4 ) : ");
		setbuf(stdin, NULL);
		fgets(op,STRINT,stdin);
		i=atoi(op);
		switch(i) {
			case 1:
				ingresa(&co,da);
				break;
			case 2:
				lee(&co,da);
				break;
			case 3:
				lista(co,da);
				break;
			case 4:
				exit(0);
		}
	} while(i!=4);
}

void ingresa(int *pr, int *d) {
	char k, dato[STRINT];
	do {
		if(*pr>=MAX) {
			system("clear");
			press_key("\nPila llena\nPresione una tecla para continuar\n");
			return;
		}
		printf("\nIngrese el dato : ");
		fgets(dato,STRINT,stdin);
		d[*pr]=atoi(dato);
		(*pr)++;
		printf("\nOtro dato ( S / N )? ");
		fgets(dato,STRINT,stdin);
		k = toupper(dato[0]);
	} while(k=='S');
}

void lee(int *pr, int *d) {
	char k, dato[STRINT];
	do {
		(*pr)--;
		if(*pr<0) {
			(*pr)=0;
			system("clear");
			press_key("\nPila vacia\nPresione una tecla para continuar\n");
			return;
		}
		printf("\nEl dato es : %d",d[*pr]);
		printf("\nOtro dato ( S / N )? ");
		fgets(dato,STRINT,stdin);
		k = toupper(dato[0]);
	} while(k=='S');
}

void lista(int pr, int *d) {
	int i;
	system("clear");
	for(i=pr-1;i>=0;i--)
		printf("%d\t",d[i]);
	printf("\n\nPresione una tecla para continuar");
	getchar();
}

void press_key(char *msg) {
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
