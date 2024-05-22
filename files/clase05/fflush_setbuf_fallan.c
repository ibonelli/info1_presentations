/**
*****************ENCABEZADO DEL MAIN*************************
*
*  Infomática I
*  Año: 2024
*  Marina Rodriguez Aguado e Ignacio Javier Bonelli
*  Observaciones: 
* 				para compilar y ejecutar se usaron estas lineas:
* 				gcc ej2.c -Wall -std=c89 -pedantic-errors -o  ej2
* 				./ej2
*  Probar ingresando un string largo, por ejemplo: "ABCDEFGHIJK"
**/


#include <stdio.h>
#define N 5
int main(){
	char c;
	char s[N]="Hola";

	printf("s: %s\n",s);

	printf("Ingrese un string: ");
	fgets(s,N,stdin);
	//setbuf(stdin,NULL);
	// As setbuf() does not work every time...
	while((c = getchar()) != '\n' && c != EOF);
		/* discard */ ;
	// Only portable way to do it
	//		https://c-faq.com/stdio/stdinflush2.html
	printf("s: %s\n",s);

	printf("Ingrese un string: ");
	fgets(s,N,stdin);
	while((c = getchar()) != '\n' && c != EOF);
	printf("s: %s\n",s);

	printf("Ingrese un string: ");
	fgets(s,N,stdin);
	while((c = getchar()) != '\n' && c != EOF);
	printf("s: %s\n",s);

	printf("Ingrese un string: ");
	fgets(s,N,stdin);
	while((c = getchar()) != '\n' && c != EOF);
	printf("s: %s\n",s);

	return 0;
}
