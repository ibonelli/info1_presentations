/*    Calcula el factorial de un entero N     */
/*      utilizando una funcion recursiva.     */

#include <stdio.h>

unsigned long int FACT(int N);
main()
{
    int N;
    N = 4;
    printf("\n\t%12d\t\t  %12lu\n",N,FACT(N));
}

unsigned long int FACT(int N)   /*  FUNCION RECURSIVA  */
{
   if (!N) return 1 ;
   return N * FACT(N-1);
}
