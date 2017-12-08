#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T> class Iterator;

class List : public Term {
public:
  Iterator<Term *> *createIterator();
  Iterator<Term *> *createDFSIterator();
  Iterator<Term *> *createBFSIterator();
  bool match(Term & term);
  string symbol() const;
  string value() const;

  Term * args(int i){
    return _elements[i];
  }

  int arity(){
    return _elements.size();
  }

  vector<Term *> getElement()
  {
    return _elements;
  }

  List (): _elements(){}

  List (vector<Term *> const & elements):_elements(elements){
    _assignable = false;
  }

  Term * head() const{
      if(_elements.empty())
          throw std::string("Accessing head in an empty list");

      return _elements[0];
  }


  List * tail() const {
      if(_elements.empty())
          throw std::string("Accessing tail in an empty list");
      vector<Term *> _clone_elements;
      _clone_elements.assign(_elements.begin()+1, _elements.end());
      List *ls= new List(_clone_elements) ;
      return ls;
  }

private:
  bool _assignable = true;
  vector<Term *> _elements;
};

#endif
