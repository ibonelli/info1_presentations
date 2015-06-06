#include <stdio.h>
#include <conio.h>

int main()
{
    char input;

    for(;;)
    {
        if(kbhit())
        {
            input = getch();
            printf("%c", input);
        }
    }
}
