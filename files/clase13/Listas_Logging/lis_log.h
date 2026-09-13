#ifndef LIS_LOG_H
#define LIS_LOG_H

#include <stdio.h>
#include "lis_vend_s.h"

void print_list(FILE *fp, struct nodo *Pini);
void log_lista(const char* tag, const char* message, struct nodo *Pini);
void log_lista_mark();

#endif /* LIS_LOG_H */
