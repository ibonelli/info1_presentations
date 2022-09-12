#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pfds[2];

    pipe(pfds);

    if (!fork()) {
        /* Parent */
        close(1);       /* close normal stdout */
        dup(pfds[1]);   /* make stdout same as pfds[1] */
        close(pfds[0]); /* we don't need this */
        execlp("ls", "dir", "-ls","/dev", NULL);
    } else {
        /* Child */
        close(0);       /* close normal stdin */
        dup(pfds[0]);   /* make stdin same as pfds[0] */
        close(pfds[1]); /* we don't need this */
        execlp("more", "mas", NULL);
    }
}
