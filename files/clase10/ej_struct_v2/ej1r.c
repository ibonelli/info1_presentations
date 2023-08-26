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
	char buf[21];
	int i, cant, out;
    int fd1 = open("alumnos.txt", O_RDONLY);
	int fd2 = open("alumnos.dat", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

	cant=1, i=0;
	while (cant!=0) {
		cant=read(fd1, buf, 21);
		add_null_str(buf,21);
		if(cant!=0) {
			strcpy(aux.nom,buf);
		}
		cant=read(fd1, buf, 21);
		add_null_str(buf,21);
		if(cant!=0) {
			strcpy(aux.ape,buf);
		}
		cant=read(fd1, buf, 3);
		if(cant!=0) {
			aux.edad=atoi(buf);
		}
		cant=read(fd1, buf, 6);
		if(cant!=0) {
			aux.legajo=atol(buf);
		}
		// Solo guardo si leyó el último dato
		if(cant!=0) {
			lista[i]=aux;
			i++;
		}
	} 
	cant=i;
    close(fd1);

	for(i=0;i<cant;i++) {
		print_alumno(lista[i]);
		out=write(fd2, (void *) &lista[i], sizeof(struct alumno));
		if(out!=sizeof(struct alumno)) {
			printf("Error en el guardado de la posicion: %d", i);
		}
	}
}
