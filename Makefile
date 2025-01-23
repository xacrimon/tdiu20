CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Woverloaded-virtual -fmax-errors=3 -O0 -g
CXXFLAGS_LIB ?= -std=c++17 -w -O0

LIB_OBJ = $(patsubst lib/%.cpp, build/lib/%.o, $(wildcard lib/*.cpp))
LAB1_OBJ = $(patsubst lab1/%.cpp, build/lab1/%.o, $(wildcard lab1/*.cpp))

.PHONY: default
default:
	@echo "error: no default target"

.PHONY: clean
clean:
	rm -rf build

build:
	mkdir build

build/lib: | build
	mkdir build/lib

build/lib/%.o: lib/%.cpp | build/lib
	$(CXX) $(CXXFLAGS_LIB) -c $< -o $@

.PHONY: lab1
lab1: $(LAB1_OBJ)

build/lab1: | build
	mkdir build/lab1

build/lab1/%.o: lab1/%.cpp | build/lab1
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: lab1/test
lab1/test: build/lab1/test
	./build/lab1/test

build/lab1/test: $(LIB_OBJ) $(LAB1_OBJ) | build/lab1
	$(CXX) $(CXXFLAGS) $(LIB_OBJ) $(LAB1_OBJ) -o build/lab1/test
