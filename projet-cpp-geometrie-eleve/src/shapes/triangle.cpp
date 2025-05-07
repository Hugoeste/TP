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
  Point centre;
  centre.x=(A.x+B.x+C.x)/3;
  centre.y=(A.y+B.y+C.y)/3;
  return centre;
}
  
void Triangle::draw(){
  vector<Point> Points={A,B,C};
  draw_picture(Points);
}

void Triangle::translate(Point T){
  centre = center();
  decax=T.x-centre.x;
  decay=T.y-centre.y;
  A.x+=decax;
  A.y+=decay;
  B.x+=decax;
  B.y+=decay;
  C.x+=decax;
  C.y+=decay;
}

void Triangle::resize(double ratio){
  






















  
    



