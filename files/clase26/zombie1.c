#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	int i;
	int pid = fork();
	if (pid==0) {
		for (i=0; i<5; i++) {
			usleep(500000);
			printf("I am Child and finished!\n");
		}
	} else {
		printf("Impatian parent does not wait.\n");
		while(1) usleep(1000);
	}
}
