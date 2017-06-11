/*    Calcula un coeficiente de Fibonacci     */
/*      utilizando una funcion recursiva.     */
/*   Determina niveles de recursividad        */

#include <stdio.h>
#include <conio.h>
int numrec , rec , maxrec ;
main()
{
    int N;
    clrscr();
    printf("Ingrese el orden del numero de Fibonacci  ");
    scanf("%d",&N);
    printf("\n\nF%d   =   %d",N,fibonacci(N));
    printf("\n\nCantidad de recursiones       =  %d",numrec);
    printf("\n\nMaximo nivel de recursividad  =  %d",maxrec);
    getch();
}

int fibonacci(int N)   /*  FUNCION RECURSIVA  */
{
   int fibo=1;
   numrec++;
   rec++;
   if(rec>maxrec) maxrec=rec ;
   if (N>1)
	fibo = fibonacci(N-1) + fibonacci(N-2);
   rec--;
   return fibo;
}