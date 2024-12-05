# Compiler options
CC = g++
CFLAGS = -c -Wall
LIBS = -lncurses
# Build directory
BUILD_DIR = build
SRC_DIR = src
# Target executable
BIN = dibs
# Source files
SRC = $(SRC_DIR)/main.cpp
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))
# Additional dependencies
SCRIPTS = $(wildcard scripts/*.sh)


all: $(BUILD_DIR)/$(BIN) $(OBJS) $(SCRIPTS)

# Create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create the executable
$(BUILD_DIR)/$(BIN): $(OBJS) | $(BUILD_DIR)
	$(CC) -o $@ $(SRC) $(LIBS)

# Create object files
$(BUILD_DIR)/%.o: $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

# Clean up
clean:
	rm -rf $(BUILD_DIR)