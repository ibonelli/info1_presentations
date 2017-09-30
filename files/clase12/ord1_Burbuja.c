#include <stdio.h>
#include "getch.h"

void main(void) {
  void burbuja(char [],int);
  char vec[10]={'G','B','E','A','L','Z','R','T','P','K'};
  int i;
  clrscr();
  printf("Vector desordenado\n");
  for(i=0;i<10;i++)
    printf("    %c",vec[i]);
  printf("\n\n");
  burbuja(vec,10);
  printf("\n\n");
  printf("Vector ordenado\n");
  for(i=0;i<10;i++)
    printf("    %c",vec[i]);
  printf("\n\n\n\n\n\n");
  getch();
}

void burbuja(char vec[],int N) {
  int i,j;
  char aux;
  for(i=0;i<N-1;i++) {
    for(j=0;j<N-i-1;j++) {
      if(vec[j]>vec[j+1]) {
        aux=vec[j];
        vec[j]=vec[j+1];
        vec[j+1]=aux;
      }
      muestra(vec,N);
    }
  printf("\n\n\nFin pasada %d\n\n",i);
  }
}

void muestra(char vec[], int N) {
  int i;
  printf("\n\n");
  for(i=0;i<N;i++)
    printf("    %c",vec[i]);
  getch();
}
