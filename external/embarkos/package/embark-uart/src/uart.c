#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <termios.h>

#include "../include/uart.h"
#include <unistd.h>



int uart_configure(int fd, int baudrate)
{
    struct termios tty;

    (void)baudrate;

    if (tcgetattr(fd, &tty) != 0)
    {
        perror("tcgetattr");
        return -1;
    }

    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag |= CREAD;
    tty.c_cflag |= CLOCAL;

    tty.c_iflag = 0;
    tty.c_oflag = 0;
    tty.c_lflag = 0;

    if (tcsetattr(fd, TCSANOW, &tty) != 0)
    {
        perror("tcsetattr");
        return -1;
    }

    printf("UART configured: 115200 8N1\n");

    return 0;
}

ssize_t uart_read(int fd, char *buffer, size_t size)
{
    return read(fd, buffer, size);
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