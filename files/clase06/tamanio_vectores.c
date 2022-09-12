#include <stdio.h>

void str_check(char *str) {
	printf("En la funcion \"str\" tiene %d caracteres\n",
				// No da el tamaño del string!!!
				(int)sizeof(str));
}

int main(void) {
	char cadena[] = "Mi string de prueba";
	int vector[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

	printf("sizeof(char): %d\n", (int) sizeof(char));
	printf("sizeof(int): %d\n", (int) sizeof(int));
	printf("sizeof(size_t): %d\n", (int) sizeof(size_t));
	printf("sizeof(cadena): %d\n", (int) sizeof(cadena));
	printf("sizeof(vector): %d\n", (int) sizeof(vector));
	printf("------------\n");
	printf("Mi \"cadena\" tiene %d caracteres\n",
				(int)(sizeof(cadena)/sizeof(char)));
	printf("Mi \"vector\" tiene %d posiciones\n",
				(int)(sizeof(vector)/sizeof(int)));
	str_check(cadena);
	return 0;
}
