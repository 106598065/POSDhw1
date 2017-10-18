all: hw3

hw3: mainAtom.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainAtom.o -lgtest
else
	g++ -o hw3 mainAtom.o -lgtest -lpthread
endif

mainAtom.o: mainAtom.cpp utVariable.h number.h utStruct.h 
	g++ -std=gnu++11 -c mainAtom.cpp
number.o: number.h number.cpp
	g++ -std=gnu++11 -c number.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++11 -c atom.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++11 -c variable.cpp


clean:
	rm -f *.o mainAtom *hw3
stat:
	wc *.h *.cpp
