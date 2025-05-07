#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
double abs(x){
  if (x<0){
    x = -x;
  }
return x;
}
double pi = M_PI;
double e = 0.00000000001;
Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference(){
  return 2*pi*radius;
}

double Circle::area(){
  return pi*rad*rad;
}

void Circle::draw(){
  t.circle(radius);
}

void Circle::translate(Point T){
  center.x += T.x;
  center.y += T.y;
}
void Circle::resize(double ratio){
  radius*=ratio;
}
bool Circle::equals(Circle circle){
  bool egal = abs(radius - circle.radius) < epsilon;
  return egal;
}

  
  
  
