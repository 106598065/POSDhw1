#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "term.h"
#include "iterator.h"
TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    // StructIterator it(&s);
    //Iterator *itStruct = s.createIterator();
    Iterator<Term *> *itStruct = s.createIterator();
    //Struc尚未實作createIterator, 目前是使用Term的 isDone =True
    //Struct實作後, isDone = False
    EXPECT_FALSE(itStruct->isDone());
    //Iterator& itStruct = it;
    // ASSERT_EQ(it.first()->symbol());
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

 TEST(iterator, nested_iterator) {
   Number one(1);
   Variable X("X");
   Variable Y("Y");
   Number two(2);
   Struct t(Atom("t"), { &X, &two });
   Struct s(Atom("s"), { &one, &t, &Y });
   StructIterator<Term*> it(&s);
   it.first();
   it.next();
   Struct *s2 = dynamic_cast<Struct *>(it.currentItem());

   StructIterator<Term *> it2(s2);
   it2.first();
   ASSERT_EQ("X", it2.currentItem()->symbol());
   ASSERT_FALSE(it2.isDone());
   it2.next();
   ASSERT_EQ("2", it2.currentItem()->symbol());
   ASSERT_FALSE(it2.isDone());
   it2.next();
   ASSERT_TRUE(it2.isDone());
}

TEST(iterator, firstList) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    //cout<<"l.size = "<<l.elementSize()<<endl;
    //ListIterator<Term *> it(&l);
    //cout<<"it.currentItem = "<<it.currentItem()<<endl;
    //Iterator<Term *> * itList = &it;

    Iterator<Term *> *itList = l.createIterator();
    //Iterator<Term *> *itStruct = t.createIterator();
    EXPECT_FALSE(itList->isDone());
    //EXPECT_FALSE(itStruct->isDone());
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());/**/
}

TEST(iterator, NullIterator){
  Number one(1);
  NullIterator<Term *> nullIterator(&one);
  nullIterator.first();
  ASSERT_TRUE(nullIterator.isDone());
  Iterator<Term*> * it = one.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}

TEST(iterator, StructDFSiterator){
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });

  Iterator<Term *> *itStruct = s.createDFSIterator();
  itStruct->first();

  //EXPECT_FALSE(itStruct->isDone());
  EXPECT_FALSE(itStruct->isDone());
  EXPECT_EQ("1", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_EQ("X", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_EQ("2", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_EQ("Y", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_TRUE(itStruct->isDone());
}

TEST(iterator, ListDFSiterator){
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  List l({ &one, &t, &Y });

  Iterator<Term *> *itList = l.createDFSIterator();
  //EXPECT_FALSE(itList->isDone());
  itList->first();
  EXPECT_EQ("1", itList->currentItem()->symbol());
  itList->next();
  EXPECT_EQ("t(X, 2)", itList->currentItem()->symbol());
  itList->next();
  EXPECT_EQ("X", itList->currentItem()->symbol());
  itList->next();
  EXPECT_EQ("2", itList->currentItem()->symbol());
  itList->next();
  EXPECT_EQ("Y", itList->currentItem()->symbol());
  itList->next();
  EXPECT_TRUE(itList->isDone());
}

TEST(iterator, StructBFSiterator){
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });

  Iterator<Term *> *itStruct = s.createBFSIterator();
  itStruct->first();

  EXPECT_FALSE(itStruct->isDone());
  EXPECT_EQ("1", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_EQ("Y", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_EQ("X", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_EQ("2", itStruct->currentItem()->symbol());
  itStruct->next();
  EXPECT_TRUE(itStruct->isDone());
}

TEST(iterator, ListBFSiterator){
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  List l({ &one, &t, &Y });

  Iterator<Term *> *itList = l.createBFSIterator();
  //EXPECT_FALSE(itList->isDone());
  itList->first();
  EXPECT_EQ("1", itList->currentItem()->symbol());
  itList->next();
  EXPECT_EQ("t(X, 2)", itList->currentItem()->symbol());
  itList->next();
  EXPECT_EQ("Y", itList->currentItem()->symbol());
  itList->next();
  EXPECT_EQ("X", itList->currentItem()->symbol());
  itList->next();
  EXPECT_EQ("2", itList->currentItem()->symbol());
  itList->next();
  EXPECT_TRUE(itList->isDone());
}


#endif
