all: hw6

hw6: term.o atom.o mainScanner.o
ifeq (${OS}, Windows_NT)
	g++ -o hw6 term.o atom.o mainScanner.o -lgtest
else
	g++ -o hw6 term.o atom.o mainScanner.o -lgtest -lpthread
endif

mainList.o: mainList.cpp utList.h
		g++ -std=gnu++11 -c mainList.cpp
mainScanner.o: mainScanner.cpp utScanner.h scanner.h utParser.h parser.h node.h
		g++ -std=gnu++11 -c mainScanner.cpp
term.o: term.cpp term.h variable.h list.h
		g++ -std=gnu++11 -c term.cpp
atom.o: atom.cpp atom.h term.h number.h
		g++ -std=gnu++11 -c atom.cpp



clean:
		rm -f *.o mainList *hw6
stat:
		wc *.h *.cpp
