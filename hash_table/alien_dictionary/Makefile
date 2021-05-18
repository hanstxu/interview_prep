CXX=g++

all: test main.cpp
	$(CXX) -o main test.o main.cpp
	rm -f main.o test.o
	./main

main: main.cpp .../../test.h
	$(CXX) -c main.cpp

test: ../../test.cpp ../../test.h
	$(CXX) -c ../../test.cpp

clean:
	rm -f main main.o test.o