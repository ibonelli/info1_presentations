/*
 * Estructura del nodo para listas dobles
 */

struct nodo {
	struct vendedor dato;
	struct nodo *sig, *ant;
};
