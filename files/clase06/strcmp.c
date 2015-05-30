#include <string.h>
#include <stdio.h>

int main(void) {
   char *buf1 = "aaa", *buf2 = "bbb", *buf3 = "ccc";
   int ptr;

   ptr = strcmp(buf2, buf1);
   if (ptr > 0)
      printf("buffer 2 es mayor que buffer 1\n");
   else
      printf("buffer 2 es menor que buffer 1\n");

   ptr = strcmp(buf2, buf3);
   if (ptr > 0)
      printf("buffer 2 es mayor que buffer 3\n");
   else
      printf("buffer 2 es menor que buffer 3\n");

   return 0;
}
