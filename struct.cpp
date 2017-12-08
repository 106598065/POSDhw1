#include "struct.h"
#include "iterator.h"


Iterator<Term *> *Struct::createIterator(){
  return new StructIterator<Term*>(this);
};

Iterator<Term *> *Struct::createDFSiterator(){
  return new DFSiterator<Term*>(this);
};

Iterator<Term *> *Struct::createBFSiterator(){
  return new BFSiterator<Term*>(this);
};
