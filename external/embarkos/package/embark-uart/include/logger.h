#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

FILE *logger_open(const char *filename);

void logger_write(FILE *fp, const char *buffer);

void logger_close(FILE *fp);

#endif