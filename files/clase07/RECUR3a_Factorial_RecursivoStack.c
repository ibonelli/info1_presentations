/*    Calcula el factorial de un entero N     */
/*      utilizando una funcion recursiva.     */

#include <stdio.h>
#include <windows.h>
//#include <conio.h>
unsigned long int FACT(int N);
int main()
{
    int N;
//    clrscr();
    N = 9 ;
    printf("\n\n\n\tN  =  %d\t\tFactorial  =  %lu",N,FACT(N));
    printf("\n");
    //getch();
    system("pause");
    return 1;
}

unsigned long int FACT(int N)   /*  FUNCION RECURSIVA  */
{
   printf("\n\t\tN  =  %d\t\tDireccion de N  =  %p",N,&N);
   if (!N) return 1 ;
   return N * FACT(N-1);
}
