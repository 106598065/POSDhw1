#include "atom.h"
#include "number.h"
#include "variable.h"

bool Atom::match(Number number) {
  //cout << "This is matchNumber"<< endl;
  return false;
}

bool Atom::match(Variable& variable){
  return variable.match(_symbol);
}
