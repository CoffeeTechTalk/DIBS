# Build directory
BUILD_DIR = build
SRC_DIR = src
# Target executable
TARGET = $(BUILD_DIR)/dibs
# Source files
SRC = $(SRC_DIR)/main.cpp

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(SRC) | $(BUILD_DIR)
	g++ -o $(TARGET) $(SRC) -lncurses

clean:
	rm -rf $(BUILD_DIR)