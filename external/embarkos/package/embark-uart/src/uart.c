#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <termios.h>
#include <sys/select.h>
#include <sys/time.h>

#include "../include/uart.h"
#include <unistd.h>

static speed_t uart_get_speed(int baudrate)
{
    switch (baudrate)
    {
        case 9600:
            return B9600;

        case 19200:
            return B19200;

        case 38400:
            return B38400;

        case 57600:
            return B57600;

        case 115200:
            return B115200;

        default:
            return B115200;
    }
}

int uart_configure(int fd, int baudrate)
{
    struct termios tty;
    speed_t speed = uart_get_speed(baudrate);

    if (tcgetattr(fd, &tty) != 0)
    {
        perror("tcgetattr");
        return -1;
    }

    cfsetispeed(&tty, speed);
    cfsetospeed(&tty, speed);

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

    printf("UART configured: %d 8N1\n", baudrate);

    return 0;
}

ssize_t uart_read(int fd, char *buffer, size_t size)
{
    return read(fd, buffer, size);
}

ssize_t uart_receive(int fd, char *buffer, size_t size)
{
    int ret;

    ret = uart_wait_data(fd);

    if (ret <= 0)
        return ret;

    return uart_read(fd, buffer, size);
}

ssize_t uart_write(int fd, const char *buffer, size_t size)
{
    return write(fd, buffer, size);
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

int uart_wait_data(int fd)
{
    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    return select(fd + 1, &readfds, NULL, NULL, &timeout);
}

void uart_close(int fd)
{
    if (fd >= 0)
    {
        close(fd);
        printf("UART closed.\n");
    }
}