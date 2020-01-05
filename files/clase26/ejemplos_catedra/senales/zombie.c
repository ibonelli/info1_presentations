#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void){

	pid_t p;
	int i;

	p=fork();
	if (!p) {
	/*proceso child.*/
		printf("\nproceso hijo\n\n");
	/*Dormirá 10 segundos y terminará, saliendo del if y ejecutando return (0).En estas condiciones quedará en estado zombie, si el padre no terminó primero */
		sleep(10);
	}else{
		printf("\nProceso padre\n\n");
		for (i=0;i<50;i++){
	/*El padre hace una demora de 50 segundos presentando en pantalla el contador y luego termina. Durante los últimos 40 segundos el child estará zombie.*/
			sleep(1);
			printf("..%d\n",i);
		}
	}
	return 0;
}
