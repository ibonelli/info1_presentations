#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void ingresa(int *d, int **pon, int *lle, int *vac, int *sac) {
	char k, dato[3];
	do {
		if (*lle) {
			system("clear");
			printf ("\n\nCola llena");
			printf ("\n\nPresione una tecla para continuar\n");
			printf("\nDesea continuar ( S )? : ");
			scanf("%s",dato);
			k = toupper(dato[0]);
			return;
		}
		printf ("\n\nIngrese el dato : ");
		scanf("%s",dato);
		**pon=atoi(dato);
		*vac = 0;
		(*pon)++;
		if (*pon == d + MAX)
			*pon = d;
		if (*pon == sac)
			*lle = 1;
		printf("\nOtro dato ( S / N )? ");
		scanf("%s",dato);
		k = toupper(dato[0]);
	} while (k == 'S');
}

void lee(int *d, int **sac, int *vac, int *lle, int *pon) {
	char k, dato[3];
	do {
		if (*vac) {
			system("clear");
			printf ("\n\nCola vacia");
			printf("\nDesea continuar ( S )? : ");
			scanf("%s",dato);
			k = toupper(dato[0]);
			return;
		}
		*lle = 0;
		printf ("\n\nEl dato es : %d\n", **sac);
		(*sac)++;
		if (*sac == d + MAX)
			*sac = d;
		if (*sac == pon)
			*vac = 1;
		printf("\nOtro dato ( S / N )? : ");
		scanf("%s",dato);
		k = toupper(dato[0]);
	} while (k == 'S');
}

void lista(int *d, int *sac, int *pon, int vac) {
	char k, dato[3];
	system("clear");
	while (!vac) {
		printf ("%d\t", *sac);
		sac++;
		if (sac == d + MAX)
			sac = d;
		if (sac == pon)
			vac = 1;
	}
	printf("\nDesea continuar ( S )? : ");
	scanf("%s",dato);
	k = toupper(dato[0]);
}
void main(void) {
	char op[3];
	int lle = 0, vac = 1, el, da[MAX], *sac = da, *pon = da;
	do {   		system("clear");		printf ("1 - Ingresa datos\n");		printf ("2 - Lee datos\n");		printf ("3 - Lista datos\n");		printf ("4 - Salir\n\n");		printf ("Ingrese una opcion ( 1 - 4 ) : ");		scanf("%s",op); el=atoi(op);		switch (el) {
			case 1:
				ingresa(da, &pon, &lle, &vac, sac);
				break;
			case 2:
				lee(da, &sac, &vac, &lle, pon);
				break;
			case 3:
				lista(da, sac, pon, vac);
				break;
			case 4:
				exit(0);		}
	} while (el != 4);
	system("clear");
}
