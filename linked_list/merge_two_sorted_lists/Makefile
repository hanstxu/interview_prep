CXX=g++

all: main list test
	$(CXX) -o main main.o list.o test.o
	rm -f main.o list.o test.o
	./main

main: main.cpp ../list.h ../../test.h
	$(CXX) -c main.cpp

list: ../list.h ../list.cpp
	$(CXX) -c ../list.cpp

test: ../../test.cpp ../../test.h
	$(CXX) -c ../../test.cpp

clean:
	rm -f main main.o list.o test.o
