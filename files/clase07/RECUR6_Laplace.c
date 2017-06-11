#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 15
float LAPLACE(int *,int);
main()
{
  int mat[N*N],n,i,j;
  clrscr();
  printf("Ingrese el orden de la matriz = ");
  scanf("%d",&n);

  /*  Generacion  */
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      /*scanf("%d",&mat[i*n+j]);*/
      mat[i*n+j]=random(10);

  /*  Impresion  */
  clrscr();
  printf("\n\n\n");
  for(i=0;i<n;i++) {
    printf("\t\t\t");
    for(j=0;j<n;j++)
      printf("%4d",mat[i*n+j]);
    printf("\n\n");
  }
  getch();

  printf("\n\nDETERMINANTE = %2.0f",LAPLACE(mat,n));
  getch();
}

float LAPLACE(int mat[],int n)
{
  float det=0.0;
  int vec[N*N],i,j,k,L,h=1;
  if(n==2) {
    det=mat[0]*mat[3]-mat[1]*mat[2];
    return det; }
  for(i=0;i<n;i++) {
    L=0;
    for(j=0;j<n;j++)
      for(k=1;k<n;k++)
        if(j!=i)  {
          vec[L]=mat[n*j+k];
          L++; }
    det=det+h*mat[n*i]*LAPLACE(vec,n-1);
    h=h*(-1);
  }
  return det;
}
