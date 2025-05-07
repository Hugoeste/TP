#include "point.hpp"
#include "shapes/square.hpp"
Square::Square(Point P, Point R) : A(P), C(R) {};
Square::double side(){
  double z;
  z=P.x-R.x;
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
  if(P.x<R.x){
    w.x=P.x+(R.x-P.x)/2;
  }
  else{
    w.x=R.x+(P.x-R.x)/2;
  }
  if(P.y<R.y){
    w.x=P.y+(R.y-P.y)/2;
  }
  else{
    w.y=R.y+(P.y-R.y)/2;
  }
  return w;
}
Square::void draw(){
  
