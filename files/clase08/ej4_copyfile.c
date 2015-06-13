/*
 * CopyFile.c
 *
 * Toma por línea de comando un archivo de origen, un archivo de destino,
 * tamaño de bloque de copia, y demora entre bloques.
 *
 * Email : ibonelli@yahoo.com
 *
 */


#define win

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

#ifdef win
  #include <windows.h>
#else
	#include <dos.h>
	#include <stdlib.h>
	#include <malloc.h>
#endif

#define DEBUG 1
#define DOES "Ing. Ignacio Bonelli"
#define VERSION "1.0"
#define COPYRIGHT "GNU (Agunte Linux!!!)"
#define PNAME "copyfile"

char *pname = PNAME;

void usage(char i)
{
   char *msg[4];
   msg[0]=DOES;
   msg[1]=VERSION;
   msg[2]=COPYRIGHT;
   msg[3]=PNAME;

   printf("Autor=%s Versión=%s\nCopyright=%s\n\n",DOES,VERSION,COPYRIGHT);
   printf("Usage: %s [ArchOrg] [ArchDest] [SizeBlockMB] [DelaySeg]\n\n",PNAME);
   printf("      ArchOrg: Nombre y ruta del archivo de origen\n");
   printf("      ArchDest: Nombre y ruta del archivo de destino\n");
   printf("      SizeBlockMB: Tamaño de los bloques a copiar en MBytes\n");
   printf("      DelaySeg: Demora entre bloques en segundos\n\n",PNAME);

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

void chk_syntax(int argc, char **argv)
{
   char *p;
   if (argc < 5)
      usage(1);
}

#ifdef win
  void demora(int segundos)
  {
    int i;
      for(i=0;i<segundos;i++) {
        Sleep(1000);
        if(DEBUG) printf("%d",i);
        }
  }
#else
  // DOS
  void demora(int segundos)
  {
    int i;
    for(i=0;i<segundos;i++) {
      delay(1000);
      if(DEBUG) printf("%d",i);
      }
  }
// falta unix que usa otra libreria
// De "unistd.h" la lib usleep()
//         man 3 usleep
#endif

int main(int argc, char **argv)
{
FILE *fpr,*fpw;
int i,size,time,Loops;
long n, FileSize;
char *str;

#ifndef win
  float div;
#endif

char str[262144];  // String de 256kB, 256*1024
                   // originalmente malloc() cambiado para ejemplo
                   //     str=(char *)malloc(262144);

chk_syntax(argc,argv);
fpr=fopen(argv[1],"r");
fpw=fopen(argv[2],"w");
if(!fpr) {
    printf("Error de apertura del archivo de entrada\n\n");
    exit(0);
    }
if(!fpw) {
    printf("Error de apertura del archivo de salida\n\n");
    exit(0);
    }
size = get_num(argv[3]);
time = get_num(argv[4]);

printf("Avance");
fseek(fpr,0,SEEK_END);
FileSize=ftell(fpr);
fseek(fpr,0,SEEK_SET);

/* Loops: Amount of 1MByte blocks to copy */
#ifdef win
  Loops=floor(FileSize/(256*1024));
#else
  div=FileSize/256;
  Loops=floor(div/1024);
#endif
if(DEBUG) printf("Loops:%d",Loops);

/* Copying size*1Mbyte blocks */
while(Loops){
  if(DEBUG) printf("\n");
  for(i=0;i<size;i++) {
    fread(str,sizeof(char)*256,1024,fpr);
    if(DEBUG) printf("ftell:%d\n",ftell(fpr));
    fwrite(str,sizeof(char)*256,1024,fpw);
    Loops--;
    }
  printf("."); demora(time);
  }

/* Last part (less than 1MByte) */
if(DEBUG) printf("\n");
if(DEBUG) printf("ftell:%d - FileSize:%d\n",ftell(fpr),FileSize);
do {
  n=fread(str,sizeof(char),256,fpr);
  if(DEBUG) printf("ftell:%d\n",ftell(fpr));
  fwrite(str,sizeof(char),n,fpw);
  if(DEBUG) printf("Last write n:%d\n",n);
  }while(!feof(fpr));

/* Final Delay (for use in batchs) */
demora(time);

fclose(fpr);
fclose(fpw);

return 0;
}
