CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = list.c main.c
OBJ = $(SRC:.c=.o)

TARGET = list

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
