# mkdir flags
MKDIR_FLAGS =
# Compiler options
CC = g++
CFLAGS = -c -Wall
LIBS = -lncursesw
# Build directory
BUILD_DIR = build
SRC_DIR = src
# Target executable
BIN = dibs
# Source files
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/ui/uiHandler.cpp $(SRC_DIR)/cfg/iniMan.cpp
$(info [Targets] [$(SRC)])
# OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))
# OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_DIR)/$(notdir $(SRC)))
# Object files without subdirectories
OBJS := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SRC)))
$(info [Objects] [$(OBJS)])
# Additional dependencies
SCRIPTS = $(wildcard scripts/*.sh)


all: $(OBJS) $(BUILD_DIR)/$(BIN) $(SCRIPTS)

# Create the build directory
$(BUILD_DIR):
	mkdir $(MKDIR_FLAGS) $(BUILD_DIR)

# Create the executable
$(BUILD_DIR)/$(BIN): $(OBJS) | $(BUILD_DIR)
	$(CC) -o $@ $(SRC) $(LIBS)

# Create object files
$(BUILD_DIR)/%.o: $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

# Clean up
clean:
	rm -rf $(BUILD_DIR)

run:
	./$(BUILD_DIR)/$(BIN)