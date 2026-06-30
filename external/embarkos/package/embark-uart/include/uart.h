#ifndef UART_H
#define UART_H

#include <stddef.h>
#include <sys/types.h>

#define UART_DEFAULT_DEVICE "/dev/ttyUSB0"
#define UART_DEFAULT_BAUD   115200

int uart_open(const char *device);

int uart_configure(int fd, int baudrate);

ssize_t uart_read(int fd, char *buffer, size_t size);

int uart_wait_data(int fd);

void uart_close(int fd);

#endif