#include <stdio.h>
#include "ej1.h"

void print_alumno(struct alumno aux) {
	printf("  nombre: %s\n", aux.nom);
	printf("apellido: %s\n", aux.ape);
	printf("    edad: %d\n", aux.edad);
	printf("  legajo: %ld\n\n", aux.legajo);
}

void add_null_str(char *str, int size) {
	int i=0, seguir=1;
	do{
		if(str[i]==' ') {
			str[i]=0;
			seguir=0;
			//printf("Debug: %d\n", i);
		} else {
			i++;
		}
	} while(seguir!=0);
}
