#include<stdio.h>

typedef enum {pepe, juan} mis_datos;
mis_datos x, y;

int main(void)
{
 x = pepe;
 y = juan;
 
 printf("x vale %d\n", x);
 printf("y vale %d\n", y);

 printf("\ntamaño: %d\n", sizeof(mis_datos));

 return 0;
}
