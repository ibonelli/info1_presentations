#include <stdio.h>
#include <stdlib.h>
#define CANT 7

int values[] = { 88, 56, 25, 45, 100, 2, 15 };

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
   int n;

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < CANT; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, CANT, sizeof(int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < CANT; n++ ) {   
      printf("%d ", values[n]);
   }
  
   return(0);
}
