/*    Calcula un coeficiente de Fibonacci     */
/*      utilizando una funcion iterativa.     */

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

int fibonacci(int N)   /*  FUNCION ITERATIVA  */
{
   int fib_ant=1,fib=1,I,aux;
   if (N<=1) return 1 ;
   for(I=2;I<=N;I++) {
	aux = fib_ant ;
	fib_ant = fib ;
	fib = fib_ant + aux ;
   }
   return fib ;
}