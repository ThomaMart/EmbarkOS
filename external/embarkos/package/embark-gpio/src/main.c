#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/gpio.h"

static void usage(void)
{
    printf("Embark GPIO\n\n");

    printf("Usage:\n");
    printf("    embark-gpio list\n");
    printf("    embark-gpio info <gpiochip>\n");
    printf("    embark-gpio get <gpiochip> <line>\n");
    printf("    embark-gpio set <gpiochip> <line> <0|1>\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        usage();
        return 1;
    }

    if (!strcmp(argv[1], "list"))
    {
        return gpio_list();
    }

    if (!strcmp(argv[1], "info"))
    {
        if (argc != 3)
        {
            usage();
            return 1;
        }

        return gpio_info(argv[2]);
    }

    if (!strcmp(argv[1], "get"))
    {
        if (argc != 4)
        {
            usage();
            return 1;
        }

        return gpio_get(argv[2], (unsigned int)atoi(argv[3]));
    }

    if (!strcmp(argv[1], "set"))
    {
        if (argc != 5)
        {
            usage();
            return 1;
        }

        return gpio_set(argv[2],
                        (unsigned int)atoi(argv[3]),
                        atoi(argv[4]));
    }

    usage();

    return 1;
}