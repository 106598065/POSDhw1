#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>
#include <string>
#include <iostream>

using std::string;

using namespace std;

class Struct:public Term
{
public:
  Struct(Atom const & name, std::vector<Term *> args):_name(name), _args(args) {
  }

  Term * args(int index) {
    return _args[index];
  }

  Atom const & name() {
    return _name;
  }
  string symbol() const{
    string ret =_name.symbol() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      ret += _args[i]-> symbol() + ", ";
    }
    ret += _args[_args.size()-1]-> symbol() + ")";
    return  ret;
  }

  string value() const{
    string ret =_name.symbol() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      ret += _args[i]-> value() + ", ";
    }
    ret += _args[_args.size()-1]-> value() + ")";
    //if(_args[_args.size()-1]-> value() == "") cout<<"notAssign";
    //cout<<"_args[_args.size()-1]-> value() = /"<<_args[_args.size()-1]-> value()<<"/"<<endl;
    return  ret;
  }

  bool match(Term &term){
    Struct * ps = dynamic_cast<Struct *>(&term);
    if (ps){
      if (!_name.match(ps->_name))
        return false;
      if(_args.size()!= ps->_args.size())
        return false;
      for(int i=0;i<_args.size();i++){
        if(_args[i]->symbol() != ps->_args[i]->symbol())
            return false;
      }
      return true;
    }
    return false;
  }
  string _type = "struct";
private:

  Atom _name;
  std::vector<Term *> _args;
};

#endif
