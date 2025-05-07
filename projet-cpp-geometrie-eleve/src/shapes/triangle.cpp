#include "point.hpp"
#include "shapes/triangle.hpp"

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter(){
  return A.distance(B)+B.distance(C)+C.distance(A);
}

double absolue (double a){
  if(a<0){
    return a*-1;
  }
  return a;
}

double Triangle::area(){
  return 0.5*absolue(A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y))
}

Point Triangle::center(){


}
  
  




