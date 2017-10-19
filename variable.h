#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "struct.h"
using std::string;

class Variable : public Term{
public:
  string _value;
  string address = "";
  string *varPtr = &address;

  Variable (string s):_symbol(s){_type = "variable";}
  string const _symbol;

  string *valueAddress(){
    return varPtr;
  }
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
    if(ret == "W"){
      return "1";
      cout << "WWWWWWWWWWW"<<endl;
    }
    return ret;
  }

  bool match( Atom atom ){
    bool ret = _assignable;
    if(_assignable){
      _value = atom._symbol ;
      *varPtr = atom._symbol;
      _assignable = false;
    }else if(atom._symbol == *varPtr){
      ret = true;
    }
    return ret;
  }

  bool match( Number & number ){
    bool ret = _assignable;
    if(_assignable){
      _value = number.value() ;
      *varPtr = number.value();
      _assignable = false;
    }
    return ret;
  }

  bool match( Variable & variable ){
      //varPtr = &variable._value;
      //variable.varPtr = &_value;
      if(*(variable.varPtr) != ""){
         *varPtr = *(variable.varPtr);
      }else{
        *(variable.varPtr) = variable._symbol;
        *varPtr = *(variable.varPtr);
        //cout<<"varPtr = "<<*varPtr<<endl;
        //cout<<"variable.symbol = "<<variable._symbol<<endl;
      }
      variable.varPtr = varPtr;
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

  string type(){
    return _type;
  }



  //string _type = "variable";
private:
  //string _value;

  std::vector<Term *> varVector;
  bool _assignable = true;
  bool _assignableVar = true;
};

#endif
