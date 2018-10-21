/* sig_talk.c --- Example of how 2 processes can talk */
/* to each other using kill() and signal() */
/* We will fork() 2 process and let the parent send a few */
/* signals to it`s child	*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

/* routines child will call upon sigtrap */
void sighup();
void sigint();
void sigquit();

void main(void)
{ int pid;

	/* get child process */
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}
	if (pid == 0) {
		/* child, set function calls */
		signal(SIGHUP, (__sighandler_t) sighup);
		signal(SIGINT, (__sighandler_t) sigint);
		signal(SIGQUIT, (__sighandler_t) sigquit);
		while(1) {
			/* infinite loop */
			usleep(1000);
		}
	} else {
		/* parent, pid hold id of child */
		printf("\nPARENT: sending SIGHUP\n\n");
		kill(pid,SIGHUP);
		sleep(3); /* pause for 3 secs */
		printf("\nPARENT: sending SIGINT\n\n");
		kill(pid,SIGINT);
		sleep(3); /* pause for 3 secs */
		printf("\nPARENT: sending SIGQUIT\n\n");
		kill(pid,SIGQUIT);
		sleep(3);
	}
}

void sighup() {
	signal(SIGHUP, (__sighandler_t) sighup); /* reset signal */
	printf("CHILD: I have received a SIGHUP\n");
}

void sigint() {
	signal(SIGINT, (__sighandler_t) sigint); /* reset signal */
	printf("CHILD: I have received a SIGINT\n");
}

void sigquit() {
	printf("My DADDY has Killed me!!!\n");
	exit(0);
}
