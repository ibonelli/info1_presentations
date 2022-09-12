#include "lib.h"

int enviarInvertido (char *fifoName, char *fileName)
{
        FILE *f;

        char c, *buffer=NULL;

        int fifoId;
        int i, sizeBuffer=0;

        if ((f=fopen(fileName, "r"))==NULL)
        {
                exitProgram(fileCantOpen, buffer, f);
        }

        if (mkfifo(fifoName, 0666)<0)
        {
                exitProgram(fifoCantMk, buffer, f);
        }

        if ((fifoId=open(fifoName, O_WRONLY))<0)
        {
                exitProgram(fifoCantOpen, buffer, f);
        }

        fseek(f, 0, SEEK_END);
        sizeBuffer=ftell(f)*sizeof(char);
        buffer=malloc(sizeBuffer);

        fseek(f, 0, SEEK_SET);
        if (fread(buffer, sizeBuffer, 1, f)<0)
        {
                exitProgram(fileCantRead, buffer, f);
        }

        for (i=(sizeBuffer-1); i>=0; i--)
        {
                if((write(fifoId, buffer+i, 1))<0)
                {
                        exitProgram(fifoCantWrite, buffer, f);
                }
        }

        free(buffer);
        fclose(f);
        return finishedOk;
}

void exitProgram(int ret, char *buffer, FILE *f)
{  
        printf("Error: %d.\n", ret);
        switch(ret)
        {
                case -1:
                case -2:
                case -4:
                        fclose(f);
                        exit(ret);
                        break;
                case -3:
                case -5:
                        free(buffer);
                        fclose(f);
                        exit(ret);
                        break;
        }
}
