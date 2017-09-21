#include <list>
#include "Shapes.h"
#include <algorithm>
using namespace std;

class Sort {

  public :static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList);

  public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList);

  public :static void sortByIncreasingArea(std::list<Shape *> * shapeList);

  public :static void sortByDecreasingArea(std::list<Shape *> * shapeList);

  public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeList);

};

bool compare_IncresingPerimeter (Shape * first, Shape * second)
{
  return ( first->perimeter() < second->perimeter() );
}

bool compare_DecreasingPerimeter (Shape * first, Shape * second)
{
  return ( first->perimeter() > second->perimeter() );
}

bool compare_IncreasingArea (Shape * first, Shape * second)
{
  return ( first->area() < second->area() );
}

bool compare_DecreasingArea (Shape * first, Shape * second)
{
  return ( first->area() > second->area() );
}

bool compare_IncreasingCompactness (Shape * first, Shape * second)
{
  return ( ( first->area() / first->perimeter() ) < ( second->area() / second->perimeter() ) );
}


static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList)  {
  //cout <<"This is sortByIncreasingPerimeter"<<endl;
  //shapeList->sort(compare_nocase);

  // use the shakeSort
  //int left = 0;
  //int right = shapeList->size()-1;
  //int shift = 0;
  //std::list<Shape *>::iterator it;
  //list<Shape *> tempShape;
  //cout << shapeList->front()->perimeter() <<endl;

  //cout << (*it)->perimeter() <<endl;
  //it++;
  //cout << (*it)->perimeter() <<endl;
  //it++;
  //cout << (*it)->perimeter() <<endl;

  shapeList->sort(compare_IncresingPerimeter);

  //it = shapeList->begin();
  //cout << (*it)->perimeter() <<endl;
  //it++;
  //cout << (*it)->perimeter() <<endl;
  //it++;
  //cout << (*it)->perimeter() <<endl;

}

static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList){
  shapeList->sort(compare_DecreasingPerimeter);
}

static void sortByIncreasingArea(std::list<Shape *> * shapeList){
  shapeList->sort(compare_IncreasingArea);
}

static void sortByDecreasingArea(std::list<Shape *> * shapeList){
  shapeList->sort(compare_DecreasingArea);
}

static void sortByIncreasingCompactness(std::list<Shape *> * shapeList){
  shapeList->sort(compare_IncreasingCompactness);
}
