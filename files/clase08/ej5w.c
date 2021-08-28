#include <stdio.h>

#define N 10
#define DEBUG 0

int main(void)
{
	FILE *fp1, *fp2;
	int v[N],aux;
	int i,leido;

	fp1=fopen("misnum.txt","r");
	fp2=fopen("misnum.dat","w");

	// Levanto el archivo en modo texto
	i=0;
	do {
		leido=fscanf(fp1,"%d\n",&aux);
		if( leido==1 ) {
			v[i] = aux;
			if(DEBUG) printf("%d\n",*(v+i));
		}
		i++;
	} while( leido==1 && i < N );

	// Lo guardo en modo binario
	fwrite(v,sizeof(int),i,fp2);

	// Cerrando
	fclose(fp1);
	fclose(fp2);

	return 0;
}
