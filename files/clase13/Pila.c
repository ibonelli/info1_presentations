#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5

void ingresa(int *pr,float **d) {
	char k;
	float dato;
	do {
		if(*pr>=MAX) {
			clrscr();
			printf("\n\nPila llena");
			printf("\n\nPresione una tecla para continuar\n");
			getche();
			return;
		} else {
			d[*pr]=(float *)malloc(3000*sizeof(float));
			if(d[*pr]==NULL) {
				clrscr();
				printf("\n\nNo hay memoria disponible\n");
				printf("\n\nPresione una tecla para continuar\n");
				getch();
				return;
			} else {
				printf("\nIngrese el dato : ");
				scanf("%f",&dato);
				*d[*pr]=dato;
				(*pr)++;
			}
		}
		printf("\nOtro dato ( S / N )? ");
		k=toupper(getche());
	} while(k=='S');
}

void lee(int *pr,float **d) {
	char k;
	do {
		(*pr)--;
		if(*pr<0)
				{
					clrscr();
					printf("\n\nPila vacia");
					printf("\n\nPresione una tecla para continuar\n");
					(*pr)=0;
					getch();
					return;
				}
			else
				{
					if(d[*pr]==NULL)
							{
								printf("No hay dato\n");
								printf("\n\nPresione una tecla para continuar\n");
								getch();
								k='N';
							}
						else
							{
								printf("\nEl dato es : %f",*d[*pr]);
								free(d[*pr]);
								d[*pr]=NULL;
							}
				}
		printf("\nOtro dato ( S / N )? ");
		k=toupper(getche());
	} while(k=='S');
}

void lista(int *pr,float **d)
	{
		int i;
		clrscr();
		for(i=*pr-1;i>=0;i--)
			printf("%f\t",*d[i]);
		printf("\n\nPresione una tecla para continuar");
		getch();
	}

void main(void)
	{
		int	co=0,i;
		float	*da[MAX];
		for(i=0;i<MAX;i++)
			da[i]=NULL;
		do
			{
				clrscr();
				printf("1 - Ingresa datos\n");
				printf("2 - Lee datos\n");
				printf("3 - Lista datos\n");
				printf("4 - Salir\n\n");
				printf("Ingrese una opcion ( 1 - 4 ) : ");
				scanf("%d",&i);
				switch(i)
					{
							case	1:	ingresa(&co,da);
												break;
							case	2:	lee(&co,da);
												break;
							case	3:	lista(&co,da);
												break;
							case	4:	exit(0);
					}
			}
		while(i!=4);
	}
