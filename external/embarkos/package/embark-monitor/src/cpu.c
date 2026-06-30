#include <stdio.h>

#include "../include/monitor.h"

void monitor_print_cpu(void)
{
    FILE *fp;
    float load1, load5, load15;

    fp = fopen("/proc/loadavg", "r");
    if (fp == NULL)
    {
        printf("Load Average : N/A\n\n");
        return;
    }

    if (fscanf(fp, "%f %f %f", &load1, &load5, &load15) != 3)
    {
        fclose(fp);
        printf("Load Average : N/A\n\n");
        return;
    }

    fclose(fp);

    printf("Load Average : %.2f %.2f %.2f\n\n",
           load1,
           load5,
           load15);
}