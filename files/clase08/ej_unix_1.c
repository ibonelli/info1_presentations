#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char buf[5];
	int cant;
    int fd = open("miarch.txt", O_RDONLY);

    /* Lee un caracter en cada pasada desde el archivo
     * terminando cuando se quede sin bytes.            */
	do {
		cant=read(fd, buf, 1);
		if(cant!=0)
			printf("%c", buf[0]);
	} while (cant!=0);

    close(fd);
}
