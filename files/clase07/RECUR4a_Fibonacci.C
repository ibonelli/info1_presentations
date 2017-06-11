/*    Calcula un coeficiente de Fibonacci     */
/*      utilizando una funcion recursiva.     */

#include <stdio.h>
#include <conio.h>

main()
{
    int N;
    clrscr();
    printf("Ingrese el orden del numero de Fibonacci  ");
    scanf("%d",&N);
    printf("\n\nF%d   =   %d",N,fibonacci(N));
    getch();
}

int fibonacci(int N)   /*  FUNCION RECURSIVA  */
{
   if (N<=1) return 1 ;
   return fibonacci(N-1) + fibonacci(N-2);
}