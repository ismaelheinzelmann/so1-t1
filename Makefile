CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

SRCDIR := source/cpp
OBJDIR := obj
BINDIR := bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

TARGET := $(BINDIR)/scheduler

all: $(TARGET)

$(TARGET): $(OBJDIR) $(BINDIR) $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(OBJECTS) -o $(TARGET)
	cp -f entrada.txt $(BINDIR)/entrada.txt

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

run: clean all input
	./$(TARGET)

input:
	cp -f entrada.txt $(BINDIR)/entrada.txt

.PHONY: all clean
