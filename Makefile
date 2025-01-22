CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Woverloaded-virtual -fmax-errors=3 -O0 -g

.PHONY: lab1
lab1: lab1/clock.o
  
lab1/clock.o: lab1/clock.cpp lab1/clock.hpp
	$(CXX) $(CXXFLAGS) lab1/clock.cpp -o lab1/clock.o
