#include <string.h>
#include <stdio.h>

void main(void) {
	char *buf1 = "aaa", *buf2 = "bbb", *buf3 = "ccc", *buf4 = "bbb";
	int ptr;

	// buffer 2 mayor o menor que buffer 1?
	ptr = strcmp(buf2, buf1);
	if (ptr > 0)
		printf("buffer 2 es mayor que buffer 1\n");
	else
		printf("buffer 2 es menor que buffer 1\n");

	// buffer 2 mayor o menor que buffer 3?
	ptr = strcmp(buf2, buf3);
	if (ptr > 0)
		printf("buffer 2 es mayor que buffer 3\n");
	else
		printf("buffer 2 es menor que buffer 3\n");

	// buffer 2 es igual a buffer 4?
	ptr = strcmp(buf2, buf4);
	if (ptr == 0)
		printf("buffer 2 es igual que buffer 4\n");
	else
		printf("buffer 2 es distinto que buffer 4\n");
}
