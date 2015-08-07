#include<stdio.h>

enum mis_datos {pepe, juan};
enum mis_datos x, y;

/*
 * Luego probar con:
 *    enum mis_datos { pepe=33, juan, manolo};
 * (enum2b.c)
 * 
 * Y luego con:
 *    typedef enum...
 *  (enum2c.c)
 */

int main(void)
{
 x = pepe;
 y = juan;
 
 printf("x vale %d\n", x);
 printf("y vale %d\n", y);

 return 0;
}
