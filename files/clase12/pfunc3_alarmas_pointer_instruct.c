/* Seleccion de funciones de alarma usando punteros a funcion  */
/* GCC : gcc -o alarmas ej3_alarmas.c -g -ggdb -Wall               */
// Correr con sudo para tener permisos de monitoreo.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <asm/unistd.h>

static long perf_event_open(struct perf_event_attr *hw_event, pid_t pid,
                int cpu, int group_fd, unsigned long flags) {
    int ret;
    ret = syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd, flags);
    return ret;
}

/*  Prototipos  */
void alarma1( ) {
	printf("Alarma1\n"); }

void alarma2( ) {
	printf("Alarma2\n"); }

void alarma3( ) {
	printf("Alarma3\n"); }

void alarma4( ) {
	printf("Alarma4\n"); }

void alarma5( ) {
	printf("Alarma5\n"); }

void alarma6( ) {
	printf("Alarma6\n"); }

void alarma7( ) {
	printf("Alarma7\n"); }

void alarma8( ) {
	printf("Alarma8\n"); }


int main(void)
{
	int dato;

    struct perf_event_attr pe;
    long long count;
    int fd;

    memset(&pe, 0, sizeof(struct perf_event_attr));
    pe.type = PERF_TYPE_HARDWARE;
    pe.size = sizeof(struct perf_event_attr);
    pe.config = PERF_COUNT_HW_INSTRUCTIONS;
    pe.disabled = 1;
    pe.exclude_kernel = 1;
    pe.exclude_hv = 1;

    fd = perf_event_open(&pe, 0, -1, -1, 0);
    if (fd == -1) {
       fprintf(stderr, "Error opening leader %llx\n", pe.config);
       exit(EXIT_FAILURE);
    }

	while ( 1 ) {
		printf("Ingrese un numero de 0 a 7\tValor: ");
		scanf("%d",&dato);
		ioctl(fd, PERF_EVENT_IOC_RESET, 0);
		ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
		switch(dato) {
			case 0: alarma1(); break;
			case 1: alarma2(); break;
			case 2: alarma3(); break;
			case 3: alarma4(); break;
			case 4: alarma5(); break;
			case 5: alarma6(); break;
			case 6: alarma7(); break;
			case 7: alarma8(); break;
		}
		ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
		read(fd, &count, sizeof(long long));
		printf("Used %lld instructions\n", count);
	    close(fd);
	}
	return 0;
}
