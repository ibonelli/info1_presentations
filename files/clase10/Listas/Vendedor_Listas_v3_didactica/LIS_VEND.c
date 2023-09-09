/*
Realizar un programa que maneje el ingreso de vendedores.
Debe poder agregarse un vendedor y luego agregar ventas de
ese vendedor.

Se debera poder listar las ventas durante el mes, y al final
del mes se debe generar un cierre del mes informando total
de ventas y comisiones a pagar.
*/

/*
 * Depende de cual usamos usara se inserta al principio o ordenadamente.
 * Sin ordernar (LIS_VEND_S.h) ingresa al principio.
 * Y LIS_VEND_SO.h ingresa ordenadamente por nombre los nodos.
 */

#include <stdio.h>
//Lista sin ordernar
//#include "LIS_VEND_S.h"
//Lista ordernada por nombre
#include "LIS_VEND_SO.h"
#include "LIS_VEND.h"

void main (void)
{
	struct nodo *ini_datos=NULL;
	int opcion;
	do {
		opcion=mostrar_menu();
		switch(opcion){
			case 1:	ingresar_vendedor(&ini_datos); break;
			case 2:	ingresar_venta(ini_datos); break;
			case 3:	borrar_vendedor(&ini_datos); break;
			case 4:	listar(ini_datos); break;
			case 5:	cerrar_mes(ini_datos); break;
		}
	}while(opcion!=6);
}
