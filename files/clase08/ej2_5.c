#include <stdio.h>

int main(int argc, char *argv[])
{
    if ( argc != 2 ) /* argc debe ser 2 para trabajar correctamente */
    {
        /* Imprimiremos argv[0] que es el nombre del programa */
        printf( "Uso: %s nombre_archivo\n", argv[0] );
    }
    else 
    {
        // argv[1] va a ser el archivo a abrir
        FILE *file = fopen( argv[1], "r" );

        /* fopen retorna 0 (puntero NULL) si hay error */
        if ( file == 0 )
        {
            printf( "No se pudo abrir el archivo\n" );
        }
        else 
        {
            int x;
            /* Lee un caracter en cada pasada desde el archivo terminando
             * cuando encuentra EOF.
             */
            while  ( ( x = fgetc( file ) ) != EOF )
            {
                printf( "%c", x );
            }
            fclose( file );
        }
    }
}
