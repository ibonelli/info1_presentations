#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char buf[10];
	int i=1, j=5, cant=20, out;
    int fd = open("miarchout.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	//printf("open: %d\n", fd2);

    /* Lee un caracter en cada pasada desde el archivo
     * terminando cuando se quede sin bytes.            */
	do {
		sprintf(buf,"%03d", i);
		out=write(fd, buf, 3);
		sprintf(buf,"%05d", j);
		out=write(fd, buf, 5);
		strcpy(buf,"\n");
		out=write(fd, buf, strlen(buf));
			//printf("%d", out);
		i=i+1;
		j=j+2;
		cant--;
	} while (cant!=0);

    close(fd);
}
