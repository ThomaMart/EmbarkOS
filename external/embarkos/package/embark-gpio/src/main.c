#include <stdio.h>
#include <string.h>

#include "gpio.h"

static void usage(void)
{
    printf("Embark GPIO\n\n");

    printf("Usage:\n");
    printf("    embark-gpio list\n");
    printf("    embark-gpio info <gpiochip>\n");
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

    usage();

    return 1;
}