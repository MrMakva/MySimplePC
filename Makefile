TARGETCLEAN = console/%.o
TARGET = console/pr2
SRC_DIR = console
SRC = $(SRC_DIR)/pr2.c
OBJ_DIR = $(SRC_DIR)
OBJ = $(OBJ_DIR)/pr2.o
mSC = mySimpleComputer
SRC_mSC := $(wildcard $(mSC)/*.c)
mTm = myTerm

SOURCES_MSC = $(wildcard $(mSC)/*.c)
OBJECT_MSC = $(patsubst $(mSC)/%.c, $(mSC)/%.o, $(SOURCES_MSC))
LIBRARY_MSC = $(SRC_DIR)/mySimpleComputer.a

SOURCES_MT = $(wildcard $(mTm)/*.c)
OBJECT_MT = $(patsubst $(mTm)/%.c, $(mTm)/%.o, $(SOURCES_MT))
LIBRARY_MT = $(SRC_DIR)/myTerm.a

SOURCES_SRC := $(wildcard $(SRC_DIR)/*.c)
OBJECT_SRC := $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(filter-out $(SRC), $(SOURCES_SRC)))
LIBRARY_SRC = $(SRC_DIR)/Lprint.a

# Сборка
all: $(TARGET)

$(TARGET): $(OBJ) $(LIBRARY_SRC) $(LIBRARY_MSC) $(LIBRARY_MT) 
	gcc -Wall -o $@ $^

$(LIBRARY_MSC): $(OBJECT_MSC)
	ar rcs $@ $^

$(LIBRARY_MT): $(OBJECT_MT)
	ar rcs $@ $^

$(LIBRARY_SRC): $(OBJECT_SRC)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	gcc -Wall -c $< -o $@ -I./include

$(mSC)/%.o: $(mSC)/%.c 
	gcc -Wall -c $< -o $@ -I./include

$(mTm)/%.o: $(mTm)/%.c 
	gcc -Wall -c $< -o $@ -I./include

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c 
	gcc -Wall -c $< -o $@ -I./include

# Для форматирования
SRC_FILES := $(wildcard $(SRC_DIR)/*.c $(mSC)/*.c $(mTm)/*.c include/*.h)
format:
	for file in $(SRC_FILES); do \
		clang-format --style=GNU -i --verbose $$file; \
	done

SRC_CLEAN := $(wildcard $(mSC)/*.o $(mTm)/*.o)
clean:
	rm -f $(SRC_CLEAN)
	rm -f $(TARGET)
	rm -f console/*.a
	rm -f console/*.o
