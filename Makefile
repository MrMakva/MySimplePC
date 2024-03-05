TARGETCLEAN = console/%.o
TARGET = console/pr1
SRC_DIR = console
SRC = $(SRC_DIR)/pr1.c
OBJ_DIR = $(SRC_DIR)
OBJ = $(OBJ_DIR)/pr1.o
mSC = mySimpleComputer
SRC_mSC := $(wildcard $(mSC)/*.c)

SOURCES = $(wildcard $(mSC)/*.c)
OBJECTS = $(patsubst $(mSC)/%.c, $(SRC_DIR)/%.o, $(SOURCES))
LIBRARY = $(SRC_DIR)/mySimpleComputer.a

# Сборка
all: $(TARGET)

$(TARGET): $(OBJ) $(LIBRARY)
	gcc -Wall -o $@ $^

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -Wall -c $< -o $@

#Компиляция и перемещение .o файлов другой вариант
compile_objects:
	for file in $(wildcard $(mSC)/*.c); do \
		gcc -Wall -c $$file -o $(OBJ_DIR)/$$(basename $$file .c).o; \
	done

# Для форматирования
SRC_FILES := $(wildcard $(SRC_DIR)/*.c $(mSC)/*.c include/*.h)
SRC_CLEAN := $(wildcard $(SRC_DIR)/*.o)
format:
	for file in $(SRC_FILES); do \
		clang-format --style=GNU -i --verbose $$file; \
	done

clean:
	rm -f $(SRC_CLEAN)
	rm -f $(TARGET)
	rm -f $(LIBRARY)