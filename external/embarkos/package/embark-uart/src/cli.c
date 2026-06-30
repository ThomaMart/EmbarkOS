#include <string.h>
#include <stdlib.h>

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

    return 0;
}