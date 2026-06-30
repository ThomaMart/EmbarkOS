#ifndef UART_H
#define UART_H

#define UART_DEFAULT_DEVICE "/dev/ttyUSB0"
#define UART_DEFAULT_BAUD   115200

int uart_open(const char *device);

int uart_configure(int fd, int baudrate);

int uart_read(int fd, char *buffer, int size);

void uart_close(int fd);

#endif