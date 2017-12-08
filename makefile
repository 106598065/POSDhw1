all: hw7

hw7: term.o atom.o mainIterator.o list.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw7 term.o atom.o mainIterator.o list.o struct.o -lgtest
else
	g++ -o hw7 term.o atom.o mainIterator.o list.o struct.o -lgtest -lpthread
endif

list.o:list.cpp list.h
	g++ -std=gnu++11 -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++11 -c struct.cpp
term.o: term.cpp term.h variable.h
		g++ -std=gnu++11 -c term.cpp
atom.o: atom.cpp atom.h term.h number.h
		g++ -std=gnu++11 -c atom.cpp
mainIterator.o: mainIterator.cpp utIterator.h
	g++ -std=gnu++11 -c mainIterator.cpp


clean:
		rm -f *.o mainList *hw7
stat:
		wc *.h *.cpp
