#define MAX_STR 20

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *pi=NULL;
	char *pc=NULL;
	char *str=NULL;

	printf("pi: %p\n", pi);
	printf("pc: %p\n", pc);
	printf("str: %p\n", str);

	pi = (int *) malloc( sizeof(int) );
	if(pi == NULL)
		printf("No se pudo alojar la memoria.\n");

	pc = (char *) malloc( sizeof(char) );
	if(pc == NULL)
		printf("No se pudo alojar la memoria.\n");

	str = (char *) malloc( sizeof(char) * MAX_STR );
	if(str == NULL)
		printf("No se pudo alojar la memoria.\n");

	printf("----------------\n", pi);
	printf("pi: %p\n", pi);
	printf("pc: %p\n", pc);
	printf("str: %p\n", str);

	return 0;
}
