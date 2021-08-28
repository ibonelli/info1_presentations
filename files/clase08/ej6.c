#include <stdio.h>

int main()
{
	FILE *fp;
	long tam;

	fp=fopen("misnum.dat","r");
	if(fp == NULL) {
		perror("Error opening file");
		return(-1);
	}

	// Muevo el "cursor" hasta el final del archivo
	fseek(fp,0,SEEK_END);

	// Obtengo la cantidad de bytes desde el principio del archivo a la posición actual
	tam = ftell(fp);

	printf("%ld\n",tam);
}
