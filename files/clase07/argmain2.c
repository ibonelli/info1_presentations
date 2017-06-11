#include <stdio.h>

#define CANT_ARG_MIN 2

int main(int cantarg,char *param[]) {
	int desp;
	if(cantarg<CANT_ARG_MIN) {
		printf("DEBE INGRESAR COMO MINIMO\n");
		printf("UN VALOR EN LA LINEA DE COMANDO\n");
		printf("INTENTELO DE NUEVO\n\n");
		return 0;
	}
	printf("La cadena Nro 0 es: %s\n",param[0]);
	for(desp=1;desp<cantarg;desp++)
		printf("La cadena Nro %d es: %s\n",desp,param[desp]);
}
