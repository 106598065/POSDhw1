#include "term.h"
#include "variable.h"
#include "list.h"
#include "iterator.h"
#include <string>
#include <sstream>
#include <typeinfo>

using std::string;
using std::type_info;

int Term::arity(){
  return 0;
}
Term * Term::args(int index){
  return nullptr;
}

bool Term::match(Term & a){
  int i = 0;
  bool ret = true;
  if (typeid(a) ==  typeid(Variable)){
    return a.match(*this);
  }
  else if(typeid(a) ==  typeid(List)){
    std::vector<Term *> e1,e2;
    e1 = this->getElement();
    e2 = a.getElement();
    if(e1.size() == e2.size()){
      for(i = 0; i <e1.size(); ++i){
        if(! e1[i]->match(*e2[i]) ){
          ret = false;
        }
      }
    }else{
      ret = false;
    }
    return ret;
  }else{
    return symbol() == a.symbol();
  }
}
Iterator<Term *> *Term::createIterator(){
  return new NullIterator<Term *>(this);
}

Term::Term ():_symbol(""){}
Term::Term (string s):_symbol(s) {}
Term::Term(double db){
  std::ostringstream strs;
  strs << db;
  _symbol = strs.str();
}
