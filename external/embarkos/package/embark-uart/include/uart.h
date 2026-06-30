/**
 * @brief Open a UART device.
 *
 * @param device UART device path.
 *
 * @return file descriptor or -1.
 */

#ifndef UART_H
#define UART_H

#include <stddef.h>
#include <sys/types.h>

#define UART_DEFAULT_DEVICE "/dev/ttyUSB0"
#define UART_DEFAULT_BAUD   115200

int uart_open(const char *device);

int uart_configure(int fd, int baudrate);

int uart_wait_data(int fd);

ssize_t uart_read(int fd, char *buffer, size_t size);

ssize_t uart_receive(int fd, char *buffer, size_t size);

ssize_t uart_write(int fd, const char *buffer, size_t size);

void uart_close(int fd);

#endif