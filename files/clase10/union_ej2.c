#include <stdio.h>

typedef unsigned char uchar;

typedef struct {
	uchar nl:4;
	uchar nh:4;
} hexa;

union byte {
   uchar b;
   hexa h;
};

void main(void) {
	union byte A;
	char str[3];

	A.b = 0x3A;
	printf("nh: %d\n",A.h.nh); /* Muestra 4 */
	printf("nl: %d\n",A.h.nl); /* Muestra 8 */

	/* Convirtiendo en string la parte alta */
	if(A.h.nh<10)
		str[0] = '0' + A.h.nh;
	else
		str[0] = 'A' + A.h.nh - 10;

	/* Convirtiendo en string la parte baja */
	if(A.h.nl<10)
		str[1] = '0' + A.h.nl;
	else
		str[1] = 'A' + A.h.nl - 10;

	/* Agregamos el fin del string */
	str[2] = '\0';

	printf("str: %s\n", str); /* Muestra el str creado */
}
