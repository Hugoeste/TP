#include "point.hpp"
#define _USE_MATH_DEFINES
#include "shapes/circle.hpp"
#include "draw.hpp"
#include<vector>
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
    std::vector<Point> points;
    for (int i = 0; i < 50000; ++i) {
        double angle = 2.0 * M_PI * i / 50000;
        double x = center.x + radius * cos(angle);
        double y = center.y + radius * sin(angle);
        points.push_back({x, y});
    }
	draw_picture(points);
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


  
  
