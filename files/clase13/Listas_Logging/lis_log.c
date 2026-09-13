#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lis_log.h"

void log_lista(const char* tag, const char* message, struct nodo *Pini) {
   time_t now;
   struct tm *tm_info;
   char timestamp[20];
   FILE *fp;

   time(&now);
   tm_info=localtime(&now);
   strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

   fp=fopen("./listas.log","a");
   if (fp == NULL)
      return;
   fprintf(fp,"-------------------------------------------\n");
   fprintf(fp,"%s [%s]: %s\n", timestamp, tag, message);
   fprintf(fp,"-------------------------------------------\n");
   print_list(fp, Pini);
   fclose(fp);
}

void print_list(FILE *fp, struct nodo *Pini) {
   int i = 0;
	struct nodo *p=Pini->sig;
	fprintf(fp,"Pini: %p\n", (void*)Pini);
	fprintf(fp,"Pini->sig: %p\n", (void*)Pini->sig);
	while(p) {
		fprintf(fp,"\t%d",i);
		fprintf(fp,"\tp: %p\n", (void*)p);
		fprintf(fp,"\tp->sig: %p\n", (void*)p->sig);
		i++;
      p=p->sig;
	}
}

void log_lista_mark() {
   FILE *fp;
   fp=fopen("./listas.log","a");
   fprintf(fp,"===========================================\n");
   fclose(fp);
}