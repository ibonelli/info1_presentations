
#ifndef LIS_VEND_H
#define LIS_VEND_H

#include "lis_vend_s.h"

int mostrar_menu();
void mostrar_datos(vend aux);
void mostrar_datos_listar(vend aux);
int verificar_existencia_dato(char *nom,struct nodo *Pini);
void ingresar_vendedor(struct nodo *Pini);
void modificar_valor_dato(char *nom,struct nodo *Pini,float venta);
void ingresar_venta(struct nodo *PINI);
void borrar_vendedor(struct nodo *Pini);
struct nodo *listar_datos(struct nodo *q);
void listar(struct nodo *Pini);
void cerrar_mes(struct nodo *Pini);
struct nodo *inicializar_datos();

#endif /* LIS_VEND_H */
