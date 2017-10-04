#all: madRace utAtom utTerm
#all: utTerm utAtom utVariable
#madRace: mainMadRace.o
	#g++ -o madRace mainMadRace.o -lgtest -lpthread
#mainMadRace.o: mainMadRace.cpp madRace.h utMadRace.h
	#g++ -std=gnu++11 -c mainMadRace.cpp
all: hw2

hw2: mainNumber.o	atom.o	number.o variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainNumber.o	atom.o	number.o variable.o -lgtest
else
	g++ -o hw2 mainNumber.o	atom.o	number.o variable.o -lgtest -lpthread
endif

utAtom: mainAtom.o atom.o
	g++ -o utAtom mainAtom.o atom.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h
	g++ -std=gnu++11 -c mainAtom.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++11 -c atom.cpp

utVariable: mainVariable.o variable.o
		g++ -o utVariable mainVariable.o variable.o -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h
		g++ -std=gnu++11 -c mainVariable.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++11 -c variable.cpp

utTerm: mainNumber.o number.o variable.o
	g++ -o utTerm mainNumber.o number.o	variable.o -lgtest -lpthread
mainNumber.o: utTerm.h mainNumber.cpp
	g++ -std=gnu++11 -c mainNumber.cpp
number.o: number.h number.cpp
	g++ -std=gnu++11 -c number.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++11 -c variable.cpp


clean:
	rm -f *.o madRace utAtom utTerm
stat:
	wc *.h *.cpp
