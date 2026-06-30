#ifndef GPIO_H
#define GPIO_H

int gpio_list(void);

int gpio_info(const char *chip);

int gpio_get(const char *chip, unsigned int line);

int gpio_set(const char *chip,
             unsigned int line,
             int value);

#endif