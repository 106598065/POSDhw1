all:utVariable utScanner utIterator


atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp

utVariable: mainVariable.o atom.o struct.o
		g++ -o utVariable mainVariable.o atom.o struct.o -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h variable.h
		g++ -std=c++11 -c mainVariable.cpp
list.o:list.cpp list.h
		g++ -std=c++11 -c list.cpp
struct.o:struct.cpp struct.h
		g++ -std=c++11 -c struct.cpp
exp: mainExp.o
	g++ -o exp mainExp.o -lgtest -lpthread
mainExp.o: mainExp.cpp exp.h global.h
	g++ -std=c++11 -c mainExp.cpp

utScanner: mainScanner.o atom.o list.o struct.o scanner.h utScanner.h utParser.h parser.h exception.h 
		g++ -o utScanner mainScanner.o atom.o list.o struct.o -lgtest -lpthread
mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h exp.h
		g++ -std=c++11 -c mainScanner.cpp

clean:
	rm -f *.o madRace utAtom utVariable utScanner
stat:
	wc *.h *.cpp
