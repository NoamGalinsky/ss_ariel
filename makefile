#    noamgal46@gmail.com


CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra -pedantic
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
HEADERS = graph.hpp data_structure.hpp algorithms.hpp
SOURCES = graph.cpp data_structure.cpp algorithms.cpp
OBJECT = graph.o algorithms.o data_structure.o

.PHONY: all clean test Main Main_with_input1 Main_with_input2 valgrind

all:test Main_with_input1 Main_with_input2 Main clean

main_program: main.o $(OBJECT)
	$(CXX) main.o $(OBJECT) -o main_program

test_program: test_function.o $(OBJECT) 
	$(CXX) $(CXXFLAGS) -o test $(OBJECT) test_function.o

test_function.o: test_function.cpp $(HEADERS)
	$(CXX) -c test_function.cpp

main.o: main.cpp $(HEADERS)
	$(CXX) -c main.cpp 

graph.o: graph.cpp graph.hpp data_structure.hpp
	$(CXX) -c graph.cpp  

algorithms.o: algorithms.cpp algorithms.hpp graph.hpp data_structure.hpp
	$(CXX) -c algorithms.cpp

data_structure.o: data_structure.cpp data_structure.hpp
	$(CXX) -c data_structure.cpp


Main: main_program
	./main_program

Main_with_input1: main_program
	./main_program < input1

Main_with_input2: main_program
	./main_program < input2

test: test_program
	./test

valgrind: main_program
	valgrind $(VALGRIND_FLAGS) ./main_program < input1
	valgrind $(VALGRIND_FLAGS) ./main_program < input2
	valgrind $(VALGRIND_FLAGS) ./main_program 

clean:
	rm *.o main_program test