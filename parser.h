#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"
#include "node.h"
#include <typeinfo>
using std::string;
using std::type_info;

#include "utParser.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(){}

  Term* termItr( Term * term){
    //cout<<"(term->symbol() = "<<term->symbol()<<endl;
    for(int index = 0; index < _terms.size(); index++){
      //cout<<"_terms[index].symbol() = "<<_terms[index]->symbol()<<endl;
      //cout<<"index = "<<index<<endl;

      if(term->symbol() == _terms[index]->symbol()){
        return _terms[index];
      }
      //cout<<"_terms[index].symbol() = "<<_terms[index]->symbol()<<endl;
      Struct * s = dynamic_cast<Struct *>(_terms[index]);

      if(s){
        //cout<<"hello"<<endl;
        return structItr(term,s);
      }else{
        //cout <<"s = "<< s <<endl;
      }
    }
    return nullptr;
  }

  Term* structItr(Term * term, Struct * s){
    for(int i = 0; i < s->arity(); i++){
       if(s->args(i)->symbol() == term->symbol()){
         //cout<<" ss->args(i)->symbol = "<<i<<" "<<s->args(i)->symbol()<<endl;
         return s->args(i);
       }
       Struct * ss = dynamic_cast<Struct*>(s->args(i));

       if(ss) {
        return structItr(term,ss);
      }
    }
  }

  void matchings(){
    Term* term = createTerm();
    if(term!=nullptr)
    {
      if(isComma == true){
        Term * findTerm = termItr(term);//find left tree term X
        //cout<<"term.s = "<<term->symbol()<<endl;
        if(findTerm != nullptr) term->match(*findTerm);//use right X match left X
        //Struct * s = dynamic_cast<Struct *>(_terms[index]);


        //cout<<"_terms.back() = "<<_terms.back()->symbol()<<endl;
        _terms.push_back(term);
        //cout<<"_terms.back() = "<<_terms.back()->symbol()<<endl;
        //cout<<"term.symbol() = "<< term.symbol()<<endl;

        //Term * findTerm2 = termItr(term);//find left tree term X
        //if(findTerm2 != nullptr) term->match(*findTerm2);

      }else{
        _terms.push_back(term);
      }
      while((_currentToken = _scanner.nextToken()) == ',' || _currentToken == '=' || _currentToken == ';') {
        if(_currentToken == '='){
          //isComma = false;
          Node * left = new Node(TERM, _terms.back(), nullptr, nullptr);
          _terms.push_back(createTerm());
          //cout<<"_terms.back() = "<<_terms.back()->symbol()<<endl;
          Node * right = new Node(TERM, _terms.back(), nullptr, nullptr);
          //cout<<"_terms.back() = "<<_terms.back()->symbol()<<endl;
          //cout<<"terms.symbol() = "<<term->symbol()<<endl;
          Node * root = new Node(EQUALITY, nullptr, left, right);
          _tree = root;

        //  Struct * s = dynamic_cast<Struct *>(_terms.back());
          /*if(s){
            cout<<"sssssssss"<<endl;
            Term * findTerm2 = termItr(_terms.back());//find left tree term X
            //cout<<"term.s = "<<term->symbol()<<endl;
            if(findTerm2 != nullptr) term->match(*findTerm2);
          }*/

        }else if( _currentToken == ','){
          isComma = true;
          //tree left = _tree
          //tree root = comma
          //tree right =
          Node * left = _tree;
          //_terms.push_back(createTerm());
          matchings();
          Node * root = new Node(COMMA, nullptr, left, _tree);
          _tree = root;
          //cout<<"HHH"<<endl;
        }else if( _currentToken == ';' ){
          isComma = false;
          Node * left = _tree;
          matchings();
          Node * root = new Node(SEMICOLON, nullptr, left, _tree);
          _tree = root;
        }
      }
    }
  }

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }



  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> & getTerms() {
    return _terms;
  }

  Node * expressionTree(){
    return _tree;
  }



private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest,ListOfTermsEmpty);
  FRIEND_TEST(ParserTest,listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

  vector<Term *> _terms;
  Scanner _scanner;
  int _currentToken;
  Node * _tree;
  bool isComma = false;
};
#endif
