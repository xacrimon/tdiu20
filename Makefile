CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast -Woverloaded-virtual -fmax-errors=3 -O0 -g
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

.PHONY: lab2
lab2: $(call objs,lab2)

build/lab2: | build
	mkdir build/lab2

build/lab2/%.o: lab2/%.cpp | build/lab2
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: lab2/test
lab2/test: build/lab2/test
	./build/lab2/test

build/lab2/test: $(call objs,lib lab2) | build/lab2
	$(CXX) $(CXXFLAGS) $(call objs,lib lab2) -o build/lab2/test

.PHONY: lab3
lab3: $(call objs,lab3)

build/lab3: | build
	mkdir build/lab3

build/lab3/%.o: lab3/%.cpp | build/lab3
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: lab3/test
lab3/test: build/lab3/test
	./build/lab3/test

build/lab3/test: $(call objs,lab3) | build/lab3
	$(CXX) $(CXXFLAGS) $(call objs,lab3) -o build/lab3/test
