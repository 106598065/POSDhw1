#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
//using std::vector;
//using std::string;
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

/*  bool match(Term & term){
    bool ret = false;
    int i = 0;

    if(!_elements.empty()){
      ret = ( (this->value()) == (term.value()) );
      //cout<<"_elements["<<i<<"].value() = "<<_elements[i]->value()<<endl;
      //cout<<"this.value() = "<<this->value()<<endl;
      //cout<<"term.value() = "<<term.value()<<endl;
    }
    return ret;
  };
*/
/*  bool match(List & list){
    int i = 0;
    bool ret = true;
    if(_elements.size() == list.elementSize()){
      for(i = 0; i < _elements.size(); ++i){
        if(! _elements[i]->match( *(list).returnElement(i) )){
          //cout<<"_elements[i].value() = "<<_elements[i]->value()<<endl;
          //cout<<"List.returnElement = "<<list.returnElement(i)->value()<<endl;
          //cout<<"match success"<<endl;
          ret = false;
        }
      }
    }else{
      ret = false;
    }
    return ret;
  }*/

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
    if(_elements.size()==0)
    {
      throw std::string("Accessing head in an empty list");
    }
    return _elements[0];
  }

  List * tail() {
    if(_elements.size()==0)
    {
      throw std::string("Accessing tail in an empty list");
    }
    List *l = new List();
    l->_elements = _elements;
    if(l->_elements.size() > 0){
      l->_elements.erase(l->_elements.begin());
    }
    return l;
  };

private:
  bool _assignable = true;
  vector<Term *> _elements;
  //vector<Term *> _elements1 = {&this->_elements};

};

#endif
