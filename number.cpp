#include "number.h"
#include "atom.h"
#include "variable.h"
using std::string;

//public Number(string s, string v):_symbol(s),_value(v){};
string Number::value(){ return std::to_string(_value); }
string Number::symbol(){ return _symbol; }
bool Number::match(string n){
  //cout << "This is matchString"<< endl;
  if(std::to_string(_value) == n){ return true;}
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

bool Number::match(Number *number){
  bool matched = false;
  if(_value == number->_value){
    matched = true;
  }
  return matched;
}

bool Number::match(Number& number){
  bool matched = false;
  if(_value == number._value){
    matched = true;
  }
  return matched;
}

bool Number::match(Atom& atom){
  return false;
}
