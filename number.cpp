#include "number.h"
#include "atom.h"
#include "variable.h"

//public Number(string s, string v):_symbol(s),_value(v){};
string Number::value(){ return _value; }
string Number::symbol(){ return _symbol; }
bool Number::match(string n){
  //cout << "This is matchString"<< endl;
  if(_value == n){ return true;}
  return false;
}
bool Number::match(Atom atom) {
  //cout << "This is matchAtom"<< endl;
  return false;
}
bool Number::match(Variable& variable){
  //cout << "This is matchVariable"<< endl;
  return variable.match(_value);
  //return true;
}
