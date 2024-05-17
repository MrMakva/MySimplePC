TARGETCLEAN = console/%.o
TARGET = console/pr3
SHRIFT_C = console/font.c
SHRIFT_OBJ = console/font
SHRIFT_BIN = console/font.bin
SRC_DIR = console
SRC = $(SRC_DIR)/pr3.c
OBJ_DIR = $(SRC_DIR)
OBJ = $(OBJ_DIR)/pr3.o
mSC = mySimpleComputer
SRC_mSC := $(wildcard $(mSC)/*.c)
mTm = myTerm
mBS= myBigChars
mRK= myReadKey

SOURCES_MRK = $(wildcard $(mRK)/*.c)
OBJECT_MRK = $(patsubst $(mRK)/%.c, $(mRK)/%.o, $(SOURCES_MRK))
LIBRARY_MRK = $(SRC_DIR)/myReadKey.a

SOURCES_MBS = $(wildcard $(mBS)/*.c)
OBJECT_MBS = $(patsubst $(mBS)/%.c, $(mBS)/%.o, $(SOURCES_MBS))
LIBRARY_MBS = $(SRC_DIR)/myBigChars.a

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

$(TARGET): $(OBJ) $(LIBRARY_SRC) $(LIBRARY_MSC) $(LIBRARY_MT) $(LIBRARY_MBS) $(LIBRARY_MRK)
	gcc -Wall -ggdb -o $@ $^

$(SHRIFT_BIN):$(SHRIFT_OBJ)
	./console/font
$(SHRIFT_OBJ):$(SHRIFT_C)
	gcc -Wall -o console/font console/font.c  -Iinclude console/myBigChars.a

$(LIBRARY_MSC): $(OBJECT_MSC)
	ar rcs $@ $^

$(LIBRARY_MT): $(OBJECT_MT)
	ar rcs $@ $^

$(LIBRARY_SRC): $(OBJECT_SRC)
	ar rcs $@ $^

$(LIBRARY_MBS): $(OBJECT_MBS)
	ar rcs $@ $^

$(LIBRARY_MRK): $(OBJECT_MRK)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	gcc -Wall -ggdb -c $< -o $@ -I./include

$(mSC)/%.o: $(mSC)/%.c 
	gcc -Wall -ggdb -c $< -o $@ -I./include

$(mTm)/%.o: $(mTm)/%.c 
	gcc -Wall -ggdb -c $< -o $@ -I./include

$(mBS)/%.o: $(mBS)/%.c 
	gcc -Wall -ggdb -c $< -o $@ -I./include

$(mRK)/%.o: $(mRK)/%.c 
	gcc -Wall -ggdb -c $< -o $@ -I./include

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c 
	gcc -Wall -ggdb -c $< -o $@ -I./include

# Для форматирования
SRC_FILES := $(wildcard $(SRC_DIR)/*.c $(mSC)/*.c $(mTm)/*.c $(mBS)/*.c $(mRK)/*.c include/*.h)
format:
	for file in $(SRC_FILES); do \
		clang-format --style=GNU -i --verbose $$file; \
	done

SRC_CLEAN := $(wildcard $(mSC)/*.o $(mTm)/*.o $(mBS)/*.o $(mRK)/*.o)
clean:
	rm -f $(SRC_CLEAN)
	rm -f $(TARGET)
	rm -f console/*.a
	rm -f console/*.o
