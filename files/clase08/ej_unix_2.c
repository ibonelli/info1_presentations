#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char buf[5];
	int cant, out;
    int fd1 = open("miarch.txt", O_RDONLY);
    int fd2 = creat("miarch2.txt", O_WRONLY);
	//printf("open: %d\n", fd2);

    /* Lee un caracter en cada pasada desde el archivo
     * terminando cuando se quede sin bytes.            */
	do {
		cant=read(fd1, buf, 1);
		if(cant!=0) {
			out=write(fd2, buf, 1);
			//printf("%d", out);
		}
	} while (cant!=0);

    close(fd1);
    close(fd2);
}
