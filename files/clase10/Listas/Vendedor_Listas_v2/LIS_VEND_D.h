#include "LIS_VEND_LC.h"
#include "LIS_VEND_DN.h"
#include "LIS_VEND_LCF.h"

/* --------------------------------------------------- */
/* Funciones a usar para una lista doblemente enlazada */
/* --------------------------------------------------- */

struct nodo *inicializar_datos()
{
	struct nodo *paux;
	paux=(struct nodo *) malloc(sizeof(struct nodo));
	paux->sig=NULL;
	return paux;
}

void ingresar_dato(char *nom, struct nodo *Pini,float comision)
{
	struct nodo *paux,*p;
	paux=(struct nodo*)malloc(sizeof(struct nodo));
	if (Pini->sig==NULL) {
		// Lista vacia
		Pini->sig=paux;
		paux->sig=NULL;
		paux->ant=NULL;
	}
	else {
		if((Pini->sig)->sig==(Pini->sig)->ant) {
			if(strcmp(nom,Pini->dato.nom)) {
				// Inserto al principio
				paux->sig=Pini->sig;
				(Pini->sig)->ant=paux;
				Pini->sig=paux;
				paux->ant=NULL;
			}
			else {
				// Inserto al final
				paux->sig=NULL;
				(Pini->sig)->sig=paux;
				paux->ant=Pini->sig;
			}
		}
		else {
			for (p=Pini->sig;(p->sig!=NULL) && strcmp(nom,(p->dato).nom);p=p->sig);
			// Inserto ordenadamente
			paux->ant=p->ant;
			paux->sig=p;
			p->ant=paux;
			(paux->ant)->sig=paux;
		}
	}
	(paux->dato).com=comision;
	strcpy((paux->dato).nom,nom);
}

void borrar_dato(char *nom,struct nodo *Pini)
{
	struct nodo *paux;
	for (paux=Pini->sig;(paux->sig!=NULL) && strcmp(nom,(paux->dato).nom);paux=paux->sig);
	if (paux->ant==NULL) {
		(paux->sig)->ant=NULL;
		Pini->sig=paux->sig;
		}
	else {
		if(paux->sig==NULL)
			(paux->ant)->sig=NULL;
		else {
			(paux->ant)->sig=paux->sig;
			(paux->sig)->ant=paux->ant;
			}
		}
	free(paux);
}
