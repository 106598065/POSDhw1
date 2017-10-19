#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <iostream>
//#include "variable.h"

using std::string;
using namespace std;


class Term{

public:
  string _type;
  string *varPtr = &address;
  string address = "";
  virtual string *valueAddress() {
    return 0;
  }
  virtual string symbol() const= 0;

  virtual string value() const{
    return symbol();
  };

  virtual bool match(Term & term) {
    return symbol() == term.symbol();
  }


};

class Atom : public Term{
public:
  string _symbol;
  string _type = "atom";

  Atom (string s):_symbol(s) {}

  string symbol() const{
    return _symbol;
  }

  bool match(Term & term){
    bool ret = false;
    string *termvalueAddress;
    //printf("type = %s\n",term._type);
    //cout <<"term._type = "<< term._type<<endl;
    if(term._type == "variable"){
      //cout <<"term.varPtr = "<<term.varPtr<<endl;
      //cout <<"*term.varPtr = "<<*term.varPtr<<endl;
      //cout <<"symbol = "<<_symbol<<endl;
      //cout <<"&symbol = "<<&_symbol<<endl;

      /*Variable * ps = dynamic_cast<Variable *>(&term);
      if(ps){
        *(ps->varPtr) = _symbol;
      }*/
      termvalueAddress = term.valueAddress();
      *termvalueAddress = symbol();
      //(term.varPtr) = &_symbol;

      //cout <<"term.varPtr = "<<term.varPtr<<endl;
      //cout <<"term.varPtr = "<<*term.varPtr<<endl;
      //cout <<"term.address = "<< &term.address<<endl;
      //cout <<"symbol = "<<&_symbol<<endl;
      ret = true;
    }else{
      ret = (symbol() == term.symbol());
    }
    return ret;
  }
};


#endif
