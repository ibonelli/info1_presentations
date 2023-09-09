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
/* En este caso la lista es ordenada por nom[40]        */
/* ---------------------------------------------------- */

struct nodo {
	struct vendedor dato;
	struct nodo *sig;
};

void ingresar_dato(char *nom, struct nodo **Pini,float comision)
{
	struct nodo *paux, *pact, *pant;
	paux=(struct nodo*)malloc(sizeof(struct nodo));
	if (Pini==NULL) {
		// Lista vacia
		*Pini=paux;
		paux->sig=NULL;
	} else {
		// Busco en la lista donde ingresarlo
		pant=pact=*Pini;
		while (pact!=NULL && strcmp(nom, pact->dato.nom)>0) {
			pant=pact;
			pact=pact->sig;
		}
		// De este for salimos con paux apuntando a donde debemos ingresar el nuevo nodo
		if (pact==*Pini) {
			// Lo agrego al principio
			paux->sig=*Pini;
			*Pini=paux;
		} else {
			if (pact==NULL) {
				// Lo agrego al final
				pant->sig=paux;
				paux->sig=NULL;
			} else {
				// Lo agrego en el medio
				pant->sig=paux;
				paux->sig=pact;
			}
		}
		(paux->dato).acum=0;
		(paux->dato).vent=0;
		(paux->dato).com=comision;
		strcpy((paux->dato).nom,nom);
	}
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
