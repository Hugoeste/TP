#define _USE_MATH_DEFINES

#include "../include/point.hpp"
#include "../include/shapes.hpp"
#include "include/test.hpp"
#include "include/compareDouble.hpp"
#include <assert.h>
#include <iostream>
#include <cmath>

void testSquare() {
    std::cout << "\n\n------------------------- Square class -------------------------\n\n";

    // Define square for tests
    Square A = Square(Point(), Point());
    Square B = Square(Point(12, 6), Point(0, -6));
    Square C = Square(Point(-0.1, -0.1), Point());
    Square D = Square(Point(-5, 5), Point(5, -5));
    Square E = Square(Point(12, 15), Point(12, 15));

    Point P, R;
    double side;

    // Test side methods
    std::cout << "----- Side methods -----\n";

    assert(isEquals(A.side()) && isEquals(E.side()));
    assert(isEquals(B.side(), 12));
    assert(isEquals(D.side(), 100*C.side()) && isEquals(D.side(), 10));

    std::cout << "Success\n\n";

    // Test perimeter methods
    std::cout << "----- Perimeter methods -----\n";

    assert(isEquals(A.perimeter()) && isEquals(E.perimeter()));
    assert(isEquals(B.perimeter(), 48));
    assert(isEquals(D.perimeter(), 100*C.perimeter()) && isEquals(D.perimeter(), 40));

    std::cout << "Success\n\n";

    // Test area methods
    std::cout << "----- Area methods -----\n";

    assert(isEquals(A.area()) && isEquals(E.area()));
    assert(isEquals(B.area(), 144));
    assert(isEquals(D.area(), 10000*C.area()) && isEquals(D.area(), 100));

    std::cout << "Success\n\n";

    // Test center methods
    std::cout << "----- Center methods -----\n";

    assert(isEquals(A.center().x) && isEquals(A.center().y));
    assert(isEquals(E.center().x, 12) && isEquals(E.center().y, 15));
    assert(isEquals(B.center().x, 6) && isEquals(B.center().y));
    assert(isEquals(C.center().x, -0.05) && isEquals(C.center().y, -0.05));
    assert(isEquals(D.center().x) && isEquals(D.center().y));

    std::cout << "Success\n\n";

    // Test translate methods
    std::cout << "----- Translate methods -----\n";

    A.translate(Point(12,10));
    assert(isEquals(A.A.x, 12) && isEquals(A.A.y, 10) && isEquals(A.C.x, 12) && isEquals(A.C.y, 10));

    B.translate(Point());    
    assert(isEquals(B.A.x, 12) && isEquals(B.A.y, 6) && isEquals(B.C.x) && isEquals(B.C.y, -6));
    
    D.translate(Point(5, -5));
    assert(isEquals(D.A.x) && isEquals(D.A.y) && isEquals(D.C.x, 10) && isEquals(D.C.y, -10));

    std::cout << "Success\n\n";
    
    // Test resize methods
    std::cout << "----- Resize methods -----\n";
    
    A.resize(10000);
    assert(isEquals(A.center().x, 12) && isEquals(A.center().y, 10) && isEquals(A.side()));
    
    B.resize(3);
    assert(isEquals(B.center().x, 6) && isEquals(B.center().y) && isEquals(B.side(), 36));
    
    D.resize(1);
    assert(isEquals(D.center().x, 5) && isEquals(D.center().y, -5) && isEquals(D.side(), 10));
    
    D.resize(0);
    assert(isEquals(D.center().x, 5) && isEquals(D.center().y, -5) && isEquals(D.side()));
    
    C.resize(-1);
    assert(isEquals(C.center().x, -0.05) && isEquals(C.center().y, -0.05) && isEquals(C.side(), 0.1));
    
    std::cout << "Success\n\n";
    
    // Test rotate methods
    std::cout << "----- Rotate methods -----\n";
    
    A = Square(Point(), Point(10,10));
    B = Square(Point(-2, 5), Point(12, 5));
    C = Square(Point(), Point());
    
    A.rotate(45);
    assert(abs(A.A.x - 5) <= epsilon && abs(A.A.y+2.071) <= epsilon && A.C.x <= epsilon && abs(A.C.y-12.071) <= epsilon && abs(A.center().x -5) <= epsilon && abs(A.center().y-5) <= epsilon);
    
    B.rotate(90);
    assert(abs(B.A.x -5) <= epsilon && abs(B.A.y +2) <= epsilon && abs(B.C.x - 5) <= epsilon && abs(B.C.y + 12) <= epsilon && abs(B.center().x -5) <= epsilon && abs(B.center().y-5) <= epsilon);
    
    C.rotate(1);
    assert(abs(C.A.x) <= epsilon && abs(C.A.y) <= epsilon && abs(C.C.x - 5) <= epsilon && abs(C.C.y) <= epsilon && abs(C.center().x) <= epsilon && abs(C.center().y) <= epsilon);
    
    B.rotate(0);
    assert(abs(B.A.x -5) <= epsilon && abs(B.A.y + 2) <= epsilon && abs(B.C.x - 5) <= epsilon && abs(B.C.y + 12) <= epsilon && abs(B.center().x-5) <= epsilon && abs(B.center().y-5) <= epsilon);
    
    B.rotate(360);
    assert(abs(B.A.x -5) <= epsilon && abs(B.A.y + 2) <= epsilon && abs(B.C.x - 5) <= epsilon && abs(B.C.y + 12) <= epsilon && abs(B.center().x-5) <= epsilon && abs(B.center().y-5) <= epsilon);
    
    std::cout << "Success\n\n";

    // Test equals methods
    std::cout << "----- Equals methods -----\n";

    assert(A.equals(E));
    assert(!C.equals(D));
    
    std::cout << "Success\n\n";
    
    // Test inscribedCircle methods
    std::cout << "----- InscribedCircle methods -----\n";
    
    assert(C.inscribedCircle().equals(Circle(0, Point())) && C.inscribedCircle().center.x == 0 && C.inscribedCircle().center.y == 0);
    assert(B.inscribedCircle().equals(Circle((7*sqrt(2))/2, Point(5, 5))) && B.inscribedCircle().center.x == 5 && B.inscribedCircle().center.y == 5);

    std::cout << "Success\n\n";

    // Test circumscribedCircle methods
    std::cout << "----- CircumscribedCircle methods -----\n";

    assert(C.circumscribedCircle().equals(Circle(0, Point())) && C.circumscribedCircle().center.x == 0 && C.circumscribedCircle().center.y == 0);
    assert(B.circumscribedCircle().equals(Circle(7, Point(5, 5))) && B.circumscribedCircle().center.x == 5 && B.circumscribedCircle().center.y == 5);

    std::cout << "Success\n\n";
}