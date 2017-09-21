#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
#include <iostream>
#include <vector>
using namespace std;

TEST (Sort, sortByIncreasingPerimeter) {
  //std::vector<Shape *> v; //宣告vector v is a Shape point
  list <Shape *> listS;
  list<Shape *>::iterator itr;
  vertex v1;
  vertex v2;
  vertex v3;
  v1.x = 0;
  v1.y = 0;
  v2.x = 0;
  v2.y = 3;
  v3.x = 4 ;
  v3.y = 0;
  //cout << "v2.x = " << v2.x ;

  Circle c(0,0,10);
  Rectangle r(0,0,3,2);
  Triangle t(v1, v2, v3);

  //ASSERT_DOUBLE_EQ(314.15926535897933, c.area());//(pi*r)^2
  //ASSERT_EQ(6, r.area());//3*2
  //ASSERT_EQ(6, t.area());//3*4/2
  //ASSERT_DOUBLE_EQ(62.831853071795862, c.perimeter());//2*PI*R
  //ASSERT_EQ(10, r.perimeter()); //3+3+2+2
  //ASSERT_EQ(12, t.perimeter()); //3+4+5

  listS.push_back(&c);//放入位址
  listS.push_back(&r);
  listS.push_back(&t);
  //cout<< "listS.size = "<<listS.size();
  sortByIncreasingPerimeter(&listS);
  /*itr = listS.begin();
  cout << "listS[0] = " << (*itr)->toString() << endl;
  itr++;
  cout << "listS[0] = " << (*itr)->toString() << endl;
  itr++;
  cout << "listS[0] = " << (*itr)->toString() << endl;*/
  itr = listS.begin();
  ASSERT_STREQ("r(0 0 3 2)", (*itr)->toString().c_str());
  itr++;
  ASSERT_STREQ("t(0 0 0 3 4 0)", (*itr)->toString().c_str());
  itr++;
  ASSERT_STREQ("c(0 0 10)", (*itr)->toString().c_str());

}

TEST (Sort, sortByDecreasingPerimeter) {

  list <Shape *> listS;
  list<Shape *>::iterator itr;
  vertex v1;
  vertex v2;
  vertex v3;
  v1.x = 0;
  v1.y = 0;
  v2.x = 0;
  v2.y = 3;
  v3.x = 4 ;
  v3.y = 0;

  Circle c(0,0,10);
  Rectangle r(0,0,3,2);
  Triangle t(v1, v2, v3);

  listS.push_back(&c);//放入位址
  listS.push_back(&r);
  listS.push_back(&t);

  sortByDecreasingPerimeter(&listS);//排序

  itr = listS.begin();
  ASSERT_STREQ("c(0 0 10)", (*itr)->toString().c_str());//UT
  itr++;
  ASSERT_STREQ("t(0 0 0 3 4 0)", (*itr)->toString().c_str());
  itr++;
  ASSERT_STREQ("r(0 0 3 2)", (*itr)->toString().c_str());

}

TEST (Sort, sortByIncreasingArea) {
  list <Shape *> listS;
  list<Shape *>::iterator itr;
  vertex v1;
  vertex v2;
  vertex v3;
  v1.x = 0;
  v1.y = 0;
  v2.x = 0;
  v2.y = 3;
  v3.x = 4 ;
  v3.y = 0;

  Circle c(0,0,10);
  Rectangle r(0,0,3,2);
  Triangle t(v1, v2, v3);

  listS.push_back(&c);//放入位址
  listS.push_back(&r);
  listS.push_back(&t);

  sortByIncreasingArea(&listS);

  itr = listS.begin();
  ASSERT_STREQ("r(0 0 3 2)", (*itr)->toString().c_str());//UT
  itr++;
  ASSERT_STREQ("t(0 0 0 3 4 0)", (*itr)->toString().c_str());
  itr++;
  ASSERT_STREQ("c(0 0 10)", (*itr)->toString().c_str());
}

TEST (Sort, sortByDecreasingArea) {
  list <Shape *> listS;
  list<Shape *>::iterator itr;
  vertex v1;
  vertex v2;
  vertex v3;
  v1.x = 0;
  v1.y = 0;
  v2.x = 0;
  v2.y = 3;
  v3.x = 4 ;
  v3.y = 0;

  Circle c(0,0,10);
  Rectangle r(0,0,3,2);
  Triangle t(v1, v2, v3);

  listS.push_back(&c);//放入位址
  listS.push_back(&r);
  listS.push_back(&t);

  sortByDecreasingArea(&listS);

  itr = listS.begin();

  ASSERT_STREQ("c(0 0 10)", (*itr)->toString().c_str());//UT
  itr++;
  ASSERT_STREQ("r(0 0 3 2)", (*itr)->toString().c_str());
  itr++;
  ASSERT_STREQ("t(0 0 0 3 4 0)", (*itr)->toString().c_str());

}

TEST (Sort, sortByIncreasingCompactness) {
  list <Shape *> listS;
  list<Shape *>::iterator itr;
  vertex v1;
  vertex v2;
  vertex v3;
  v1.x = 0;
  v1.y = 0;
  v2.x = 0;
  v2.y = 3;
  v3.x = 4 ;
  v3.y = 0;

  Circle c(0,0,10);
  Rectangle r(0,0,3,2);
  Triangle t(v1, v2, v3);

  listS.push_back(&c);//放入位址
  listS.push_back(&r);
  listS.push_back(&t);

  sortByIncreasingCompactness(&listS);
  itr = listS.begin();
  ASSERT_STREQ("t(0 0 0 3 4 0)", (*itr)->toString().c_str());
  itr++;
  ASSERT_STREQ("r(0 0 3 2)", (*itr)->toString().c_str());
  itr++;
  ASSERT_STREQ("c(0 0 10)", (*itr)->toString().c_str());//UT
}

#endif
