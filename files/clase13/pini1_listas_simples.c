/* Ingresa elementos al final */

void ingresa(struct lis **p)
{
	struct lis *act,*aux;
	act=*p;
	if(!aux=(struct lis *)malloc(sizeof(struct lis)) {
		printf("\n\nNo hay memoria\n");
		return;
		}
	endat(&aux);
	aux->sig=NULL;
	if(!*p) {
		*p=aux;
		return;
		}
	while(act->sig)
		act=act->sig;
	act->sig=aux;
}

/* Inserta elementos ordenadamente */

void ingresa(struct lis **p)
{
	struct lis *act,*aux,*ant;
	aux=(struct lis *)malloc(sizeof(struct lis));
	endat(&aux);
	if(!*p) {
		// in_pr_el1();
		*p=aux;
		aux->sig=NULL;
		return;
		}
	ant=act=*p;
	while((act->dato<aux->dato)&&act) {
		ant=act;
		act=act->sig;
		}
	if(!act) {
		// in_ul_el()
		ant->sig=aux;
		aux->sig=NULL;
		return;
		}
	if(ant==act) {
		// in_pr_el()
		*p=aux;
		aux->sig=ant;
		return;
		}
	// ele_int()
	ant->sig=aux;
	aux->sig=act;
}

/* Borrar elementos */

void borra(struct lis **p)
{
	struct lis *aux,*ant;
	int b;
	b=ingdat();
	aux=*p;
	ant=*p;
	while((b!=aux->dato)&&(aux)) {
		ant=aux;
		aux=aux->sig;
		}
	if((*p==aux)&&(aux)) {
		// boprida()
		impdat(aux);
		if(condat()) {
			*p=aux->sig;
			free(aux);
			return;
		}
	}
	if(aux) {
		// datint()
		impdat(aux);
		if(condat()) {
			ant->sig=aux->sig;
			free(aux);
			return;
		}
	}
	printf("\nDatos no existen");
}
