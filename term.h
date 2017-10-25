#ifndef TERM_H
#define TERM_H

#include <string>
#include <sstream>
#include <typeinfo>
//#include "atom.h"
//#include "variable.h"
class Variable;

using std::string;

class Term{
public:
  virtual string symbol() const{return _symbol;}
  virtual string value() const{return symbol();}
  virtual bool match(Term & a);//{
    /*if (typeid(a) ==  typeid(Variable))
      return a.match(*this);
    else*/
      //return symbol() == a.symbol();
  //}
protected:
  Term ();
  Term (string s);
  Term(double db);
  string _symbol;
};

#endif
