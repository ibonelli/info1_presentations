#include <stdio.h>
#include <malloc.h>
#include <string.h>

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
	struct nodo *sig;
};

void ingresar_dato(char *nom, struct nodo **Pini,float comision)
{
	struct nodo *paux;
	if (Pini==NULL) {
		// Lista vacia
		paux=(struct nodo*) malloc(sizeof(struct nodo));
		(paux->dato).acum=0;
		(paux->dato).vent=0;
		*Pini=paux;
		paux->sig=NULL;
	} else {
		// Lo agrego al principio
		paux=(struct nodo*)malloc(sizeof(struct nodo));
		(paux->dato).acum=0;
		(paux->dato).vent=0;
		paux->sig=*Pini;
		*Pini=paux;
	}
	(paux->dato).com=comision;
	strcpy((paux->dato).nom,nom);
}

void borrar_dato(char *nom,struct nodo **Pini)
{
	struct nodo *paux,*p;
	p=*Pini;
	for (paux=(*Pini)->sig;(paux->sig!=NULL) && strcmp(nom,(paux->dato).nom);paux=paux->sig);
	p=paux;
	if (paux->sig!=NULL)
		p->sig=paux->sig;
	else
		p->sig=NULL;
	free(paux);
}
