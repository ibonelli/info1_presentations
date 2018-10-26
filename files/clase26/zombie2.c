#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	int i;
	int pid = fork();
	if (pid==0) {
		for (i=0; i<10; i++) {
			usleep(500000);
			printf("I am Child (wait %d)\n", i);
		}
	} else {
		printf("Parent waiting...\n");
		wait(NULL);
		printf("I am the Parent and my child finished!\n");
		while(1) usleep(1000);
	}
}
