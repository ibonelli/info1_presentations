#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int rv;

	switch(pid=fork()) {
		case -1:
			perror("fork");  /* something went wrong */
			exit(1);		 /* parent exits */

		case 0:
			printf(" CHILD: This is the child process!\n");
			printf(" CHILD: My PID is %d\n", getpid());
			printf(" CHILD: My parent's PID is %d\n", getppid());
			printf(" CHILD: Enter my exit status (make it small): ");
			// fflush(stdin) no funciona...
			scanf(" %d", &rv);
			printf(" CHILD: I'm outta here!\n");
			exit(rv);

		default:
			printf("PARENT: This is the parent process!\n");
			printf("PARENT: My PPID is %d\n", getppid());
			printf("PARENT: My PID is %d\n", getpid());
			printf("PARENT: My child's PID is %d\n", pid);
			printf("PARENT: Parent is leaving the building...\n");
	}
}
