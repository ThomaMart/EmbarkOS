#include <stdio.h>
#include <string.h>

#include "../include/monitor.h"

void monitor_print_memory(void)
{
    FILE *fp;
    char key[64];
    unsigned long value;
    char unit[16];

    unsigned long total = 0;
    unsigned long available = 0;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL)
    {
        printf("Memory       : N/A\n\n");
        return;
    }

    while (fscanf(fp, "%63s %lu %15s", key, &value, unit) == 3)
    {
        if (strcmp(key, "MemTotal:") == 0)
            total = value;

        if (strcmp(key, "MemAvailable:") == 0)
            available = value;

        if (total && available)
            break;
    }

    fclose(fp);

    printf("Memory       : %lu / %lu MB\n\n",
           (total - available) / 1024,
           total / 1024);
}