#include <stdio.h>
#include <sys/statvfs.h>

#include "../include/monitor.h"

void monitor_print_disk(void)
{
    struct statvfs fs;

    if (statvfs("/", &fs) != 0)
    {
        printf("Disk Usage   : N/A\n\n");
        return;
    }

    unsigned long total =
        (fs.f_blocks * fs.f_frsize) / (1024 * 1024);

    unsigned long available =
        (fs.f_bavail * fs.f_frsize) / (1024 * 1024);

    unsigned long used = total - available;

    printf("Disk Usage   : %lu / %lu MB\n\n",
           used,
           total);
}