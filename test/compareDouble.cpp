#include "include/compareDouble.hpp"
#include <iostream>
#include <cmath>

bool isEquals(double a, double b) {
    return abs(a-b) <= epsilon;
}