#include <stdio.h>

#include "../include/monitor.h"

void monitor_print_uptime(void)
{
    FILE *fp;
    double uptime;

    fp = fopen("/proc/uptime", "r");
    if (fp == NULL)
    {
        printf("Uptime       : N/A\n");
        return;
    }

    if (fscanf(fp, "%lf", &uptime) != 1)
    {
        fclose(fp);
        printf("Uptime       : N/A\n");
        return;
    }

    fclose(fp);

    unsigned long seconds = (unsigned long)uptime;

    unsigned int days = seconds / 86400;
    seconds %= 86400;

    unsigned int hours = seconds / 3600;
    seconds %= 3600;

    unsigned int minutes = seconds / 60;
    seconds %= 60;

    if (days > 0)
    {
        printf("Uptime       : %ud %02u:%02u:%02lu\n",
               days,
               hours,
               minutes,
               seconds);
    }
    else
    {
        printf("Uptime       : %02u:%02u:%02lu\n",
               hours,
               minutes,
               seconds);
    }
}