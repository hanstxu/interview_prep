CXX=g++

all: main graph test
	$(CXX) -o main main.o graph.o test.o
	rm -f main.o graph.o test.o
	./main

main: main.cpp ../graph.h ../../test.h
	$(CXX) -c main.cpp

graph: ../graph.h ../graph.cpp
	$(CXX) -c ../graph.cpp

test: ../../test.cpp ../../test.h
	$(CXX) -c ../../test.cpp

clean:
	rm -f main main.o graph.o test.o
