CFLAGS ?= -Wall -Wextra -Iinclude

TARGET = embark-gpio

SRC = \
    src/main.c \
    src/gpio.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -lgpiod -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)