#include "point.hpp"
#include <cmath>

Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

double Point::distance(Point B = Point()) {
  return sqrt((B.x_val-x_val)*(B.x_val-x_val)+(B.y_val-y_val)*(B.y_val-y_val));
}
