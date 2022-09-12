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

void add_null_str(char *str, int size) {
	int i=0, seguir=1;
	do{
		if(str[i]==' ') {
			str[i]=0;
			seguir=0;
			//printf("Debug: %d\n", i);
		} else {
			i++;
		}
	} while(seguir!=0);
}

int main()
{
	struct alumno aux, lista[5];
	char buf[20];
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
		printf("  nombre: %s\n", lista[i].nom);
		printf("apellido: %s\n", lista[i].ape);
		printf("    edad: %d\n", lista[i].edad);
		printf("  legajo: %ld\n\n", lista[i].legajo);
		out=write(fd2, (void *) &lista[i], sizeof(struct alumno));
		if(out!=sizeof(struct alumno)) {
			printf("Error en el guardado de la posicion: %d", i);
		}
	}
}
