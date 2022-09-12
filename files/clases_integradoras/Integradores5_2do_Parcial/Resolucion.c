#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FIFO_NAME "fifo_stock"

typedef struct producto{
    int codigo;
    char descripcion[20];
    int stock;
} Producto;



/*
Desarrollar una función que permita la carga de productos en un arreglo dinámico.
La función recibe la información de un producto y lo carga dentro del arreglo,
retornando la cantidad total de elementos del arreglo.
Si coincide el código de producto con un código existente, se deberá actualizar el stock disponible,
manteniendo la descripción y el código sin modificación.

En caso de error, la función devuelve (-1) y debe garantizar la liberación de los recursos utilizados hasta ese
momento. En caso de éxito, retorna la cantidad total de elementos del arreglo.
*/
int CargarProducto (Producto **puntero_a_listado,
                    int cantidad,
                    int codigo,
                    char *descripcion,
                    int stock)
{
    int i;
    Producto *listado, *aux;

    listado = *puntero_a_listado;
    //verificar si el producto existe en el arreglo
    for(i=0; i<cantidad; i++){
        if( listado[i].codigo == codigo ){
            //existe -> actualizar stock
            listado[i].stock = stock;
            return cantidad;
        }
    }
    //pedir memoria
    aux = (Producto*) realloc(listado, sizeof(Producto)*(cantidad+1) );
    if(aux==NULL){
        return -1; //si falla retornar -1
    }
    listado = aux;
    *puntero_a_listado = listado;
    cantidad++;

    //cargar producto
    listado[cantidad-1].codigo = codigo;
    strcpy(listado[cantidad-1].descripcion, descripcion);
    listado[cantidad-1].stock = stock;

    //retornar cantidad de elementos del arreglo
    return cantidad;
}

/*
Desarrollar una función que a partir de un arreglo del tipo Producto, actualice un archivo, escribiendo al final
del mismo, los datos correspondientes a un código específico utilizando el siguiente formato:
Codigo,Descripcion,Stock\n
La función devuelve:
0 en caso de éxito
-1 si no pudo crear / abrir el archivo
-2 si el arreglo se encuentra vacío
-3 si el código recibido no se encuentra en el arreglo
*/
int EscribirInformacion(Producto *listado, int cantidad, int codigo, char* nombreArchivo)
{
    int i;
    FILE *fd;

    //si el arreglo está vacio
    if(cantidad==0){
        return -2;
    }

    //verificar si el producto existe en el arreglo
    for(i=0; i<cantidad; i++){
        if( listado[i].codigo == codigo ){
            //existe -> imprimir a archivo

            fd = fopen(nombreArchivo, "a");
            if(fd==NULL){
                return -1;
            }

            fprintf(fd, "%d,%s,%d\n", listado[i].codigo, listado[i].descripcion, listado[i].stock);
            return 0;
        }
    }

    //si el producto no existe en el arreglo
    return -3;
}

/*
int main(void){

    Producto *listado;
    int cantidad=0;

    //Cargar stock
    cantidad = CargarProducto(&listado,cantidad,1234,"Bananas",100);
    cantidad = CargarProducto(&listado,cantidad,6747,"Peras",50);
    cantidad = CargarProducto(&listado,cantidad,4774,"Mangos",3);

    //Actualizar stock de bananas a 85
    cantidad = CargarProducto(&listado,cantidad,1234,"",85);


    return 0;
}
*/

/*
3) Desarrollar un programa que permita validar el funcionamiento de los módulos (1 y 2) previamente
desarrollados.
El programa recibe por línea de comando la siguiente información:
./programa archivoSalida codigoAFiltrar
El proceso padre cargará los datos utilizando la función del punto (1) y finalizará la carga cuando el código sea 0. En
caso de error en la función de carga, se notificará al usuario y finalizará el programa. El proceso de carga se realiza
por parte del usuario mediante el teclado.
A continuación, el proceso padre será el encargado de pasarle a un proceso hijo (mediante IPC y no otro mecanismo)
el nombre del archivo a generar. El proceso hijo invocará a la función del punto (2). Luego, el proceso hijo le
notificará al padre el resultado de la operación y el padre informará al usuario si hubo error o se generó el archivo
correctamente.
Procure realizar todas las validaciones y liberaciones de recursos.
*/

int main(int argc, char **argv) {
    Producto *listado;
    int cantidad=0;
	int aux, codigo, stock;
    char descripcion[20];
    pid_t pid;
    int fd, num;

    if(argc!=3){
        printf("uso: $./programa archivoSalida codigoAFiltrar\n");
        return 0;
    }

    printf("Codigo: ");
    scanf("%d",&codigo);

    while(codigo != 0){
        printf("Descripción: ");
        scanf("%s",descripcion);
        printf("Stock: ");
        scanf("%d",&stock);

        aux = CargarProducto(&listado, cantidad, codigo, descripcion, stock);
        if(aux == -1){
            printf("No se pudo realizar realloc\n");
            return 0;
        }
        cantidad = aux;

        printf("Codigo: ");
        scanf("%d",&codigo);
    } 


	switch(pid=fork()) {
		case -1:
			perror("fork");  /* something went wrong */
			exit(1);		 /* parent exits */

		case 0:
            //Child

            if ((fd=mkfifo (FIFO_NAME, 0666))<0)
                fprintf (stderr, "Error creando la FIFO %s. CÃŗdigo de error %s\n",FIFO_NAME,strerror(fd));

	        fd = open(FIFO_NAME, O_WRONLY);
            if(fd==0){
                printf("Error abriendo fifo escritura");
                return 0;
            }

            aux=EscribirInformacion(listado,cantidad, atoi(argv[2]), argv[1]);

            if( (num = write(fd, &aux, sizeof(int) )) == -1 )
                fprintf (stderr, "Error escribiendo en la FIFO %s. CÃŗdigo de error %s\n", FIFO_NAME, strerror(num));

	        close(fd);

	        remove(FIFO_NAME);
	        return 0;

		default:
            //Parent

            if ((fd=mkfifo (FIFO_NAME, 0666))<0)
		        fprintf (stderr, "Error creando la FIFO %s. Codigo de error %s\n",FIFO_NAME,strerror(fd));
            
            fd = open(FIFO_NAME, O_RDONLY);
            if(fd==0){
                printf("Error abriendo fifo lectura");
                return 0;
            }

            num = read(fd, &aux, sizeof(int));
            if(num != sizeof(int)){
                printf("Error leyendo fifo");
                return 0;
            }

            switch(aux){
                case 0:
                    printf("Dato guardado");
                    break;
                case -1:
                    printf("Problemas con el archivo");
                    break;
                case -2:
                    printf("Arreglo vacío");
                    break;
                case -3:
                    printf("Código de producto inexistente");
                    break;
                default:
                    printf("No debería haber llegado acá... Problema en EscribirInformacion()");
            }
            return 0;
	}

    return 0;
}