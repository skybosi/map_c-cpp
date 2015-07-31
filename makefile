DEBUG = gdb
CC = gcc
CC_FLAG = -g -Wall -I
INCLUDE = include
SRC = src/*.c
TARGET = bin/test_map
TESTFILE = source/test.c
OUTFILE = source/test.c.c

$(TARGET):$(SRC)
	find . -name *.c.c -exec rm {} \;
	$(CC) $(CC_FLAG) $(INCLUDE) $(SRC) -o $(TARGET)
clean:				
	find . -name *.c.c -exec rm {} \;
	rm $(TARGET)
test:
	find . -name *.c.c -exec rm {} \;
	@./$(TARGET) $(TESTFILE)
vi:
	@vim $(OUTFILE)
cat:
	@cat $(OUTFILE)
debug:
	@$(DEBUG) ./$(TARGET) $(TESTFILE) $(OUTFILE)

.PHONY:test debug
