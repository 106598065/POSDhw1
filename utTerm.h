#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"

//test Number.value()
TEST (Number,ctor) {
  Number N("N","5");
  ASSERT_EQ("5",N.value());
}
//test Number.symbol()
TEST (Number, symbol) {
  Number N("N","5");
  ASSERT_EQ("N",N.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
  Number N("N","5");
  ASSERT_TRUE(N.match("5"));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
  Number N("N","5");
  ASSERT_FALSE(N.match("6"));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
  Atom tom("tom");
  Number N("N","5");
  ASSERT_FALSE(N.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
  Variable X("X");
  Number N5("N5","5");
  Number N25("N25","25");
  ASSERT_TRUE(N5.match(X));
  //ASSERT_TRUE(N25.match(X));
  //ASSERT_EQ(N5.value(),X.value());
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
  Atom tom("tom");
  Number N5("N5","5");
  //ASSERT_TRUE(tom.match(N5));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {

}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {

}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {

}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {

}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {

}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){

}
#endif
