CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Woverloaded-virtual -fmax-errors=3 -O0 -g

.PHONY: lab1
lab1: lab1/time.o

.PHONY: lab1/test
lab1/test: lab1/time_test
	./lab1/time_test

lab1/time_test: lab1/test.o lab1/time.o lib/catch_amalgamated.o
	$(CXX) $(CXXFLAGS) lab1/test.o lab1/time.o lib/catch_amalgamated.o -o lab1/time_test
  
lab1/test.o: lab1/test.cpp
	$(CXX) $(CXXFLAGS) -c lab1/test.cpp -o lab1/test.o

lab1/time.o: lab1/time.cpp lab1/time.hpp
	$(CXX) $(CXXFLAGS) -c lab1/time.cpp -o lab1/time.o

lib/catch_amalgamated.o: lib/catch_amalgamated.cpp lib/catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) -c lib/catch_amalgamated.cpp -o lib/catch_amalgamated.o
