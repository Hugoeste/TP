CXX = g++
CXXFLAGS = -std=c++23 -Iinclude
LDFLAGS = -lgdi32 -luser32
SRC = src/*.cpp src/shapes/*.cpp main.cpp
SRC1 = src/*.cpp src/shapes/*.cpp test/*.cpp

.PHONY: all clean

all: main

main: $(SRC)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o test $(SRC1) $(LDFLAGS)

clean:
	rm -f main
	rm -f test
