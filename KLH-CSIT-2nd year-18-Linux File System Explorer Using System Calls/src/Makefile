CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = explorer

SRC = main.c file_operations.c directory_operations.c file_info.c search.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
