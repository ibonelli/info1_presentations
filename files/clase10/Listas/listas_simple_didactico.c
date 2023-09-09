#include <stdlib.h>
#include <stdio.h>
#include "listas_simple_didactico.h"

int menu() {
	int op;

	printf("1.- Ingresar un dato\n");
	printf("2.- Sacar un dato\n");
	printf("3.- Listar\n");
	printf("4.- Salir\n");

	scanf("%d",&op);
	return op;
}

void main(void)
{
	struct nodo *INI;
	INI = NULL;
	int op,num,salir=0;

	while(salir==0) {
		op=menu();
		switch(op) {
			case 1: /* Ingresar */
				printf("Ingresar un dato: ");
				scanf("%d",&num);
				INI=ls_ingresar(INI,num);
				break;
			case 2: /* Sacar */
				printf("Dato sacado: %d\n",ls_sacar(&INI));
				break;
			case 3: /* Listar */
				printf("Listar:\n");
				ls_listar(INI);
				break;
			case 4: /* Salir */
				salir = 1;
				break;
		}
	}
}
