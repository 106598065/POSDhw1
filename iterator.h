#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"
#include <queue>

template <class T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual T currentItem() const = 0;
  virtual bool isDone() const = 0;
};

template <class T>
class NullIterator :public Iterator<T>{
public:
  //NullIterator(Term *n){}
  NullIterator(T n){}
  void first(){}
  void next(){}
  //Term * currentItem() const{
  T currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }

};
template <class T>
class StructIterator :public Iterator<T> {
public:
  friend class Struct;
  void first() {
    _index = 0;
  }

  T currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }
  StructIterator(Struct *s): _index(0), _s(s) {}
private:

  int _index;
  Struct* _s;
};
template <class T>
class ListIterator :public Iterator<T> {
public:
  ListIterator(List *list): _index(0), _list(list) {
    //cout<<"l.size = "<<list->elementSize()<<endl;
    //cout<<"_l.size = "<<_list->elementSize()<<endl;
  }

  void first() {
    _index = 0;
  }

  T currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }
private:
  int _index;
  List* _list;
};

template <class T>
class DFSiterator: public Iterator<T>{
public:

  DFSiterator (T term):_index(0), _term(term){}

  void first() {
    _index = 1;
    _terms.clear();
    DFS(_term);
  }

  T currentItem() const {
    return _terms[_index];
  }

  bool isDone() const {
    return _index >= _terms.size() - 1;
  }

  void next() {
      _index++;
    }

  void DFS(T term){
    _terms.push_back(term);
    //cout<<"terms.size = "<<_terms.size()<<endl;
    //cout<<"terms.back = "<<_terms.back()->symbol()<<endl;
    if(term->arity() != 0){
      //cout<<"terms.size = "<<_terms.size()<<endl;
      //cout<<"terms.back = "<<_terms.back()->symbol()<<endl;
      for(int i = 0; i < term->arity(); i++){//將看到的東西放入vector
        if(term->args(i)->arity() != 0){//如果遇到struct or list 則再呼叫DFS進行探索 探索完再繼續
          DFS(term->args(i));
        }else{
          _terms.push_back(term->args(i));
        }
      }
    }
    //cout<<"terms.size = "<<_terms.size()<<endl;
    //cout<<"terms.back = "<<_terms.back()->symbol()<<endl;
      //Iterator<Term *> iterator =
  }
private:
  int _index;
  T _term;
  std::vector<T> _terms;
};

template <class T>
class BFSiterator: public Iterator<T>{
public:

  BFSiterator (T term):_index(0), _term(term){}

  void first() {
    _index = 1;
    _terms.clear();
    BFS(_term);
  }

  T currentItem() const {
    return _terms[_index];
  }

  bool isDone() const {
    return _index >= _terms.size() - 1;
  }

  void next() {
      _index++;
    }

  void BFS(T term){
    queue<T> q;
    _terms.push_back(term);

    if(term->arity() != 0){

      for(int i = 0; i < term->arity(); i++){//將看到的東西放入vector
        if(term->args(i)->arity() != 0){//如果遇到struct or list 先暫存起來
          _terms.push_back(term->args(i));
          q.push(term->args(i));
        }else{
          _terms.push_back(term->args(i));
        }
      }
      while(!q.empty()){//將暫存的Struct or List 依序搜尋
        T n = q.front();
        q.pop();
        if(n->arity() != 0){
          for(int i = 0; i < n->arity(); i++){
            //q.push(n.args(i));
            _terms.push_back(n->args(i));
          }
        }
      }
      //cout<<"queue size = "<<q.size()<<endl;
    }
  }
private:
  int _index;
  T _term;
  std::vector<T> _terms;
  std::vector<T> _termsvec;
};

#endif
