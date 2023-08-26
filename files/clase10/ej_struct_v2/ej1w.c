#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ej1.h"

int main()
{
	struct alumno aux, lista[5];
	int i, cant, out;
    int fd1 = open("alumnos.dat", O_RDONLY);

	if(fd1<0) {
		printf("Error al abrir el archivo\n");
		exit(-1);
	}

	cant=1, i=0;
	while (cant!=0) {
		cant=read(fd1, (void *) &aux, sizeof(struct alumno));
		if(cant!=0) {
			lista[i]=aux;
			i++;
		}
	} 
	cant=i;
    close(fd1);

	for(i=0;i<cant;i++) {
		print_alumno(lista[i]);
	}
}
