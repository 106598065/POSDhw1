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
  return ret;
}
