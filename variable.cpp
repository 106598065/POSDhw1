#include "variable.h"
#include "atom.h"
#include "number.h"

//Variable(string s):_symbol(s){}
string Variable::value(){ return _value; }
bool Variable::match( Atom atom ){
  bool ret = _assignable;
  if(_assignable){
    _value = atom._symbol ;
    _assignable = false;
  }
  else if(atom._symbol == this->value()){//如果不能assign 則比較atom.value以及variable.value 一樣= 回傳true
    return true;
  }
  return ret;
}

bool Variable::match( string s ){
  bool ret = _assignable;
  if(_assignable){
    _value = s ;
    _assignable = false;
  }
  else if(s == this->value()){
    return true;
  }
  return ret;
}

bool Variable::match( Number number ){
  bool ret = _assignable;
  if(_assignable){
    _value = number.value() ;
    _assignable = false;
  }
  else if(number.value() == this->value()){
    return true;
  }
  return ret;
}
//123
