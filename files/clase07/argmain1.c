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
	for(desp=1;desp<cantarg;desp++)
		printf("El string Nro. %d es: %s\n",desp,param[desp]);
}
