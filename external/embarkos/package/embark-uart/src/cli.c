#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cli.h"
#include "../include/uart.h"

void cli_print_help(void)
{
    printf("Embark UART Monitor\n\n");

    printf("Usage:\n");
    printf("  embark-uart [OPTIONS]\n\n");

    printf("Options:\n");
    printf("  --device <device>    UART device\n");
    printf("  --baud <baudrate>    UART baudrate\n");
    printf("  --log <file>         Save UART output\n");
    printf("  --timestamp          Display timestamps\n");
    printf("  --send <text>        Send text after opening UART\n");
    printf("  --list-baud          List supported baudrates\n");
    printf("  --version            Show version\n");
    printf("  --help               Show help\n");
}

void cli_print_version(void)
{
    printf("Embark UART v0.2.0\n");
}

void cli_print_baudrates(void)
{
    printf("Supported baudrates:\n");
    printf(" 9600\n");
    printf("19200\n");
    printf("38400\n");
    printf("57600\n");
    printf("115200\n");
}

int cli_parse(int argc, char *argv[], struct uart_options *opts)
{
    opts->device = UART_DEFAULT_DEVICE;
    opts->baudrate = UART_DEFAULT_BAUD;
    opts->log_file = NULL;
    opts->send = NULL;
    opts->timestamp = 0;
    opts->show_help = 0;
    opts->show_version = 0;
    opts->list_baud = 0;

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
        else if (!strcmp(argv[i], "--log") && i + 1 < argc)
        {
            opts->log_file = argv[++i];
        }
        else if (!strcmp(argv[i], "--timestamp"))
        {
            opts->timestamp = 1;
        }
        else if (!strcmp(argv[i], "--help"))
        {
            opts->show_help = 1;
        }
        else if (!strcmp(argv[i], "--version"))
        {
            opts->show_version = 1;
        }
        else if (!strcmp(argv[i], "--list-baud"))
        {
            opts->list_baud = 1;
        }
        else if (!strcmp(argv[i], "--send") && i + 1 < argc)
        {
            opts->send = argv[++i];
        }
        else
        {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            return -1;
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