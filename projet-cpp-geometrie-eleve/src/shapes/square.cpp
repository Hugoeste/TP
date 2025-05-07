#include "point.hpp"
#include "shapes/square.hpp"
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
Square::double side(){
  double z;
  z=A.x-A.x;
  if(z<0){
  z=-z;
  return z;
}
Square::double perimeter(){
    return side()*4;
}
Square::double area(){
    return side()*side();
}
Square::point center(){
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
Square::void translate(Point T){
  point tempA=A;
  point tempC=C;
  tempA.x=T.x-(center().x-A.x);
  tempA.y=T.y-(center().y-A.y);
  tempC.x=T.x+(C.x-center().x);
  tempC.y=T.y+(C.y-center().y);
  A=tempA;
  C=tempC;
}
  
  
