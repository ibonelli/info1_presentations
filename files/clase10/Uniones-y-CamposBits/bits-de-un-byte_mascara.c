/*
 * Muestro los bits de un byte utilizando mascaras
 */

#include <stdio.h>

char A;
char B0, B2, B3, B4, B5, B6, B7;

A=248;

B0=0x01;
B1=0x02;
B2=0x04;
B3=0x08;
B4=0x10;
B5=0x20;
B6=0x40;
B7=0x80;

if(A&B0)
	printf("b0 = 1");
else
	printf("b0 = 0");

if(A&B1)
	printf("b1 = 1");
else
	printf("b1 = 0");

if(A&B2)
	printf("b2 = 1");
else
	printf("b2 = 0");

...
