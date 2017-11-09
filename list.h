#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

class List : public Term {
public:
  string symbol() const{
    string ret = _symbol;
    if(_elements.empty()){
      ret = "[]";
    }else{
      std::vector<Term *>::const_iterator it = _elements.begin();
      ret ="[";
      for(; it!=_elements.end()-1; ++it){
        ret += (*it)->symbol()+", ";
      }
      ret += (*it)->symbol()+"]";
    }
    return ret;
  }

  string value() const{//return symbol();
    string ret = _symbol;
    if(_elements.empty()){
      ret = "[]";
    }else{
      std::vector<Term *>::const_iterator it = _elements.begin();
      ret ="[";
      for(; it!=_elements.end()-1; ++it){
        ret += (*it)->value()+", ";
      }
      ret += (*it)->value()+"]";
    }
    return ret;
  }

  Term * returnElement(int i){
    return _elements[i];
  }

  int elementSize(){
    return _elements.size();
  }

  vector<Term *> getElement()
  {
    return _elements;
  }

  List (): _elements(){}

  List (vector<Term *>  & elements):_elements(elements){_assignable = false;}
  Term * head() const{
    string ret = "Accessing head in an empty list";
    if(_elements.empty()){
      throw ret;
    }
    return _elements[0];
  }

  List * tail() {
    string ret = "Accessing tail in an empty list";
    if(_elements.empty()){
      throw ret;
    }
    List *lptr = new List();
    lptr->_elements = _elements;
    if(lptr->_elements.size() > 0){
      lptr->_elements.erase(lptr->_elements.begin());
    }
    return lptr;
  }

private:
  bool _assignable = true;
  vector<Term *> _elements;
};

#endif
