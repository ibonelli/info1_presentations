#include <stdio.h>

int main(void)
{
   int ch = 0;

   printf("Input a string:");
   while ((ch != 'x'))
   {
      ch = getchar();
      putchar(ch);
   }
   return 0;
}
