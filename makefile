# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Wall -Wextra -Werror -g

# Source directory
SRC_DIR = src

# Build directory
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Executable name
TARGET = $(BUILD_DIR)/main

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build artifacts
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean
