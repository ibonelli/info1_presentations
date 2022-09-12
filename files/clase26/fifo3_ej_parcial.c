#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


int agregarInicio (char *nombre, char *texto);
int enviarInvertido  (char *fifoName, char *fileName);

int main (void)
{

    printf ("%d\r\n", enviarInvertido ("./myFifo", "./prueba.txt"));

    return (0);
}

int enviarInvertido  (char *fifoName, char *fileName)
{
FILE *f;
int rVal, i, fd, cantRead;
void *p;
struct stat st;

    //-- Creo el nodo fifo --
    rVal = mknod (fifoName, S_IFIFO | 0666, 0);
    if (rVal == -1) {
        if (errno != EEXIST) {
            printf ("Error mknod");
            return (-1);
        }
    }

    //-- Abro el archivo --
    f = fopen (fileName, "r");
    if (f == NULL) {
        perror ("Error al abrir el archivo\r\n");
        return (-2);
    }

    //-- Obtengo el tamanio --
    rVal = stat(fileName, &st);
    if (rVal < 0) {
        printf ("Error en fstat\r\n");
        return (-5);
    }

    //-- Reservo memoria --
    p = malloc (st.st_size);
    if (p == NULL) {
        printf ("Error en fstat\r\n");
        return (-6);
    }

    //-- Leo --
    cantRead = fread (p, 1, st.st_size, f);
    if (cantRead < 0) {
        printf ("Error al leer en el archivo\r\n");
        return (-3);
    }

    //-- Cierro --
    rVal = fclose (f);
    if (rVal != 0) {
        printf ("Error al cerrar el archivo\r\n");
        return (-7);
    }

    //-- Abro la fifo como escritura --
    fd = open (fifoName, O_WRONLY);
    if (fd < 0) {
        printf ("Error fifo");
        return (-8);
    }

    for (i = st.st_size; i >= 0; i--) {
        rVal = write (fd, (p +  i), 1);
        printf("%d\n", i);
    }

    free (p);    
    return (0);
}
