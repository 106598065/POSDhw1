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
  //string _value;
  int _value;
public:
  Number(string s, int v):_symbol(s),_value(v){}
  Number(int v):_symbol(std::to_string(v)), _value(v){}
  string value();
  string symbol();
  bool match(string n);
  bool match(Atom atom);
  bool match(Variable& variable);
  bool match(Number *number);
  bool match(Number& number);
  bool match(Atom& atom);
};

#endif
