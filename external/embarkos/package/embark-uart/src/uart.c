#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "../include/uart.h"

int uart_configure(int fd, int baudrate)
{
    (void)fd;
    (void)baudrate;

    return 0;
}

int uart_read(int fd, char *buffer, int size)
{
    (void)fd;
    (void)buffer;
    (void)size;

    return 0;
}

int uart_open(const char *device)
{
    int fd;

    printf("Opening %s...\n", device);

    fd = open(device, O_RDWR | O_NOCTTY);

    if (fd == -1)
    {
        printf("Failed to open UART\n");
        printf("Reason : %s\n", strerror(errno));
        return -1;
    }

    printf("UART opened successfully.\n");

    return fd;
}

void uart_close(int fd)
{
    if (fd >= 0)
    {
        close(fd);
        printf("UART closed.\n");
    }
}