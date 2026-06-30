#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/cli.h"
#include "../include/uart.h"

int cli_parse(int argc, char *argv[], struct uart_options *opts)
{
    opts->device = UART_DEFAULT_DEVICE;
    opts->baudrate = UART_DEFAULT_BAUD;

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "--device") && i + 1 < argc)
        {
            opts->device = argv[++i];
        }
        else if (!strcmp(argv[i], "--baud") && i + 1 < argc)
        {
            opts->baudrate = atoi(argv[++i]);
        }
    }

    if (opts->baudrate != 9600 &&
    opts->baudrate != 19200 &&
    opts->baudrate != 38400 &&
    opts->baudrate != 57600 &&
    opts->baudrate != 115200)
    {
        fprintf(stderr, "Unsupported baudrate: %d\n", opts->baudrate);
        return -1;
    }

    return 0;

}