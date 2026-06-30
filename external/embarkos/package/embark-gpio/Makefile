CFLAGS ?= -Wall -Wextra -Iinclude

LDFLAGS += -lgpiod

TARGET = embark-gpio

SRC = \
	src/main.c \
	src/gpio.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean