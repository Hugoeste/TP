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
double Square::side(){
  double z;
  z=A.x-A.x;
  if(z<0){
  z=-z;
  return z;
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
  point tempA=A;
  point tempC=C;
  tempA.x=center().x-((center().x-A.x)*ratio);
  tempA.y=center().y-((center().y-A.y)*ratio);
  tempC.x=center().x+((C.y-center().y)*ratio);
  tempC.y=center().y+((C.y-center().y)*ratio);
  A=tempA;
  C=tempC;
}


  


  
  
