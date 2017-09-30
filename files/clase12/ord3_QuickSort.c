#include <stdio.h>
#include "getch.h"


void quick(char vec[], int izq, int der) {
  int i,j,k;
  char x,y;
  i=izq;j=der;
  x=vec[(izq+der)/2];
  for(k=izq;k<=der;k++)
    printf("    %c",vec[k]);
  printf("\nComparando = %c",x);
  printf("\n");
  do {
    while(vec[i]<x && i<der)
      i++;
    while(x<vec[j] && j>izq)
      j--;
    if (i<=j) {
      y=vec[i];
      vec[i]=vec[j];
      vec[j]=y;
      i++ ; j-- ;
    }
  } while(i<=j);
  for(k=izq;k<=der;k++)
    printf("    %c",vec[k]);
  printf("\n\n");
  if(izq<j)
    quick(vec,izq,j);
  if(i<der)
    quick(vec,i,der);
}

void quick_sort(char vec[],int N) {
  quick(vec,0,N-1);
}

void main(void) {
  void quick_sort(char[],int);
  char vec[10]={'G','B','E','A','L','Z','R','T','P','K'};
  int i;
  printf("Vector desordenado\n");
  for(i=0;i<10;i++)
    printf("    %c",vec[i]);
  printf("\n\n");
  quick_sort(vec,10);
  printf("\nVector ordenado\n");
  for(i=0;i<10;i++)
    printf("    %c",vec[i]);
  printf("\n");
  getch();
}
