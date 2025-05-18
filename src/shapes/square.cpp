#define _USE_MATH_DEFINES

#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include "..\..\test\include\compareDouble.hpp"
#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;

Square::Square(Point P, Point R) : A(P), C(R) {}

double Square::side(){
  return A.distance(C)/sqrt(2);
}

double Square::perimeter(){
    return side()*4;
}

double Square::area(){
    return side()*side();
}

Point Square::center(){
  Point w;
  w.x = (C.x + A.x) / 2;
  w.y = (C.y + A.y) / 2;
  return w;
}

void Square::translate(Point T){
  A.x += T.x;
  A.y += T.y;
  C.x += T.x;
  C.y += T.y;
}

void Square::resize(double ratio){
  Point centre = center();
  double cote = side();

  A.x = centre.x + (cote / 2) * ratio;
  A.y = centre.y + (cote / 2) * ratio;
  C.x = centre.x - (cote / 2) * ratio;
  C.y = centre.y - (cote / 2) * ratio;
}

void Square::rotate(double angle){
  Point centre = center();
  Point F = Point(-centre.x, -centre.y);
  angle *= M_PI / 180;

  translate(F);

  Point tempA3;
  Point tempC3;

  tempA3.x = A.x * cos(angle) - A.y * sin(angle);
  tempA3.y = A.x * sin(angle) + A.y * cos(angle);
  tempC3.x = C.x * cos(angle) - C.y * sin(angle);
  tempC3.y = C.x * sin(angle) + C.y * cos(angle);

  A = tempA3;
  C = tempC3;

  translate(centre);
}

bool Square::equals(Square square){
  for (int i = 0; i <= 3; i++) {
    if (A.equals(square.A) && C.equals(square.C)) {
      return true;
    }

    rotate(90);
  }

  return false;
}

void Square::draw(){
  Point B, D;
  B.x=A.x;
  B.y=C.y;
  D.x=C.x;
  D.y=A.y;
  vector<Point> Points={A,B,C,D,A};
  draw_picture(Points);
}

Circle Square::inscribedCircle(){
  Circle p((side()/2),center());
  return p;
}

Circle Square::circumscribedCircle(){
  Circle n(A.distance(center()),center());
  return n;
}
