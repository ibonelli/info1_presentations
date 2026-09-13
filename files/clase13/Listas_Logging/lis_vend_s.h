#ifndef LIS_VEND_S_H
#define LIS_VEND_S_H

struct vendedor {
	char nom[40];
	float com,acum;
	int vent;
};

typedef struct vendedor vend;

struct nodo {
	struct vendedor dato;
	struct nodo *sig;
};

void ingresar_dato(char *nom, struct nodo *Pini,float comision);
void borrar_dato(char *nom,struct nodo *Pini);

#endif /* LIS_VEND_S_H */
