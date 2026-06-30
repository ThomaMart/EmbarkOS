#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <time.h>

#include "../include/timestamp.h"

static struct timespec start;

void timestamp_init(void)
{
    clock_gettime(CLOCK_MONOTONIC, &start);
}

void timestamp_print(void)
{
    struct timespec now;

    clock_gettime(CLOCK_MONOTONIC, &now);

    long sec = now.tv_sec - start.tv_sec;
    long nsec = now.tv_nsec - start.tv_nsec;

    if (nsec < 0)
    {
        sec--;
        nsec += 1000000000L;
    }

    printf("[%02ld:%02ld.%03ld] ",
           sec / 60,
           sec % 60,
           nsec / 1000000);
}