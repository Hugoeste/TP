#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
double pi = M_PI;

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
  
  
  
  
