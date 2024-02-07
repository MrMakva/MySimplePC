CC = gcc
CFLAGS = -Wall
TARGETCLEAN =test
TARGET = console/test
SRC_DIR = console
SRC = $(SRC_DIR)/test.c
OBJ_DIR = $(SRC_DIR)
OBJ = $(OBJ_DIR)/test.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETCLEAN) $(OBJ)