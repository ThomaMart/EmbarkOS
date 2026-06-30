#include <stdio.h>

#include "../include/uart.h"

int main(void)
{
    int fd;

    printf("=========================================\n");
    printf("        Embark UART Monitor\n");
    printf("=========================================\n\n");

    printf("Device : %s\n", UART_DEFAULT_DEVICE);
    printf("Baud   : %d\n\n", UART_DEFAULT_BAUD);

    fd = uart_open(UART_DEFAULT_DEVICE);

    if (uart_configure(fd, UART_DEFAULT_BAUD) != 0)
    {
        uart_close(fd);
        return 1;
    }

    if (fd < 0)
        return 1;

    uart_close(fd);

    return 0;
}
