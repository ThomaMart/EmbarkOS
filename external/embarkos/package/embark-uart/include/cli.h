#ifndef CLI_H
#define CLI_H

struct uart_options {
    const char *device;
    int baudrate;
};

int cli_parse(int argc, char *argv[], struct uart_options *opts);

#endif