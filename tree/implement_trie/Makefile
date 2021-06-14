CXX=g++

all: main trie test
	$(CXX) -o main main.o trie.o test.o
	rm -f main.o trie.o test.o
	./main

main: main.cpp ../trie.h ../../test.h
	$(CXX) -c main.cpp

trie: ../trie.h ../trie.cpp
	$(CXX) -c ../trie.cpp

test: ../../test.cpp ../../test.h
	$(CXX) -c ../../test.cpp

clean:
	rm -f main main.o trie.o test.o
