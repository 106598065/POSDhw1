#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"
#include <iostream>
using std::string;
using namespace std;

class Variable : public Term {
public:
  Variable(string s):Term(s), _inst(0){}
  string value() const {
    if (_inst)
      return _inst->value();
    else
      return Term::value();
  }
  bool match( Term & term ){
    if (this == &term)
      return true;
    if(!_inst){
      _inst = &term ;
      return true;
      //return (*_inst).symbol();
    }
    return _inst->match(term);
  }
  string symbol() const{
    string ret = _symbol;
            //cout<<"HELLO"<<endl;
      if(_inst){
        ret += " = ";
        ret += (*_inst).symbol();
      }
    return ret;
  }
private:
  Term * _inst;
};

#endif
