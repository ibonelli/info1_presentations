#include <stdio.h>

int main()
{
	FILE *file = fopen("miarch.txt", "r");
	FILE *file2 = fopen("miarchout.txt", "w");

	int x;
	/* Lee un caracter en cada pasada desde el archivo terminando
	 * cuando encuentra EOF.
	*/
	while (( x = fgetc(file)) != EOF ) {
			//printf( "%c", x );
			//fputc(x,file2);
			fprintf(file2,"%x ",(char) x);
		}
	fclose( file );
	fclose( file2 );
}
