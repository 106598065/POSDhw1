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
    if (_inst){
      //cout<<"HH = "<<(*_inst).value()<<endl;
      //cout<<" u call varialbe value "<<endl;
      return _inst->value();
    }
    else{
      //cout<<" hello 2"<<endl;
      return Term::value();
    }

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
  /*string symbol() const{
    string ret = _symbol;
            //cout<<"HELLO"<<endl;
      if(_inst){
        ret += " = ";
        ret += (*_inst).symbol();
      }
    return ret;
  }*/
  /*string value() const{
    string ret = (*_inst).value();
            cout<<"HELL1O = "<<(*_inst).value()<<endl;
      /*if(_inst){
        ret += " = ";
        ret += (*_inst).value();
          cout<<"HELL2O"<<endl;
      }
    return ret;
  }*/
private:
  Term * _inst;
};

#endif
