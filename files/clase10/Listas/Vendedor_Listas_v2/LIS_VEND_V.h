#include <stdio.h>
#include <string.h>

#define MAX 10

struct vendedor {
	char nom[40];
	float com,acum;
	int vent;
};

typedef struct vendedor vend;

/* ---------------------------------------------------- */
/* Funciones a usar para una lista simplemente enlazada */
/* ---------------------------------------------------- */

struct nodo {
	struct vendedor dato;
};

struct nodo lista_datos[MAX];
int indice,listado;

struct nodo *inicializar_datos()
{
	indice=0;
	listado=0;
	return lista_datos;
}

void ingresar_dato(char *nom, struct nodo *Pini,float comision)
{
	if(indice<MAX) {
		Pini[indice].dato.com=comision;
		strcpy((Pini[indice].dato).nom,nom);
		indice++;
	} else {
		printf("Vector lleno\n");
	}
}

void borrar_dato(char *nom,struct nodo *Pini)
{
	int i,j;
	for (i=0;(i<indice) && strcmp(nom,(Pini[indice].dato).nom);i++);
	if (strcmp(nom,(Pini[indice].dato).nom))
		for(j=i;j<indice;j++)
			Pini[j]=Pini[j+1];
	else
		printf("Dato no encontrado");
}

int verificar_existencia_dato(char *nom,struct nodo *Pini)
{
	int i;
	for (i=0;(i<indice) && strcmp(nom,(Pini[indice].dato).nom);i++);

	if (strcmp(nom,(Pini[indice].dato).nom))
		return 1;
	else
		return 0;
}

void modificar_valor_dato(char *nom,struct nodo *Pini,float venta)
{
	int i;
	for (i=0;(i<indice) && strcmp(nom,(Pini[indice].dato).nom);i++);
	(Pini[indice].dato).acum+=(venta*(Pini[indice].dato).com);
	(Pini[indice].dato).vent++;
}

struct nodo *listar_datos(struct nodo *q)
{
	if(listado==0) {
		listado++;
		return q;
	} else {
		if(listado<indice) {
			listado++;
			return q+1;
		} else {
			listado=0;
			return NULL;
		}
	}
}
