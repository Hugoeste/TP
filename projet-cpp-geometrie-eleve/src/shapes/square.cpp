#include "point.hpp"
#include "shapes/square.hpp"
#include <cmath>
using namespace std
Square::Square(Point P, Point R){ 
  A=P;
  C=R;
  if(A.x>C.x){
    double j;
    j=A.x;
    A.x=C.x;
    C.x=j;
  }
  if(A.y>C.y){
    double j;
    j=A.y;
    A.y=C.y;
    C.y=j;
  }
}
double Square::side(){
  return A.distance(C)/sqrt(2);
}
double Square::perimeter(){
    return side()*4;
}
double Square::area(){
    return side()*side();
}
point Square::center(){
  point w;
  if(A.x<C.x){
    w.x=A.x+(C.x-A.x)/2;
  }
  else{
    w.x=C.x+(A.x-C.x)/2;
  }
  if(A.y<C.y){
    w.x=A.y+(C.y-A.y)/2;
  }
  else{
    w.y=C.y+(A.y-C.y)/2;
  }
  return w;
}
void Square::translate(Point T){
  point tempA=A;
  point tempC=C;
  tempA.x=T.x-(center().x-A.x);
  tempA.y=T.y-(center().y-A.y);
  tempC.x=T.x+(C.x-center().x);
  tempC.y=T.y+(C.y-center().y);
  A=tempA;
  C=tempC;
}
void Square::resize(double ratio){
  point tempA2=A;
  point tempC2=C;
  tempA2.x=center().x-((center().x-A.x)*ratio);
  tempA2.y=center().y-((center().y-A.y)*ratio);
  tempC2.x=center().x+((C.y-center().y)*ratio);
  tempC2.y=center().y+((C.y-center().y)*ratio);
  A=tempA2;
  C=tempC2;
}
void Square::rotate(angle){
  point d=center();
  point F;
  F.x=0;
  F.y=0;
  translate(F);
  point tempA3;
  point tempC3;
  tempA3.x=A.x*cos(angle)-A.y*sin(angle);
  tempA3.y=A.x*sin(angle)+A.y*cos(angle);
  tempC3.x=C.x*cos(angle)-C.y*sin(angle);
  tempC3.y=C.y*sin(angle)+C.y*cos(angle);
  A=tempA3;
  C=tempC3;
  translate(d);
}

bool Square::equals(Square square){
  if(side()==square.side()){
    return true;
  }
  else{
    return false;
  }
}

void Square::draw(){
  Point B, D;
  B.x=A.x;
  B.y=C.y;
  D.x=C.x;
  D.y=A.y;
  vector<Point> Points={A,B,C,D};
  draw_picture(Points);
}
Circle Square::circumscribedCircle(){
  Circle n(A.distance(center()),center());
  return n;
}
Circle Square::inscribedCircle(){
  Circle p((side()/2),center());
  return p;
}
  


  
  
