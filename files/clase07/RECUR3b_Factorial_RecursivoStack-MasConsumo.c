/*    Calcula el factorial de un entero N     */
/*      utilizando una funcion recursiva.     */

#include <stdio.h>

#define MAX 100

unsigned long int FACT(int N);

main()
{
  char c;
  int N;
  do {
    printf("\nIngrese un numero: ");
    scanf("%d",&N);
    fflush(stdin);
    printf("\n\t%12d\t\t  %12lu\n",N,FACT(N));
    printf("\n\nOtro numero? (s/n): ");
    c=getchar();
  } while(c=='s');
}

unsigned long int FACT(int N)   /*  FUNCION RECURSIVA  */
{
  char vec[MAX], i; /* Gastamos memoria de la pila */
  for(i=0;i<MAX;i++) vec[i]=i; /* Para que realmente la tome, hay que asignarla */
  printf("\n %d \t %p ",N,&N);
  
  if (!N) return 1 ;
  return N * FACT(N-1);
}
