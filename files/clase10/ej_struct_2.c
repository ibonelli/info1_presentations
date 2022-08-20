struct alumno {
	char nom[20];
	char ape[20];
	int edad;
	long legajo;
};

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct alumno aux, lista[5];
	int i, cant, out;
    int fd1 = open("alumnos.dat", O_RDONLY);

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
		printf("  nombre: %s\n", lista[i].nom);
		printf("apellido: %s\n", lista[i].ape);
		printf("    edad: %d\n", lista[i].edad);
		printf("  legajo: %ld\n\n", lista[i].legajo);
	}
}
