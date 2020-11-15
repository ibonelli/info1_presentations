#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define finishedOk 0
#define fifoCantMk -1
#define fifoCantOpen -2
#define fifoCantWrite -3
#define fileCantOpen -4
#define fileCantRead -5

int enviarInvertido (char *, char *);
void exitProgram(int, char *, FILE *);
