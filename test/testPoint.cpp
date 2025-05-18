#define _USE_MATH_DEFINES

#include "point.hpp"
#include "shapes.hpp"
#include "include/test.hpp"
#include "include/compareDouble.hpp"
#include <assert.h>
#include <iostream>
#include <cmath>

void testPoint() {
    std::cout << "------------------------- Points class -------------------------\n\n";

    // Define point for tests
    Point A = Point();
    Point B = Point(12,15);
    Point C = Point(2, 5);

    // Test distance methods
    std::cout << "----- Distance methods -----\n";

    assert(isEquals(B.distance(A), B.distance()) && isEquals(3*sqrt(41), B.distance()) && isEquals(B.distance(), 3*sqrt(41)));
    assert(isEquals(B.distance(C), C.distance(B)));
    assert(isEquals(10*sqrt(2), B.distance(C)) && isEquals(B.distance(C), 10*sqrt(2)));

    std::cout << "Success\n\n";

    // Test equals methods
    std::cout << "----- Distance methods -----\n";

    assert(A.equals());
    assert(!B.equals(C));
    
    std::cout << "Success\n\n";    
}