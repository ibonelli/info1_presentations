/*
 * Ejemplo de campos de bits
 * GCC : gcc -o campos-de-bit campos-de-bit.c -g -ggdb -Wall
 * 		Para compilar este programa necesita getch.h en la misma carpeta
 */

#include <stdio.h>
#include <stdlib.h>
#include "getch.h"
#include <stdio_ext.h>

struct alfa {
	unsigned char c:1;
	unsigned char a:2;
	unsigned char b:3;
	};

struct beta {
	unsigned int d:5;
	unsigned int e:9;
	unsigned int f:2;
	};

union gama {
	unsigned char g;
	struct alfa h;
	};

union delta {
	unsigned int i;
	struct beta j;
	};

void convBinGamma(union gama);
void convBinDelta(union delta);

int main(void)
{
	union gama k;
	union delta l;

	system("clear");

	k.g = 0;

	k.h.a=2;
	k.h.b=5;
	k.h.c=1;

	l.i = 0;

	l.j.d=25;
	l.j.e=368;
	l.j.f=3;

	printf("\n\n%x\t%x\t%x\t\t%X",k.h.a,k.h.b,k.h.c,k.g);
	convBinGamma(k);
	printf("\n\n%x\t%x\t%x\t\t%X",l.j.d,l.j.e,l.j.f,l.i);
	convBinDelta(l);
	printf("\n\nk=%d\tl=%d\n\n",sizeof(k),sizeof(l));

	__fpurge(stdin);
	getch();

	return 0;
}

void convBinGamma(union gama m)
{
	unsigned char n,o=0x80;
	printf("\n\n");
	for(n=0;n<8;n++)
		if(m.g&(o>>n))
				printf("1");
			else
				printf("0");
	printf("\t");
}

void convBinDelta(union delta p)
{
	unsigned int q,r=0x8000;
	printf("\n\n");
	for(q=0;q<16;q++)
		if(p.i&(r>>q))
				printf("1");
			else
				printf("0");
	printf("\t");
}
