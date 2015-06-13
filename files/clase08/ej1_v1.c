#include <stdio.h>

int main()
{
	FILE *file = fopen("miarch.txt", "r");

	int x;
	/* Lee un caracter en cada pasada desde el archivo terminando
	 * cuando encuentra EOF.
	*/
	while (( x = fgetc(file)) != EOF ) {
			printf( "%c", x );
		}

	fclose( file );
}
