#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>

#include "../include/monitor.h"

void monitor_print_system(void)
{
    struct utsname info;
    char hostname[256] = "unknown";

    uname(&info);
    gethostname(hostname, sizeof(hostname));

    printf("Hostname     : %s\n", hostname);
    printf("Kernel       : %s\n", info.release);
    printf("Architecture : %s\n\n", info.machine);
}