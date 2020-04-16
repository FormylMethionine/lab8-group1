CXXFLAGS = Wall
objects = string_tests.o string.o tests.o

all: run_tests 

run_tests: $(objects)
	g++ -o run_tests $(objects) 

string_tests.o: string_tests.cpp
	g++ -o string_tests.o -c string_tests.cpp 

string.o: string.cpp string.h
	g++ -c -o string.o string.cpp

tests.o: tests.cpp tests.h
	g++ -c -o tests.o tests.cpp

check:
	./run_tests

clean:
	rm $(objects)
