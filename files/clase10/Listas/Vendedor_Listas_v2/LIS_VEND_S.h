#include "LIS_VEND_LC.h"
#include "LIS_VEND_SN.h"
#include "LIS_VEND_LCF.h"

/* ---------------------------------------------------- */
/* Funciones a usar para una lista simplemente enlazada */
/* ---------------------------------------------------- */

struct nodo *inicializar_datos()
{
	struct nodo *paux;
	paux=(struct nodo *) malloc(sizeof(struct nodo));
	paux->sig=NULL;
	return paux;
}

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
