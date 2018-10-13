#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define pLim 8
#define cLim 5
#define pSleep 1
#define cSleep 1

int main(int argc, char **argv)
{
	char op;
	printf("--beginning of program\n");

	int counter = 0;
	pid_t pid = fork();

	if (pid == 0)
	{
		// child process
		int i = 0;
		for (; i < cLim; ++i)
		{
			printf("Proceso hijo: contador=%d\n", ++counter);
			// En este caso el uso de sleep es didactico
			sleep(cSleep);
		}
	}
	else if (pid > 0)
	{
		// parent process
		int j = 0;
		for (; j < pLim; ++j)
		{
			printf("Proceso padre: contador=%d\n", ++counter);
			printf("Para generar otro proceso presione \"C\", para terminar \"S\"");
			op = (char) getchar();
			if (toupper(op) == 'C') {
			}
			if (toupper(op) == 'S') {
			}
		}
	}
	else
	{
		// fork failed
		printf("fork() failed!\n");
		return 1;
	}

	printf("--end of program--\n");

	return 0;
} 
