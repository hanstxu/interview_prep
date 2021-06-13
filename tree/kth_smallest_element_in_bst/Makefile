CXX=g++

all: main tree test
	$(CXX) -o main main.o tree.o test.o
	rm -f main.o tree.o test.o
	./main

main: main.cpp ../tree.h ../../test.h
	$(CXX) -c main.cpp

tree: ../tree.h ../tree.cpp
	$(CXX) -c ../tree.cpp

test: ../../test.cpp ../../test.h
	$(CXX) -c ../../test.cpp

clean:
	rm -f main main.o tree.o test.o
