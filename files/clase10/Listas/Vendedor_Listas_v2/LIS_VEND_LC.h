/*
 * Definiciones de datos comunes a listas simples y dobles
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct vendedor {
	char nom[40];
	float com,acum;
	int vent;
};

typedef struct vendedor vend;
