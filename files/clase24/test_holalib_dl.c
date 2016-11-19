/* Programa de prueba para nuestra librería holalib
 * Usando bibliotecas de carga dinámica
 */

# include "holalib.h"
# include <dlfcn.h>
# include <stdlib.h>

int main(int argc, char **argv)
{
	void *handle;
	void (*hello) (void);
	char *error;

	/*
	 * Se abre la librería y se obtiene en handle un puntero a la
	 * instancia de la misma
	 */
	handle = dlopen("libhola.so.1",RTLD_LAZY);

	/*
	 * Si handle es NULL, entonces se imprime el mensaje devuelto por
	 * dlerror en stderr
	 */
	if (!handle) {
		fprintf (stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	/*
	 * En hello se guarda el puntero al label llamado hola en la
	 * librería.
	 */
	hello = dlsym (handle, "hola");
	if ((error = dlerror()) != NULL) {
		fputs(error, stderr);
		exit(EXIT_FAILURE);
		}

	/*
	 * Se invoca la función por medio de su puntero. Aquí es donde
	 * aparece el mensaje característico de nuestra librería.
	 */
	(*hello) ();

	dlclose(handle);
	return 0;
}
