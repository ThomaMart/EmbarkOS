#include <stdio.h>
#include <signal.h>

#include "../include/uart.h"
#include "../include/cli.h"

static volatile sig_atomic_t running = 1;

static void signal_handler(int sig)
{
    (void)sig;
    running = 0;
}

int main(int argc, char *argv[])
{
    int fd;
    char buffer[256];
    struct uart_options opts;

    signal(SIGINT, signal_handler);

    if (cli_parse(argc, argv, &opts) != 0)
        return 1;

    if (opts.show_help)
    {
        cli_print_help();
        return 0;
    }

    if (opts.show_version)
    {
        cli_print_version();
        return 0;
    }

    if (opts.list_baud)
    {
        cli_print_baudrates();
        return 0;
    }

    printf("=========================================\n");
    printf("        Embark UART Monitor\n");
    printf("=========================================\n\n");

    printf("Device : %s\n", opts.device);
    printf("Baud   : %d\n\n", opts.baudrate);

    fd = uart_open(opts.device);

    if (fd < 0)
        return 1;

    if (uart_configure(fd, opts.baudrate) != 0)
    {
        uart_close(fd);
        return 1;
    }

    while (running)
    {
        int ret = uart_wait_data(fd);

        if (ret < 0)
            break;

        if (ret == 0)
            continue;

        ssize_t bytes = uart_read(fd, buffer, sizeof(buffer) - 1);

        if (bytes > 0)
        {
            buffer[bytes] = '\0';
            printf("%s", buffer);
            fflush(stdout);
        }
    }

    uart_close(fd);

    return 0;
}