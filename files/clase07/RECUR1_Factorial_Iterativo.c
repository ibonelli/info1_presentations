/*    Calcula el factorial de un entero N     */
/*      utilizando una funcion iterativa.     */

#include <stdio.h>

unsigned long int FACT(int N);

main()
{
    int N;
    N = 4;
    printf("\n\t%12d\t\t  %12lu\n",N,FACT(N));
}

unsigned long int FACT(int N)   /*  FUNCION ITERATIVA  */
{
   unsigned long int PROD = 1;
   int I;
   for(I=N;I>0;I--)
	PROD *= I ;
   return PROD;
}
