CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRC_DIR = src
BUILD_DIR = build
TARGET = scheduler

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

.PHONY: all clean dist

all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET) copy_entrada

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

copy_entrada:
	cp $(SRC_DIR)/entrada.txt $(BUILD_DIR)/entrada.txt

clean:
	rm -rf $(BUILD_DIR)

dist: clean
	tar czvf $(TARGET).tar.gz $(SRC_DIR) $(lastword $(MAKEFILE_LIST))
