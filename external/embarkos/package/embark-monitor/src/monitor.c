#include <stdio.h>

#include "../include/monitor.h"

int monitor_run(void)
{
    printf("=========================================\n");
    printf("        Embark System Monitor\n");
    printf("=========================================\n\n");

    monitor_print_system();
    monitor_print_cpu();
    monitor_print_memory();
    monitor_print_disk();
    monitor_print_uptime();

    return 0;
}