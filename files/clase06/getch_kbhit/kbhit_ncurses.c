/* Below you can see an ncurses.h version of dos/win conio.h  */
/* GCC : gcc -o test kbhit_ncurses.c -lncurses -g -ggdb -Wall */

#include <stdio.h>
#include <ncurses.h>

int main(void)
{
    char input;

    initscr(); // entering ncurses mode
    raw();     // CTRL-C and others do not generate signals
    noecho();  // pressed symbols wont be printed to screen
    cbreak();  // disable line buffering
    while (1) {
        erase();
        mvprintw(1,0, "Enter symbol, please");
        input = getch();
        mvprintw(2,0, "You have entered %c", input);
        getch(); // press any key to continue
    }
    endwin(); // leaving ncurses mode    

    return 0;
}
