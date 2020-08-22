#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
typedef struct {
	int     numero;
	char    caracter;
	float   real;
	char    v[10];
	} datos_t1;

typedef struct {
	int     numero;
	float   real;
	char    caracter;
	char    v[10];
	} datos_t2;

typedef struct {
	char    caracter;
	int     numero;
	char    v[10];
	float   real;
	short   chico;
	} datos_t3;

typedef struct {
	char    c1, c2;
	int     numero;
	char    v[10];
	float   real;
	} datos_t4;
    
typedef struct {
	char    c1, c2;
	int     numero;
	char    v[10];
	float   real;
	short   chico;
	} datos_t5;

	datos_t1 n1;
	datos_t1 n1v[10];

	datos_t2 n2;
	datos_t2 n2v[10];

	datos_t3 n3;
	datos_t3 n3v[10];

	datos_t4 n4;
	datos_t5 n5;

	n1.numero=10;
	n1.caracter='a';
	n1.real=3.14;
	strcpy(n1.v, "ABC");

	n2.numero=20;
	n2.caracter='b';
	n2.real=2.71;
	strcpy(n2.v, "DEF");

	n3.numero=30;
	n3.caracter='b';
	n3.real=4.15;
	strcpy(n3.v, "GHI");
	n3.chico=35;

	n4.numero=40;
	n4.c1='b';
	n4.c2='c';
	strcpy(n4.v, "JKL");
	n4.real=5.28;

	n5.numero=50;
	n5.c1='b';
	n5.c2='c';
	strcpy(n5.v, "MNO");
	n5.real=6.28;
	n5.chico=55;

	printf("numero\t%p  numero\t%d\t\tsize int %ld\n",&n1.numero,n1.numero,sizeof(int));
	printf("char\t%p  char\t%c\t\tsize char %ld\n",&n1.caracter,n1.caracter,sizeof(char));
	printf("real\t%p  real\t%0.2f\t\tsize float %ld\n",&n1.real,n1.real,sizeof(float));
	printf("vector\t%p  vector\t%s\t\tsize vector %ld\n",&n1.v,n1.v,sizeof(n1.v));

	printf("size\t%ld\n",sizeof(n1));
	printf("\n");

	printf("numero\t%p  numero\t%d\t\tsize int %ld\n",&n2.numero,n2.numero,sizeof(int));
	printf("real\t%p  real\t%0.2f\t\tsize float %ld\n",&n2.real,n2.real,sizeof(float));
	printf("char\t%p  char\t%c\t\tsize char %ld\n",&n2.caracter,n2.caracter,sizeof(char));
	printf("vector\t%p  vector\t%s\t\tsize vector %ld\n",&n2.v,n2.v,sizeof(n2.v));

	printf("size\t%ld\n",sizeof(n2));
	printf("\n");

	printf("char\t%p  char\t%c\t\tsize char %ld\n",&n3.caracter,n3.caracter,sizeof(char));
	printf("numero\t%p  numero\t%d\t\tsize int %ld\n",&n3.numero,n3.numero,sizeof(int));
	printf("vector\t%p  vector\t%s\t\tsize vector %ld\n",&n3.v,n3.v,sizeof(n3.v));
	printf("real\t%p  real\t%0.2f\t\tsize float %ld\n",&n3.real,n3.real,sizeof(float));
	printf("chico\t%p  chico\t%d\t\tsize short %ld\n",&n3.chico,n3.chico,sizeof(short));

	printf("size\t%ld\n",sizeof(n3));
	printf("\n");

	printf("Vectores\n");
	printf("\tsize n1v\t%ld\n",sizeof(n1v));
	printf("\tsize n2v\t%ld\n",sizeof(n2v));
	printf("\tsize n2v\t%ld\n",sizeof(n3v));
	printf("\n");

	printf("char1\t%p  char1\t%c\t\tsize char %ld\n",&n4.c1,n4.c1,sizeof(char));
	printf("char2\t%p  char2\t%c\t\tsize char %ld\n",&n4.c2,n4.c2,sizeof(char));
	printf("numero\t%p  numero\t%d\t\tsize int %ld\n",&n4.numero,n4.numero,sizeof(int));
	printf("vector\t%p  vector\t%s\t\tsize vector %ld\n",&n4.v,n4.v,sizeof(n4.v));
	printf("real\t%p  real\t%0.2f\t\tsize float %ld\n",&n4.real,n4.real,sizeof(float));

	printf("size\t%ld\n",sizeof(n4));
	printf("\n");

	printf("char1\t%p  char1\t%c\t\tsize char %ld\n",&n5.c1,n5.c1,sizeof(char));
	printf("char2\t%p  char2\t%c\t\tsize char %ld\n",&n5.c2,n5.c2,sizeof(char));
	printf("numero\t%p  numero\t%d\t\tsize int %ld\n",&n5.numero,n5.numero,sizeof(int));
	printf("vector\t%p  vector\t%s\t\tsize vector %ld\n",&n5.v,n5.v,sizeof(n4.v));
	printf("real\t%p  real\t%0.2f\t\tsize float %ld\n",&n5.real,n5.real,sizeof(float));
	printf("chico\t%p  chico\t%d\t\tsize short %ld\n",&n5.chico,n5.chico,sizeof(short));

	printf("size\t%ld\n",sizeof(n5));
	printf("\n");

	return (0);
}
