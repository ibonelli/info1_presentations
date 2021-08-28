#include <stdio.h> 
#include "binary.h"

// Para validar, revisar:
// 		https://ibonelli.github.io/info1_presentations/Clase01_Sistemas_Numeracion.html#/6/10
//		gcc -o float float.c

typedef struct { 
	// Es importante este orden: LSB to MSB
	// Adicionalmente deben ser "unsigned int" por que frac es mayor a 8
	unsigned int frac:23;
	unsigned int exp:8;
	unsigned int s:1;
} flotante; 

typedef union { 
	float input; 
	flotante separado; 
} flotante_separar; 

int main(void) { 
	flotante_separar f;
	bytespacked fp;

	//printf("Introduzca un número float \n"); 
	//scanf(" %f", &f.input); 
	f.input = -118.625;

	fp.f = f.input;
	print_b32(fp);

	printf("S: %d, Exp: %x, Fracción: %x \n", 
		f.separado.s,
		f.separado.exp,
		f.separado.frac); 

	return 0; 
}
