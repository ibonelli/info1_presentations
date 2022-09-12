#include <stdio.h>
#include <string.h>

int main()
{
   FILE *fp;
   char str[60];
   int aux, i=1;

   fp = fopen("miarch.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }

   while(fgets(str, 60, fp)!=NULL) {
      printf("%02d - ", i);
      str[strlen(str)-1]=0;
      puts(str);
      i++;
   }

   fclose(fp);
   return(0);
}
