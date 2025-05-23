#include "..\test\include\compareDouble.hpp"
#include "point.hpp"
#include <cmath>

Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

double Point::distance(Point B) {
  return sqrt((B.x-x)*(B.x-x)+(B.y-y)*(B.y-y));
}

bool Point::equals(Point P) {
  return isEquals(x, P.x) && isEquals(y, P.y);
}