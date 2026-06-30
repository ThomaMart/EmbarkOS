CFLAGS ?= -Wall -Wextra -Iinclude

TARGET = embark-monitor

SRC = \
	src/main.c \
	src/monitor.c \
	src/system.c \
	src/cpu.c \
	src/memory.c \
	src/disk.c \
	src/uptime.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)