#include <string.h>
#include <stdio.h>

int main(void)
{
   char destination[25];
   char *espacio = " ", *s1 = "Curso", *s2 = "Informatica 1";

   strcpy(destination, s1);
   strcat(destination, blank);
   strcat(destination, s2);

   printf("%s\n", destination);
   return 0;
}
