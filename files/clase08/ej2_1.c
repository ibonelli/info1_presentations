#include <stdio.h>

int main()
{
   FILE *fp;
   char str[60];

   /* abriendo el archivo para lectura */
   fp = fopen("file.txt" , "r");

   if(fp == NULL) 
   {
      perror("Error opening file");
      return(-1);
   }

   if( fgets (str, 60, fp)!=NULL ) 
   {
      /* escribiendo el contenido en stdout */
      puts(str);
   }

   fclose(fp);
   return(0);
}
