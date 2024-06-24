# Define the compiler
CC = gcc

# Define compiler flags
CFLAGS = -fopenmp -Iinclude -Wall -O3 -g

# Check if the PARALLEL flag is set
ifdef PARALLEL
	CFLAGS += -DPARALLEL
endif

# Define the target executables
TARGET = smolar-simd
TEST_TARGET = test

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): smolar.c
	$(CC) $(CFLAGS) -o $(TARGET) smolar.c

# Rule to build the test executable
$(TEST_TARGET): test.o smolar.o
	$(CC) $(CFLAGS) -o $(TEST_TARGET) test.o smolar.o

# Rule to compile test.c into an object file
test.o: test.c
	$(CC) $(CFLAGS) -c test.c

# Rule to compile smolar.c into an object file
smolar.o: smolar.c
	$(CC) $(CFLAGS) -c smolar.c

# Clean up generated files
clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o

# Phony targets
.PHONY: all clean