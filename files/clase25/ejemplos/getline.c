/*
 * getline.c
 *
 * Toma de la línea de comando el número de linea de un archivo de
 * texto o un rango de lineas y el nombre del archivo del cuál
 * estraerlas y luego las devuelve por stdout.
 *
 * Email : ibonelli@uole.com
 *
 */

#include <stdio.h>
#include <ctype.h>

#define DEBUG 0
#define DOES "Ing. Ignacio Bonelli"
#define VERSION "1.0"
#define COPYRIGHT "GNU (Agunte Linux!!!)"
#define PNAME "getline"

int valid = 0;          /* true if lpt exists and has H/W */

char *pname = PNAME;
int ini,range;         /* Guarda en ini la primer linea y si rango=0 es una sola linea
                           si rango es un número es la linea final a tomar */

void usage(char i)
{
   char *msg[4];
   msg[0]=DOES;
   msg[1]=VERSION;
   msg[2]=COPYRIGHT;
   msg[3]=PNAME;

   printf("Autor=%s Versión=%s\nCopyright=%s\n\n",DOES,VERSION,COPYRIGHT);
   printf("Usage: %s linea/s Archivo\n\n",PNAME);
   printf("      Si desea extraer por ejemplo la linea 5 del archivo\n");
   printf("      de texto con el nombre mrtg.log debe escribir:\n\n");
   printf("            %s 5 mrtg.log\n\n",PNAME);
   printf("      Si desea extraer un rango de lineas como por ejemplo\n");
   printf("      de la linea 7 a la 10 debe escribir:\n\n");
   printf("            %s 7-10 mrtg.log\n\n",PNAME);

   if(DEBUG) printf("\nPunto del Trace: %d\n\n",i);

   exit(0);
}

int get_num(char *str)
{
   char aux[10];
   int i=0;

   while(isalnum((int)*(str+i))) {
      aux[i]=*(str+i); i++;
      }
   aux[i]=0;
   i=atoi(aux);

   if(DEBUG) printf("Num:%d\n",i);
   
   return i;
}

void chk_sintax(int argc, char **argv)
{
   char *p;
   if (argc < 3)
      usage(1);
   p=argv[1];
   if ( isalnum((int)*p) ) {
      while( isalnum( (int)*p) ) p++;
      if( *p == '-' ) {
         p++;
         if ( isalnum((int)*p) ) {
            while( isalnum( (int)*p) ) p++;
            if( *p != 0 ) usage(2);
            }
         else usage(3);
         }
      else if( *p != 0 ) usage(4);
      }
   else usage(5);
}

void get_option(char **argv)
{
   char *p;
   p=argv[1];
   
   ini=get_num(p);
   while( isalnum( (int)*p) ) p++;
   if( *p != '-' ) range=-1;
   else {
        p++;
        range=get_num(p);
        }
}

int main(int argc, char **argv)
{
    FILE *fp;
    int i=1;
    char str[1024];

    chk_sintax(argc,argv);
    get_option(argv);
    if(range!=-1) { if(ini>range) usage(6); }
    fp=fopen(argv[2],"r");
    if(!fp)
        {
        printf("Error de apertura de archivo\n\n");
        exit(0);
        }
    while(!feof(fp))
      {
      fgets(str,1023,fp);
      if(!feof(fp)) {
        if(ini==i)
	  printf("%s",str);
        else
    	  if(range!=0 && range!=-1)
            if( (i>ini) && (i<=range) )
        	printf("%s",str);
	}
      i++;
      }
    fclose(fp);
    exit(0);
}

