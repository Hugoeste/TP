#include "circle.hpp"
#include "point.hpp"
#include <cassert>
#include <cmath>

void testCircle() {	
	Circle A = Circle(1, point());
	Circle B = Circle(0, point(1, 0));
	Circle C = Circle(1, point(2, 32));
	Circle D = Circle(2, point(1, 7));
	
	assert(A.circumference() == C.circumference() == 2*M_PI);
	assert(B.circumference() == 0);
	
	assert(A.area() == C.area() == M_PI);
	assert(B.area() = 0);
	
	assert(!A.equals(B));
	assert(A.equals(A.translate(Point(15,12))));
	
}
