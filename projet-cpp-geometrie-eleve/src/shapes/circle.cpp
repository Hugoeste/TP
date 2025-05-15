#include "point.hpp"
#define _USE_MATH_DEFINES
#include "shapes/circle.hpp"
#include "CTurtle.hpp"
#include <cmath>
#include <cassert>
#include <iostream>
double abso(double x){
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
  return pi*radius*radius;
}

void Circle::draw() {
    cturtle::TurtleScreen screen;
    cturtle::Turtle t(screen);
	t.penup();
	t.setposition(center.x,center.y - radius);
	t.pendown();
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
  bool egal = abso(radius - circle.radius) < e;
  
  return egal;
}
  
  
