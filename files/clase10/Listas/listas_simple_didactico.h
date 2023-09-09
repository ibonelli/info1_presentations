#include <stdlib.h>

struct nodo {
	int dato;
	struct nodo *sig;
	};

int ls_vacia(struct nodo *INI) {
	if (INI) /* No Vacio */
		return 0;
	else /* Si Vacia */
		return 1;
	}

struct nodo * ls_ingresar (struct nodo *lsp, int dat) {
	struct nodo *p;
	p= (struct nodo *)malloc(sizeof(struct nodo)); /* Suponiendo que nos dan memoria */
	p->dato=dat;
	if(lsp) { /* Lista con datos */
		p->sig=lsp;
	} else { /* Lista Vacia */
		p->sig=NULL;
	}
	return p;
}

int ls_sacar (struct nodo **lsp) {
	int aux;
	struct nodo *p;

	aux = (*lsp)->dato;
	p = *lsp;
	*lsp = (*lsp)->sig;

	free(p);
	return aux;
}

void ls_listar (struct nodo *lsp) {
	struct nodo *p;
	int i;

	for(p=lsp,i=1;p!=0;p=p->sig,i++) {
		printf("-nodo%d----------------------\n",i);
		printf("dir nodo: %p\n",p);
		printf("dato: %d\n",p->dato);
		printf("sig: %p\n",p->sig);
	}
}
