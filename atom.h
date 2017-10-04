#ifndef ATOM_H
#define ATOM_H
#include <string>


using std::string;
class Number;
class Variable;

class Atom {
public:
  Atom (string s):_symbol(s) {}
  bool operator ==(Atom a) {return _symbol == a._symbol;}
  string _symbol;
  bool match(Number number);
  bool match(Variable& variable);
};

#endif
