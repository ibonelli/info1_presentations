#include<stdio.h>

enum dia_de_la_semana {
    lunes, martes, miercoles, jueves, viernes, 	sabado, domingo
};

enum dia_de_la_semana hoy;

int main(void)
{
    hoy = sabado;
    int dia = (int)sabado;	/* dia = 5 */
    printf("Hoy es %d\n", dia);
    return 0;
}
