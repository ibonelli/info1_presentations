#define BUFSIZE 60
#define CANT 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ej1.h"

int main() 
{
	struct alumno aux, lista[CANT];
	char buf[BUFSIZE], *sp, *freturn;
	int i=0, cant, out;
    FILE *fd1 = fopen("alumnos.csv", "r");
	FILE *fd2 = fopen("alumnos.dat", "w");

	do {
		freturn=fgets(buf, BUFSIZE, fd1);
		if(freturn!=NULL) {
			sp=strtok(buf,",");
			if(sp!=NULL) //nombre
				strcpy(aux.nom,sp);
			sp=strtok(NULL,",");
			if(sp!=NULL) //apellido
				strcpy(aux.ape,sp);
			sp=strtok(NULL,",");
			if(sp!=NULL) //edad
				aux.edad=atoi(sp);
			sp=strtok(NULL,",");
			if(sp!=NULL) //legajo
				aux.legajo = atol(sp);
			lista[i]=aux;
			i++;
		}
	} while (freturn!=NULL);

	cant=i;
    fclose(fd1);

	for(i=0;i<cant;i++) {
		print_alumno(lista[i]);
	}

	out=fwrite((void *) lista, sizeof(struct alumno), cant, fd2);
	if(out!=cant) {
		printf("Error en el guardado. out: %d\n", out);
	}
    fclose(fd2);
}
