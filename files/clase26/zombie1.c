#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int i;
    int pid = fork();
    if (pid==0)
    {
        for (i=0; i<20; i++) {
            usleep(500000);
            printf("I am Child (wait %d)\n", i);
        }
    }
    else
    {
        wait(NULL);
        printf("I am Parent\n");
        while(1) usleep(1000);
    }
}
