#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
using std::string;

class Variable : public Term{
public:
  Variable (string s):_symbol(s){}
  string const _symbol;

  string symbol() const { return _symbol; }
  string value() const {
    string ret = *varPtr;// = _value;
    //cout <<"VarPtr = "<<*varPtr<<endl;
    if(*varPtr == ""){
      ret = _symbol;
    }
    if(varVector.size()>0){
      return varVector[0]->value();
    }
    return ret;
  }

  bool match( Atom atom ){
    bool ret = _assignable;
    if(_assignable){
      _value = atom._symbol ;
      varPtr = &atom._symbol;
      _assignable = false;
    }
    return ret;
  }

  bool match( Number & number ){
    bool ret = _assignable;
    if(_assignable){
      _value = number.value() ;
      varPtr =(string*) &number._value;
      _assignable = false;
    }
    return ret;
  }

  bool match( Variable & variable ){

      //varPtr = &variable._value;
      //variable.varPtr = &_value;
      varPtr = variable.varPtr;
      //variable.varPtr = varPtr;
      //cout <<"*varPtr = "<<varPtr<<endl;
      //cout <<"variable._value = "<<&variable._value<<endl;
      //cout <<"*variable.varPtr = "<<variable.varPtr<<endl;
      //cout <<"_value = "<<&_value<<endl;
      return true;
  }

  bool match( Struct & s){
    //varPtr = s;
    varVector = {&s};
    //cout<<"varVectorsize = "<<varVector.size()<<endl;
    return true;
  }

  string _value;
  string address = "";
  string *varPtr = &address;
private:
  //string _value;
  std::vector<Term *> varVector;
  bool _assignable = true;
  bool _assignableVar = true;
};

#endif
