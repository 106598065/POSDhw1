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
    //std::ostringstream strs;
    //strs << _value;
    //std::string str = strs.str();
    //return str;
    //return std::to_string(_value);
    return _value;
  }
  bool match (Term & term){
    bool ret = false;
    if(term._type =="variable"){
      *term.varPtr = _value;
      ret = true;
    }else{
      ret = Term::match(term);
    }
    return ret;
  }

  string _type = "number";
private:

  string _value;
  string _symbol;
};

#endif
