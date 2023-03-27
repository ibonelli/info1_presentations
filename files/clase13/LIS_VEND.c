/********************
 * Realizar un programa que maneje el ingreso de vendedores.
 * Debe poder agregarse un vendedor y luego agregar ventas de
 * ese vendedor.
 * 
 * Se debera poder listar las ventas durante el mes, y al final
 * del mes se debe generar un cierre del mes informando total
 * de ventas y comisiones a pagar.
 *
 * compile: 
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

struct nodo {
	struct vendedor dato;
	struct nodo *sig;
};

/********************
 * Funciones a usar para una lista simplemente enlazada
 */

void ingresar_dato(char *nom, struct nodo *Pini,float comision)
{
	struct nodo*paux;

	paux=(struct nodo*) malloc(sizeof(struct nodo));
	(paux->dato).acum=0;
	(paux->dato).vent=0;

	if (Pini->sig==NULL) {
		Pini->sig=paux;
		paux->sig=NULL;
	} else {
		paux->sig=Pini->sig;
		Pini->sig=paux;
	}

	(paux->dato).com=comision;
	strcpy((paux->dato).nom,nom);
}

void borrar_dato(char *nom,struct nodo *Pini)
{
	struct nodo *paux,*p;
	p=Pini;
	for (paux=Pini->sig;(paux->sig!=NULL) && strcmp(nom,(paux->dato).nom);paux=paux->sig);
	p=paux;
	if (paux->sig!=NULL)
		p->sig=paux->sig;
	else
		p->sig=NULL;
	free(paux);
}

/********************
 *    Funciones manejo programa
 */

int mostrar_menu()
{
int choice;

printf("1.- Ingresar un vendedor\n");
printf("2.- Ingresar una venta\n");
printf("3.- Borrar un vendedor\n");
printf("4.- Listado\n");
printf("5.- Cerrar mes\n");
printf("6.- Salir\n");
scanf("%d",&choice);

return choice;
}

void mostrar_datos(vend aux)
{
	printf("nombre y apellido: %s\n", aux.nom);
	printf("comisiones:%f\n",aux.acum);
	printf("cantidad de ventas:%d\n", aux.vent);
}

void mostrar_datos_listar(vend aux)
{
	mostrar_datos(aux);
	printf("comision sobre las ventas %f\n", aux.com);
}

int verificar_existencia_dato(char *nom,struct nodo *Pini)
{
	struct nodo *paux;
	paux=Pini->sig;
	if( paux != NULL ) {
		while(strcmp(nom,(paux->dato).nom) && paux->sig != NULL)
			paux=paux->sig;
		if( paux != NULL ) {
			if(!strcmp(nom,(paux->dato).nom))
				return 0;
			else
				return 1;
		} else {
			return 1;
		}
	} else {
		return 1;
	}
}

void ingresar_vendedor(struct nodo *Pini)
{
	int i;
	char nombre[40];
	float com;
	printf("Ingrese el nombre del vendedor:\n");
	scanf("%s", nombre);
	if (verificar_existencia_dato(nombre,Pini)) {
		printf("Ingrese la comision:\n");
		scanf("%f",& com);
		ingresar_dato(nombre,Pini,com);
	}
	else
		printf("El vendedor ya existe!\n");
}

void modificar_valor_dato(char *nom,struct nodo *Pini,float venta)
{
	struct nodo *paux;
	for(paux=Pini->sig;strcmp(nom,(paux->dato).nom);paux=paux->sig);
	(paux->dato).acum+=(venta*(paux->dato).com);
	(paux->dato).vent++;
}

void ingresar_venta(struct nodo *PINI)
{
	char nombre[40];
	float valor_venta;
	printf("Ingrese el nombre del vendedor:\n");
	scanf("%s",nombre);
	if (!verificar_existencia_dato(nombre,PINI)) {
		printf("Ingrese el valor de la venta:\n");
		scanf("%f",&valor_venta);
		modificar_valor_dato(nombre,PINI,valor_venta);
	}
	else
		printf("El vendedor no existe!\n");
}

void borrar_vendedor(struct nodo *Pini)
{
	char nombre[40];
	printf("ingrese el nombre del vendedor:\n");
	scanf("%s",nombre);
	if (verificar_existencia_dato(nombre,Pini))
		borrar_dato(nombre,Pini);
	else
		printf("el vendedor no existe");
}

struct nodo *listar_datos(struct nodo *q)
{
	return q->sig;
}

void listar(struct nodo *Pini)
{
	struct nodo *paux;
	paux=listar_datos(Pini);
	while(paux) {
		mostrar_datos_listar(paux->dato);
		paux=listar_datos(paux);
		}
}

void cerrar_mes(struct nodo *Pini)
{
	struct nodo *paux;
	int total_ventas;
	float total_a_pagar;
	paux=listar_datos(Pini);
	while(paux) {
		mostrar_datos(paux->dato);
		total_ventas+=(paux->dato).vent;
		total_a_pagar+=(paux->dato).acum;
		paux=listar_datos(paux);
		}
	printf("total de ventas: %d\n", total_ventas);
	printf("total a pagar:%f\n",total_a_pagar);
}

struct nodo *inicializar_datos()
{
	struct nodo *paux;
	paux=(struct nodo *) malloc(sizeof(struct nodo));
	paux->sig=NULL;
	return paux;
}

/********************
 * Nuestro main()
 */

void main (void)
{
	struct nodo *ini_datos;
	int opcion;
	ini_datos=inicializar_datos();
	do {
		opcion=mostrar_menu();
		switch(opcion){
			case 1:	ingresar_vendedor(ini_datos); break;
			case 2:	ingresar_venta(ini_datos); break;
			case 3:	borrar_vendedor(ini_datos); break;
			case 4:	listar(ini_datos); break;
			case 5:	cerrar_mes(ini_datos); break;
		}
	}while(opcion!=6);
}
