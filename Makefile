CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Woverloaded-virtual -fmax-errors=3 -O0 -g
CXXFLAGS_LIB ?= -std=c++17 -w -O0
objs = $(foreach dir,$(1),$(patsubst $(dir)/%.cpp,build/$(dir)/%.o,$(wildcard $(dir)/*.cpp)))

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
lab1: $(call objs,lab1)

build/lab1: | build
	mkdir build/lab1

build/lab1/%.o: lab1/%.cpp | build/lab1
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: lab1/test
lab1/test: build/lab1/test
	./build/lab1/test

build/lab1/test: $(call objs,lib lab1) | build/lab1
	$(CXX) $(CXXFLAGS) $(call objs,lib lab1) -o build/lab1/test
