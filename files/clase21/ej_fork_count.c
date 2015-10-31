#include <stdio.h>
#include <unistd.h>

#define pLim 8
#define cLim 5
#define pSleep 1
#define cSleep 1

int main(int argc, char **argv)
{
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
            // En este caso el uso de sleep es didactico
            sleep(pSleep);
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
