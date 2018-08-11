#include <stdio.h>

typedef unsigned char uchar;

struct hexa {
	uchar nl:4;
	uchar nh:4;
};

union byte {
   uchar b;
   struct hexa h;
};

void main(void) {
	union byte A;
	char str[3];

	A.b=0x48;
	printf("nh: %d\n",A.h.nh); /* Muestra 4 */
	printf("nl: %d\n",A.h.nl); /* Muestra 8 */

	/* Convirtiendo en string */
	str[0] = '0' + A.h.nh;
	str[1] = '0' + A.h.nl;
	str[2] = '\0';

	printf("str: %s\n",str); /* Muestra el str creado */
}
