#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <iostream>
//#include "variable.h"
//#include "atom.h"



using std::string;
using namespace std;
//class Atom;
class Variable;
class Atom;

class Number {
private:
  string _symbol;
  string _value;
public:
  Number(string s, string v):_symbol(s),_value(v){};
  string value();
  string symbol();
  bool match(string n);
  bool match(Atom atom);
  bool match(Variable& variable);
};

#endif
