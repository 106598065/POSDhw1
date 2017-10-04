all: hw2

hw2: mainNumber.o	atom.o	number.o variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainNumber.o	atom.o	number.o variable.o -lgtest
else
	g++ -o hw2 mainNumber.o	atom.o	number.o variable.o -lgtest -lpthread
endif

mainAtom.o: mainAtom.cpp utAtom.h
	g++ -std=gnu++11 -c mainAtom.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++11 -c atom.cpp

mainVariable.o: mainVariable.cpp utVariable.h
		g++ -std=gnu++11 -c mainVariable.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++11 -c variable.cpp

mainNumber.o: utTerm.h mainNumber.cpp
	g++ -std=gnu++11 -c mainNumber.cpp
number.o: number.h number.cpp
	g++ -std=gnu++11 -c number.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif
