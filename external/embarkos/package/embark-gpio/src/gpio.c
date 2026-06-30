#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include <gpiod.h>

#include "gpio.h"

int gpio_list(void)
{
    struct dirent *entry;
    DIR *dir;

    dir = opendir("/dev");

    if (!dir)
    {
        perror("opendir");
        return 1;
    }

    printf("Available GPIO chips\n");
    printf("--------------------\n");

    while ((entry = readdir(dir)) != NULL)
    {
        if (!strncmp(entry->d_name, "gpiochip", 8))
            printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}

int gpio_info(const char *chip)
{
    struct gpiod_chip *gpio;
    char path[64];

    snprintf(path, sizeof(path), "/dev/%s", chip);

    gpio = gpiod_chip_open(path);

    if (!gpio)
    {
        perror("gpiod_chip_open");
        return 1;
    }

    printf("GPIO Chip Information\n");
    printf("---------------------\n");
    printf("Name  : %s\n", gpiod_chip_name(gpio));
    printf("Label : %s\n", gpiod_chip_label(gpio));
    printf("Lines : %u\n", gpiod_chip_num_lines(gpio));

    gpiod_chip_close(gpio);

    return 0;
}