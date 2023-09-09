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
	// Ingreso del nodo a la lista
	if (*Pini==NULL) {
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
	}
	// Ingreso los datos del nodo
	(paux->dato).acum=0;
	(paux->dato).vent=0;
	(paux->dato).com=comision;
	strcpy((paux->dato).nom,nom);
}

int verificar_existencia_dato(char *nom, struct nodo *Pini)
{
	// Devuelve verdadero (1) si lo encuentra
	struct nodo *paux;
	paux=Pini;
	if(paux!=NULL) {
		while(strcmp(nom,(paux->dato).nom) && paux->sig != NULL)
			paux=paux->sig;
		if(paux!=NULL) {
			if(strcmp(nom,(paux->dato).nom)==0) {
				// Encontrado!
				return 1;
			} else {
				// No lo encontró
				return 0;
			}
		} else {
			// Si paux es NULL se "cayó" de la lista
			return 0;
		}
	} else {
		// Si paux es NULL la lista está vacía
		return 0;
	}
}

void borrar_dato(char *nom, struct nodo **Pini)
{
	struct nodo *pact, *pant;

	pact=pant=*Pini;
	if(pact!=NULL) {
		// La lista no está vacía
		while(strcmp(nom,(pact->dato).nom) && pact->sig!=NULL) {
			pant=pact;
			pact=pact->sig;
		}
	}

	if(pact!=NULL && strcmp(nom,(pact->dato).nom)==0) {
		// Encontrado, podemos borrarlo
		if (pact==*Pini) {
			// Borrando el primer elemento
			// Este código y condición también funciona si es el último elemento
			*Pini=pact->sig;
		} else {
			if (pact->sig==NULL) {
				// Borrando el último de la lista
				pant->sig=NULL;
			} else {
				// Borrando en el medio de la lista
				pant->sig=pact->sig;
			}
		}
	}

	free(pact);
}
