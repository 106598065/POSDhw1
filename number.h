#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <iostream>
#include <sstream>
#include "atom.h"

using std::string;
using namespace std;

class Number : public Term{
public:
  Number(double value)//:_symbol(std::to_string(value)),_value(value){}
  {
    std::ostringstream strs;
    strs << value;
    std::string str = strs.str();
    this->_symbol = str;
    this->_value = str;
  }

  string symbol()  const{
    return _value; //std::to_string(_value);
  }
  string value() const{
    std::ostringstream strs;
    strs << _value;
    std::string str = strs.str();
    return str;
    //return std::to_string(_value);
    //return _value;
  }
  //double _value;
  string _value;
private:
  string _symbol;
  //double _value;
};

//class Variable;
//class Atom;
/*
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
  bool match(Atom& atom);
  bool match(Variable& variable);
  bool match(Number *number);
  bool match(Number& number);
  //bool match(Atom& atom);
};

//public Number(string s, string v):_symbol(s),_value(v){};
string Number::value(){ return std::to_string(_value); }
string Number::symbol(){ return _symbol; }
bool Number::match(string n){
  //cout << "This is matchString"<< endl;
  if(std::to_string(_value) == n){ return true;}
  return false;
}
bool Number::match(Atom& atom) {
  //cout << "This is matchAtom"<< endl;
  return false;
}
bool Number::match(Variable& variable){
  //cout << "This is matchVariable"<< endl;
  //return variable.match(_value);
  //return true;
}

bool Number::match(Number *n  umber){
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
*/
#endif
