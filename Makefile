CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Woverloaded-virtual -fmax-errors=3 -O0 -g

.PHONY: lab1
lab1: lab1/time.o
  
lab1/time.o: lab1/time.cpp lab1/time.hpp
	$(CXX) $(CXXFLAGS) lab1/time.cpp -o lab1/time.o
