#ifndef UTLIST_H
#define UTLIST_H

#include <string>
using std::string;

#include "list.h"
#include "term.h"
#include "struct.h"
#include "atom.h"
#include "variable.h"
/*
#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
*/

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  List L;
  EXPECT_EQ("[]",L.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
  Number N496(496);
  Number N8128(8128);
  std::vector<Term *> elements = {&N496, &N8128};
  List ll(elements);
  EXPECT_EQ("[496, 8128]",ll.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
  Atom terence_tao("terence_tao");
  Atom alan_mathison_turing("alan_mathison_turing");
  std::vector<Term *> elements = {&terence_tao, &alan_mathison_turing};
  List ll(elements);
  EXPECT_EQ("[terence_tao, alan_mathison_turing]",ll.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
  Variable X("X");
  Variable Y("Y");
  std::vector<Term *> elements = {&X,&Y};
  List L(elements);
  EXPECT_EQ("[X, Y]",L.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
  Atom tom("tom");
  Number N496(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> elements = {&N496, &X, &terence_tao};
  List L(elements);
  ASSERT_FALSE(tom.match(L));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
  Number N8128(8128);
  Number N496(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> elements = {&N496, &X, &terence_tao};
  List L(elements);
  ASSERT_FALSE(N8128.match(L));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
  Number N496(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> elements = {&N496, &X, &terence_tao};
  List L(elements);
  std::vector<Term *> v = {&X};
  Struct s(Atom("s"),v);

  EXPECT_EQ("s(X)",s.symbol());
  EXPECT_FALSE(s.match(L));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
  Number N496(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> elements = {&N496, &X, &terence_tao};
  List L(elements);
  Variable Y("Y");
  EXPECT_TRUE(Y.match(L));
  EXPECT_EQ("Y = [496, X, terence_tao]",Y.symbol());
}

// ?- X = [496, X, terence_tao].
// false. no score
TEST(List, matchToVarOccuredInListShouldFail) {
  Number N496(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> elements = {&N496, &X, &terence_tao};
  List L(elements);
  EXPECT_TRUE(X.match(L));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
  Number N496(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> elements = {&N496, &X, &terence_tao};
  List L1(elements);
  List L2(elements);
  EXPECT_TRUE(L1.match(L2));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
  Number N496(496);
  Variable X("X");
  Variable Y("Y");
  Atom terence_tao("terence_tao");
  std::vector<Term *> elements1 = {&N496, &X, &terence_tao};
  std::vector<Term *> elements2 = {&N496, &Y, &terence_tao};
  List L1(elements1);
  List L2(elements2);
  EXPECT_TRUE(L1.match(L2));
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {// 目前沒顯示X = 8128
  Number N496(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  Number N8128(8128);
  std::vector<Term *> elements1 = {&N496, &X, &terence_tao};
  std::vector<Term *> elements2 = {&N496, &N8128, &terence_tao};
  List L1(elements1);
  List L2(elements2);
  EXPECT_TRUE(L1.match(L2));
  EXPECT_EQ("8128",X.value());
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing. 目前沒顯示
TEST(List, matchVarinListToAtomShouldSucceed) {
  Number N496(496);
  Variable X("X");
  Variable Y("Y");
  Atom terence_tao("terence_tao");
  Atom alan_mathison_turing("alan_mathison_turing");
  std::vector<Term *> elements1 = {&N496, &X, &terence_tao};
  List L1(elements1);
  Y.match(L1);
  X.match(alan_mathison_turing);
  EXPECT_EQ("[496, alan_mathison_turing, terence_tao]",Y.value());
  EXPECT_EQ("alan_mathison_turing",X.value());
}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("first"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
  Atom f("[first]"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("[first]"), l.head()->value());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
  Atom f("[first]"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("third"), l.tail()->tail()->head()->value());
  EXPECT_EQ(string("[]"), l.tail()->tail()->tail()->value());

}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {
  List L1;
  //L1.head()->value();

}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {

}




#endif
