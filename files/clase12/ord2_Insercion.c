#include <stdio.h>
#include "getch.h"

void muestra(char vec[], int N) {
  int i;
  printf("\n\n");
  for(i=0;i<N;i++)
    printf("    %c",vec[i]);
  getch();
}

void insercion(char vec[],int N) {
  int i,j;
  char aux;
  for(i=1;i<N;i++) {
    aux=vec[i];
    for(j=i-1;j>=0 && aux<vec[j];j--) {
      vec[j+1]=vec[j];
      muestra(vec,N);
    }
    vec[j+1]=aux;
    printf("\nRealizo corrimiento\n");
    muestra(vec,N);
  }
}

void main(void) {
  void insercion(char [],int);
  char vec[10]={'G','B','E','A','L','Z','R','T','P','K'};
  int i;
  printf("Vector desordenado\n");
  for(i=0;i<10;i++)
    printf("    %c",vec[i]);
  printf("\n\n");
  insercion(vec,10);
  printf("\n\n\nVector ordenado\n");
  for(i=0;i<10;i++)
    printf("    %c",vec[i]);
  getch();
}
