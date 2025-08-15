# Simple Makefile for wxWidgets 3.3.1 on macOS
# Requires wx-config from wxWidgets installation

CXX = g++
CXXFLAGS = -std=c++17 `wx-config --cxxflags`
LDFLAGS = `wx-config --libs core,base`

TARGET = hello
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)
