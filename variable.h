#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

using std::string;

class Number;
class Atom;

class Variable{
public:
  Variable(string s):_symbol(s){}
  string const _symbol;
  string value();
  bool match( Atom atom );
  bool match( string s );
  bool match( Number number );

private:
  string _value;
  bool _assignable = true;
};

#endif
