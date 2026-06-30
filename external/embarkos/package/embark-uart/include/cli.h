#ifndef CLI_H
#define CLI_H

struct uart_options
{
    const char *device;
    int baudrate;
    int show_help;
    int show_version;
    int list_baud;
};

int cli_parse(int argc, char *argv[], struct uart_options *opts);

void cli_print_help(void);
void cli_print_version(void);
void cli_print_baudrates(void);

#endif