#define _USE_MATH_DEFINES

#include "point.hpp"
#include "shapes.hpp"
#include "include/test.hpp"
#include "include/compareDouble.hpp"
#include <assert.h>
#include <iostream>
#include <cmath>


void testCircle() {
    std::cout << "\n\n------------------------- Circle class -------------------------\n\n";

    //Define circle for tests
    Circle A = Circle(2, Point());
    Circle B = Circle(0, Point(12, 0));
    Circle C = Circle(2, Point(15, 7));
    Circle D = Circle(1, Point(7, 5));
    Circle E = Circle(-2, Point());
    Circle F = Circle(2.5, Point(12,15));

    // Test circumference methods
    std::cout << "----- Circumference methods -----\n";

    assert(isEquals(A.circumference(), C.circumference()) && isEquals(A.circumference(), E.circumference()) && isEquals(A.circumference(), 4*M_PI));
    assert(isEquals(B.circumference()));

    std::cout << "Success\n\n";

    // Test area methods
    std::cout << "----- Area methods -----\n";

    assert(isEquals(A.area(), C.area()) && isEquals(A.area(), E.area()) && isEquals(A.area(), 4*M_PI));
    assert(isEquals(B.area()));

    std::cout << "Success\n\n";

    // Test translate methods
    std::cout << "----- Translate methods -----\n";

    A.translate(Point(12, 15));
    assert(isEquals(A.center.x, 12) && isEquals(A.center.y, 15) && isEquals(A.radius, 2));

    B.translate(Point(-12, 0));
    assert(isEquals(B.center.x) && isEquals(B.center.y) && isEquals(B.radius));

    F.translate(Point());
    assert(isEquals(F.center.x, 12) && isEquals(F.center.y, 15) && isEquals(F.radius, 2.5));

    D.translate(Point(5, 10));
    assert(isEquals(D.center.x, 12) && isEquals(D.center.y, 15) && isEquals(D.radius, 1));

    std::cout << "Success\n\n";

    // Test equals methods (Faux car tes semblables)
    std::cout << "----- Equals methods -----\n";

    assert(A.equals(A));
    assert(!A.equals(B));
    assert(!A.equals(E));

    std::cout << "Success\n\n";

    // Test resize methods
    std::cout << "----- Resize methods -----\n";

    A.resize(0.5);
    assert(A.equals(D));

    A.resize(-1);
    assert(A.equals(D));
    
    A.resize(1);
    assert(A.equals(D));
    
    B.resize(50);
    assert(B.equals(Circle(0)));

    D.resize(2.5);
    assert(D.equals(F));

    C.resize(0);
    assert(C.equals(Circle(0, Point(15, 7))));

    std::cout << "Success\n\n";
}