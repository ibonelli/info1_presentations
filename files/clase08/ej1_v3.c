#include <stdio.h>

int main()
{
	FILE *file = fopen("miarch2.txt", "r");
	FILE *file2 = fopen("miarchout2.txt", "w");

	int x;
	char c;

	/* Lee un caracter en cada pasada desde el archivo terminando
	 * cuando encuentra EOF.
	*/
	while (( x = fgetc(file)) != EOF ) {
		c = (char) x;
		if (c == 0x0a) {
			fprintf(file2,"\n");
		} else {
			fprintf(file2,"%x ",c);
		}
	}
	fclose( file );
	fclose( file2 );
}
