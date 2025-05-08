#/*    noamgal46@gmail.com    */


CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra -pedantic


main_program: main.o SquareMat.o
	$(CXX) $(CXXFLAGS) -o main main.o SquareMat.o

main.o: main.cpp SquareMat.hpp
	$(CXX) -c main.cpp

test_program: testFile.o SquareMat.o
	$(CXX) $(CXXFLAGS) -o test.out SquareMat.o testFile.o

testFile.o: testFile.cpp SquareMat.hpp
	$(CXX) -c testFile.cpp

SquareMat.o: SquareMat.cpp
	$(CXX) -c SquareMat.cpp



Main: main_program
	./main

Main_with_input: main
	./main < input1

test: test_program
	./test.out
valgrind: main_program test_program
	valgrind ./test.out
	valgrind ./main
clean:
	rm *.o test.out main