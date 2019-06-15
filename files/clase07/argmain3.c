#include <stdio.h>
#include <string.h>

#define CANT_ARG_MIN 2

int main(int cantarg,char *param[],char *ento[])
	{
		int desp;
		if(cantarg<CANT_ARG_MIN)
				{
					printf("DEBE INGRESAR COMO MINIMO\n");
					printf("UN VALOR EN LA LINEA DE COMANDO\n");
					printf("INTENTELO DE NUEVO\n\n");
					return -1;
				}
		for(desp=0;desp<cantarg;desp++)
			printf("El string Nro. %d es: %s\t%p\n",desp,param[desp],\
				param[desp]);
		printf("\n\n");
		for(desp=0;ento[desp]!='\0';desp++)
			printf("El string Nro. %d es: %s\t%p\n",desp,ento[desp],\
			ento[desp]);
    return 0;
	}
