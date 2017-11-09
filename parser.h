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

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}

  Term* createTerm(){
    int token = _scanner.nextToken();
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) {
          _scanner.nextToken();
          vector<Term*> terms = getArgs();
          if(_currentToken == ')'){
            return new Struct(*atom, terms);
          }
        }
        else
          return atom;
    }else if(token == '['){
        vector<Term *> terms = getArgs();
        if(_currentToken == ']'){
          if(terms.size() > 0){
            return new List(terms);
          }else if(terms.size() == 0){
            return new List();
          }
          else{
            throw string("unexpected token");
          }
        }
        else if(_currentToken == ')'){
          throw string("unexpected token");
        }
    }
    else if(token == ']'){
      _currentToken=']';
      return nullptr;
    }
    else if(token == ')'){
      _currentToken = ')';
      return nullptr;
    }

    return nullptr;
  }

  vector<Term*> getArgs()
  {
    Term* term = createTerm();
    vector<Term*> args;
    if(term){
      args.push_back(term);

      while((_currentToken = _scanner.nextToken()) == ',') {
        args.push_back(createTerm());
      }
    }
    return args;
  }




private:
  Scanner _scanner;
  int _currentToken = -1;
};
#endif
