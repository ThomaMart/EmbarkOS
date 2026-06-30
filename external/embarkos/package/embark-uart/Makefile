CFLAGS ?= -Wall -Wextra -Iinclude

TARGET = embark-uart

SRC = \
	src/main.c \
	src/uart.c \
	src/cli.c \
	src/logger.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)