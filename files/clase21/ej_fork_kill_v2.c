//Ejemplo 2: Crea un hijo con fork, para luego matarlo con kill PID

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i, iPi = fork ();
	if (iPi > 0) {
		printf ("Desde el padre muestro el PID del hijo: %d\n", iPi);
			for(i=0;i<30;i++) {
				sleep(1);
				printf(".");
				// Fuerzo a que lo que haya en el buffer stdout salga por pantalla
				fflush(stdout);
				// Otra forma es agregarle el salto de linea
				// printf(".\n"); // Pero queda uno por linea...
			}
		printf("\n");
	}
	if (iPi == 0) { //Este es el hijo
		printf ("Desde el hijo muestro su propio PID: %d\n", getpid ());
		while (1) {
			sleep(1);
		}
	}
	if (iPi < 0)
		printf ("Error al crear el hijo");

	return 0;
}
