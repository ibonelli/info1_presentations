#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lis_vend_s.h"

/* ---------------------------------------------------- */
/* Funciones a usar para una lista simplemente enlazada */
/* ---------------------------------------------------- */

void ingresar_dato(char *nom, struct nodo *Pini,float comision)
{
	struct nodo*paux;
	if (Pini->sig==NULL) {
		paux=(struct nodo*) malloc(sizeof(struct nodo));
		(paux->dato).acum=0;
		(paux->dato).vent=0;
		Pini->sig=paux;
		paux->sig=NULL;
	}
	else {
		paux=(struct nodo*)malloc(sizeof(struct nodo));
		(paux->dato).acum=0;
		(paux->dato).vent=0;
		paux->sig=Pini->sig;
		Pini->sig=paux;
	}
	(paux->dato).com=comision;
	strcpy((paux->dato).nom,nom);
}

void borrar_dato(char *nom,struct nodo *Pini)
{
	struct nodo *paux,*anterior;
	anterior=Pini;
	paux=Pini->sig;
	while (paux!=NULL && strcmp(nom,(paux->dato).nom)!=0) {
		anterior=paux;
		paux=paux->sig;
	}
	if (paux!=NULL) {
		anterior->sig=paux->sig;
		free(paux);
	}
}
