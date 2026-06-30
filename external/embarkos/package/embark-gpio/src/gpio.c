#include <stdio.h>
#include <gpiod.h>

#include "../include/gpio.h"

int gpio_list(void)
{
    char path[32];

    printf("Available GPIO chips\n");
    printf("--------------------\n");

    for (int i = 0; i < 8; i++)
    {
        struct gpiod_chip *chip;

        snprintf(path, sizeof(path), "/dev/gpiochip%d", i);

        chip = gpiod_chip_open(path);

        if (chip)
        {
            printf("%s\n", gpiod_chip_name(chip));
            gpiod_chip_close(chip);
        }
    }

    return 0;
}

int gpio_info(const char *chip_name)
{
    char path[64];
    struct gpiod_chip *chip;

    snprintf(path, sizeof(path), "/dev/%s", chip_name);

    chip = gpiod_chip_open(path);

    if (!chip)
    {
        perror("gpiod_chip_open");
        return 1;
    }

    printf("GPIO Chip Information\n");
    printf("---------------------\n");
    printf("Name  : %s\n", gpiod_chip_name(chip));
    printf("Label : %s\n", gpiod_chip_label(chip));
    printf("Lines : %u\n", gpiod_chip_num_lines(chip));

    gpiod_chip_close(chip);

    return 0;
}

int gpio_get(const char *chip_name, unsigned int line)
{
    printf("gpio_get(%s, %u) not implemented yet.\n",
           chip_name,
           line);

    return 0;
}

int gpio_set(const char *chip_name,
             unsigned int line,
             int value)
{
    printf("gpio_set(%s, %u, %d) not implemented yet.\n",
           chip_name,
           line,
           value);

    return 0;
}