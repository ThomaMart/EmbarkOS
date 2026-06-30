#include <stdio.h>

#include "../include/logger.h"

FILE *logger_open(const char *filename)
{
    if (filename == NULL)
        return NULL;

    return fopen(filename, "a");
}

void logger_write(FILE *fp, const char *buffer)
{
    if (!fp)
        return;

    fputs(buffer, fp);
    fflush(fp);
}

void logger_close(FILE *fp)
{
    if (fp)
        fclose(fp);
}