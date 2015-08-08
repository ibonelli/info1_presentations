/*
 * Funciones comunes a listas simples y dobles
 */

struct nodo *listar_datos(struct nodo *q)
{
	return q->sig;
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

void modificar_valor_dato(char *nom,struct nodo *Pini,float venta)
{
	struct nodo *paux;
	for(paux=Pini->sig;strcmp(nom,(paux->dato).nom);paux=paux->sig);
	(paux->dato).acum+=(venta*(paux->dato).com);
	(paux->dato).vent++;
}
