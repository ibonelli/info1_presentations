/*
 * Archivo a incluir en LIS_VEND.c
 */

int mostrar_menu()
{
int choice;

printf("1.- Ingresar un vendedor\n");
printf("2.- Ingresar una venta\n");
printf("3.- Borrar un vendedor\n");
printf("4.- Listado\n");
printf("5.- Cerrar mes\n");
printf("6.- Salir\n");
scanf("%d",&choice);

return choice;
}

void mostrar_datos(vend aux)
{
	printf("nombre y apellido: %s\n", aux.nom);
	printf("comisiones:%f\n",aux.acum);
	printf("cantidad de ventas:%d\n", aux.vent);
}

void mostrar_datos_listar(vend aux)
{
	mostrar_datos(aux);
	printf("comision sobre las ventas %f\n", aux.com);
}

void ingresar_vendedor(struct nodo *Pini)
{
	int i;
	char nombre[40];
	float com;
	printf("Ingrese el nombre del vendedor:\n");
	scanf("%s", nombre);
	if (verificar_existencia_dato(nombre,Pini)) {
		printf("Ingrese la comision:\n");
		scanf("%f",& com);
		ingresar_dato(nombre,Pini,com);
	}
	else
		printf("El vendedor ya existe!\n");
}

void ingresar_venta(struct nodo *PINI)
{
	char nombre[40];
	float valor_venta;
	printf("Ingrese el nombre del vendedor:\n");
	scanf("%s",nombre);
	if (!verificar_existencia_dato(nombre,PINI)) {
		printf("Ingrese el valor de la venta:\n");
		scanf("%f",&valor_venta);
		modificar_valor_dato(nombre,PINI,valor_venta);
	}
	else
		printf("El vendedor no existe!\n");
}

void borrar_vendedor(struct nodo *Pini)
{
	char nombre[40];
	printf("ingrese el nombre del vendedor:\n");
	scanf("%s",nombre);
	if (verificar_existencia_dato(nombre,Pini))
		borrar_dato(nombre,Pini);
	else
		printf("el vendedor no existe");
}

void listar(struct nodo *Pini)
{
	struct nodo *paux;
	paux=listar_datos(Pini);
	while(paux) {
		mostrar_datos_listar(paux->dato);
		paux=listar_datos(paux);
		}
}

void cerrar_mes(struct nodo *Pini)
{
	struct nodo *paux;
	int total_ventas;
	float total_a_pagar;
	paux=listar_datos(Pini);
	while(paux) {
		mostrar_datos(paux->dato);
		total_ventas+=(paux->dato).vent;
		total_a_pagar+=(paux->dato).acum;
		paux=listar_datos(paux);
		}
	printf("total de ventas: %d\n", total_ventas);
	printf("total a pagar:%f\n",total_a_pagar);
}
