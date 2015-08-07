#include<stdio.h>

enum mis_datos { pepe=33, juan, manolo};
enum mis_datos x, y;

int main(void)
{
 x = pepe;
 y = juan;
 
 printf("x vale %d\n", x);
 printf("y vale %d\n", y);

 return 0;
}
