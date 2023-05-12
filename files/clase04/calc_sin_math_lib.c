/*
 * Compile using -lm at the end:
 * 				gcc -o calc calc_sin_math_lib.c -lm
 * 
 * Same is needed if we use a different compiler:
 * 				clang calc_sin_math_lib.c -o calc -lm
 * 
 * The reason to put it at the end seems to be the compiler optimizations.
 *     (source https://stackoverflow.com/questions/19188688/math-h-linker-error-using-sin-in-c)
 */

#include <stdio.h>
#include <math.h>

#define PI 3.1415926536

int main(void){
	double ang, rad, res;

	printf("== Calculo del seno ==\n");
	printf("Ingresar un angulo en grados: ");
	scanf("%lf",&ang);

	rad = PI/180;			// Pasamos de grados a radianes

	printf("\nAngulo: %f\n", ang);
	printf("En radianes: %f\n", rad);

	res = sin(ang*rad);
	printf("=> Resultado sin(): %f\n", res);

	return 0;
}
