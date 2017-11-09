#ifndef TERM_H
#define TERM_H

#include <string>
#include <sstream>
#include <typeinfo>
#include <vector>
class Variable;
class List;

using std::string;


class Term{
public:
  virtual string symbol() const{return _symbol;}
  virtual string value() const{return symbol();}
  virtual bool match(Term & a);
  virtual std::vector<Term *> getElement(){
    std::vector<Term *> v;
    return v;
  }
  virtual int arity();
  virtual Term * args(int index);

protected:
  Term ();
  Term (string s);
  Term(double db);
  string _symbol;
};

#endif
