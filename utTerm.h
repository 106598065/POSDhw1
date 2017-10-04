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
  //cout <<"X:value = " << X.value() << endl;
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
  Atom tom("tom");
  Number N5("N5","5");
  ASSERT_FALSE(tom.match(N5));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
  Atom tom("tom");
  Variable X("X");
  //cout <<"X:value = " << X.value() << endl;
  ASSERT_TRUE(tom.match(X));
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_TRUE(tom.match(X));
  //cout <<"X:value = " << X.value() << endl;
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
  Atom jerry("jerry");
  Atom tom("tom");
  Variable X("X");
  //ASSERT_TRUE(X.match(jerry));
  X.match(jerry);
  ASSERT_FALSE(tom.match(X));
  //cout <<"X:value = " << X.value() << endl;
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
  Number N5("N5","5");
  Variable X("X");
  ASSERT_TRUE(X.match(N5));
  //cout <<"X:value = " << X.value() << endl;
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
  Number N25("N25","25");
  Number N100("N100","100");
  Variable X("X");
  X.match(N25);
  ASSERT_FALSE(X.match(N100));
  //cout <<"X:value = " << X.value() << endl;
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
  Atom tom("tom");
  Number N25("N25","25");
  Variable X("X");
  X.match(tom);
  ASSERT_FALSE(X.match(N25));
  //cout <<"X:value = " << X.value() << endl;
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
  Atom tom("tom");
  Number N25("N25","25");
  Variable X("X");
  tom.match(X);
  ASSERT_FALSE(N25.match(X));
  //cout <<"X:value = " << X.value() << endl;
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_TRUE(X.match(tom));
  //cout <<"X:value = " << X.value() << endl;
}
#endif
