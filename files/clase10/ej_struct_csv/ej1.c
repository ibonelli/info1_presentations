#include <stdio.h>
#include "ej1.h"

void print_alumno(struct alumno aux) {
	printf("  nombre: %s\n", aux.nom);
	printf("apellido: %s\n", aux.ape);
	printf("    edad: %d\n", aux.edad);
	printf("  legajo: %ld\n\n", aux.legajo);
}
