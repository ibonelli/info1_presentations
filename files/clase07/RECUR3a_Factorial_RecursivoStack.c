/*    Calcula el factorialorial de un entero N     */
/*      utilizando una funcion recursiva.     */

#include <stdio.h>
#include "getch.h"

unsigned long int factorial(int N);

int main(void)
{
    int N;
    N = 9 ;
    printf("\n\n\n\tN  =  %d\t\tfactorialorial  =  %lu",N,factorial(N));
    printf("\n");
    getch();
    return 1;
}

unsigned long int factorial(int N)   /*  FUNCION RECURSIVA  */
{
   printf("\n\t\tN  =  %d\t\tDireccion de N  =  %p",N,&N);
   if (!N) return 1 ;
   return N * factorial(N-1);
}
