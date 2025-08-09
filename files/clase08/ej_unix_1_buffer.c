#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define TAM 50

int main()
{
	char buf[TAM];
	int cant;
	int i;
    int fd = open("miarch.txt", O_RDONLY);

    /* Lee un caracter en cada pasada desde el archivo
     * terminando cuando se quede sin bytes.            */
	do {
		cant=read(fd, buf, TAM);
		if(cant!=0)
			for (i=0;i<cant;i++)
				printf("%c", buf[i]);
	} while (cant!=0);

    close(fd);
}
