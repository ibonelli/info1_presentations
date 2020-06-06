#include <stdio.h>
#include <string.h>

int main(void) {
	char string[10];
	char *str1 = "abcdefghi";
	char *str2;

	str2 = string;

	printf("string pointer: %p\n",string);
	printf("str1 pointer: %p\n",str1);
	printf("str2 pointer: %p\n",str2);

	strcpy(str2,"MiString");
	printf("%s\n", str2);

	// ERROR
	//str2 = str1;
	// Copio el puntero, no el contenido!
	// Esto en un final equivale a un 2...

	// CORRECTO
	strcpy(str2,str1);
	// Copio el contenido de str1 en str2

	printf("%s\n", str2);
	printf("str1 pointer: %p\n",str1);
	printf("str2 pointer: %p\n",str2);

	return 0;
}
