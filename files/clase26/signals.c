#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void sigproc(void);
void quitproc(void);

int flag=1;

int main(void) {
	signal(SIGINT, (__sighandler_t) sigproc);
	signal(SIGQUIT, (__sighandler_t) quitproc);
	printf("Process ID: %d\n", getpid());
	printf("ctrl-c disabled use ctrl-\\ to quit\n");
	while(flag) {
		/* infinite loop */
		usleep(1000);
	}
	printf("Volvimos a main, termino el while y me cierro...\n");
	return 0;
}

void sigproc() {
	signal(SIGINT, (__sighandler_t) sigproc);
	/* NOTE some versions of UNIX will reset signal to default
	after each call. So for portability reset signal each time */

	printf("you have pressed ctrl-c \n");
}

void quitproc() {
	printf("ctrl-\\ pressed to quit\n");
	flag=0; /* normal exit status */
}
