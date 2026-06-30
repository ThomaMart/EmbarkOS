#ifndef MONITOR_H
#define MONITOR_H

int monitor_run(void);

void monitor_print_system(void);
void monitor_print_cpu(void);
void monitor_print_memory(void);
void monitor_print_disk(void);
void monitor_print_uptime(void);

#endif