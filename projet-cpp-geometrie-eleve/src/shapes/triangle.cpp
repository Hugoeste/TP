#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>

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
  Point centre = center();
  double decax=T.x-centre.x;
  double decay=T.y-centre.y;
  A.x+=decax;
  A.y+=decay;
  B.x+=decax;
  B.y+=decay;
  C.x+=decax;
  C.y+=decay;
}

void Triangle::resize(double ratio){
  Point centre= center();
  Point vectA;
  Point vectB;
  Point vectC;
  vectA.x=A.x-centre.x;
  vectA.y=A.y-centre.y;
  vectB.x=B.x-centre.x;
  vectB.y=B.y-centre.y;
  vectC.x=C.x-centre.x;
  vectC.y=C.y-centre.y;
  A.x=centre.x+vectA.x*ratio;
  A.y=centre.y+vectA.y*ratio;
  B.x=centre.x+vectB.x*ratio;
  B.y=centre.y+vectB.y*ratio;
  C.x=centre.x+vectC.x*ratio;
  C.y=centre.y+vectC.y*ratio;
}

void Triangle::rotate(double angle){ 
  Point centre0= center();
  Point origine;
  origine.x=0;
  origine.y=0;
  translate(origine);
  A.x=A.x*std::cos(angle)-A.y*std::sin(angle)
  A.y=A.x*std::sin(angle)-A.y*std::cos(angle)
  B.x=B.x*std::cos(angle)-B.y*std::sin(angle)
  B.y=B.x*std::sin(angle)-B.y*std::cos(angle)
  C.x=C.x*std::cos(angle)-C.y*std::sin(angle)
  C.y=C.x*std::sin(angle)-C.y*std::cos(angle)
  translate(centre0);  
}
	














	










    


bool isRightAngled(){
double long = 0;
	bool py1 = A.distance(B)*A.distance(B) + B.distance(C)* B.distance(C) - C.distance(A)*C.distance(A) == 0;
	bool py2 = A.distance(B)*A.distance(B) + C.distance(A)* C.distance(A) - B.distance(C)*B.distance(C) == 0;
	bool py3 = C.distance(A)*C.distance(A) + B.distance(C)* B.distance(C) - A.distance(B)*A.distance(B) == 0;
	return py1 or py2 or py3;
}

bool isEquilateral(){
	bool cote1 = A.distance(B) ==  B.distance(C);
	bool cote2 = A.distance(B) ==  C.distance(A);
	return cote1 and cote2;
}

bool isIsoceles(){
	bool cote1 = A.distance(B) ==  B.distance(C);
	bool cote2 = A.distance(B) ==  C.distance(A);
	bool cote3 = B.distance(C) == C.distance(A);
	return cote1 or cote2 or cote3;
}





















  
    



