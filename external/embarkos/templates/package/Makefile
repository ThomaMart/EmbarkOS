CFLAGS ?= -Wall -Wextra -Iinclude

TARGET = embark-template

SRC = \
	src/main.c \
	src/template.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)