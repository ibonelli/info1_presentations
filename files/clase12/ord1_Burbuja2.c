#include <stdio.h>
#include "getch.h"

void muestra(char vec[], int N) {
  int i;
  printf("\n\n");
  for(i=0;i<N;i++)
    printf("    %c",vec[i]);
  getch();
}

void burbuja(char vec[],int N) {
  int i,j;
  char flag=1;
  char aux;
  for(i=0;(i<N-1)&&flag;i++) {
	flag=0;
    for(j=0;j<N-i-1;j++) {
      if(vec[j]>vec[j+1]) {
        aux=vec[j];
        vec[j]=vec[j+1];
        vec[j+1]=aux;
		flag=1;
      }
      muestra(vec,N);
    }
  printf("\n\n\nFin pasada %d\n\n",i);
  }
}

void main(void) {
  char vec[10]={'A','B','E','G','K','L','P','R','T','Z'};
  //char vec[10]={'G','B','E','A','L','Z','R','T','P','K'};
  int i;
  //clrscr();
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
