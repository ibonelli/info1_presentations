/*
 * Ejercicio de enumeraciones:
 * Construir un programa que muestre un menú y e indique la opción
 * seleccionada, empleando una enumeración y una lista de cadenas.
 * 
 * De: http://maxus.fis.usal.es/FICHAS_C.WEB/02xx_PAGS/0201.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define NUM_OPCIONES 5

int main(void)
{
  enum {Nuevo, Abrir, Guardar, Cerrar, Salir};

  char menu[][10] = {"  Nuevo", "  Abrir", "Guardar", " Cerrar", "  Salir"};
  char opcion;
  int i, caso;

  system("clear");

  do {
    /* Visualizar menú y leer la opción */
    printf("\nSeleccione una opción:\n");
    for(i=0;i<NUM_OPCIONES;i++)
      printf("%s (%d)\n", menu[i], i);
    printf(" : ");
    scanf("%c", &opcion);
    __fpurge(stdin);
    
    /* Mostrar en pantalla la opción seleccionada */
    caso = opcion - '0';
    switch(caso) {
      case Nuevo:  printf("\nSe ha seleccionado la opción: \"%s\"\n", menu[caso]);
          break;
      case Abrir:  printf("\nSe ha seleccionado la opción: \"%s\"\n", menu[caso]);
          break;
      case Guardar: printf("\nSe ha seleccionado la opción: \"%s\"\n", menu[caso]);
          break;
      case Cerrar: printf("\nSe ha seleccionado la opción: \"%s\"\n", menu[caso]);
          break;
      case Salir:  printf("\nSe ha seleccionado la opción: \"%s\"\n", menu[caso]);
          break;
      default:  printf("\n\nOpción incorrecta\n\n");
          break;
    }
  }
  while(caso != Salir);

  printf("\n\nFin del programa\n\n");
  return 0;
}
