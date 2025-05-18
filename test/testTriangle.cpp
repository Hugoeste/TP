#define _USE_MATH_DEFINES

#include "point.hpp"
#include "shapes.hpp"
#include "include/test.hpp"
#include "include/compareDouble.hpp"
#include <assert.h>
#include <iostream>
#include <cmath>

void testTriangle() {
    std::cout << "Start Test for triangle class : \n\n";

    // Define triangle for tests
    Triangle A = Triangle(Point(), Point(), Point()); // Nul
    Triangle B = Triangle(Point(), Point(4, 0), Point(2, 3)); // isocele
    Triangle C = Triangle(Point(), Point(4, 0), Point(0, 3)); // rectangle
    Triangle D = Triangle(Point(), Point(2, 0), Point(1, sqrt(3))); // equilateral
    Triangle E = Triangle(Point(), Point(2, 0), Point(0, 2)); // isocele rectangle
    Triangle F = Triangle(Point(), Point(3, 1), Point(1, 4)); // quelconque
    Triangle G = Triangle(Point(10, 0), Point(14, 0), Point(12, 3)); // isocele

    // Test perimeter methods
    std::cout << "  - perimeter methods : \n";

    assert(abs(A.perimeter()) <= epsilon);
    assert(abs(B.perimeter() - G.perimeter()) <= epsilon && abs(B.perimeter() - (4+2*sqrt(13))) <= epsilon);
    assert(abs(C.perimeter() -12) <= epsilon);
    assert(abs(D.perimeter() -6) <= epsilon);
    assert(abs(E.perimeter() - (4+2*sqrt(2))) <= epsilon);
    assert(abs(F.perimeter()-sqrt(10)-sqrt(13)-sqrt(17)) <= epsilon);

    std::cout << "Success\n\n";

    // Test area methods
    std::cout << "  - area methods : \n";

    assert(abs(A.area()) <= epsilon);
    assert(abs(B.area()-G.area()) <= epsilon && abs(B.area() -6) <= epsilon);
    assert(abs(C.area()-6) <= epsilon);
    assert(abs(D.area()-sqrt(3)) <= epsilon);
    assert(abs(E.area()-2) <= epsilon);
    assert(abs(F.area()-11/2) <= epsilon);

    std::cout << "Success\n\n";

    // Test center methods
    std::cout << "  - center methods : \n";

    assert(abs(A.center().x) <= epsilon && abs(A.center().y) <= epsilon);
    assert(abs(B.center().x-2) <= epsilon && abs(B.center().y-1) <= epsilon);
    assert(abs(C.center().x-4/3) <= epsilon && abs(C.center().y-1) <= epsilon);
    assert(abs(D.center().x-1) <= epsilon && abs(D.center().y-sqrt(3)/3) <= epsilon);
    assert(abs(E.center().x-2/3) <= epsilon && abs(E.center().y-2/3) <= epsilon);
    assert(abs(F.center().x-4/3) <= epsilon && abs(F.center().y-5/3) <= epsilon);

    std::cout << "Success\n\n";

    // Test translate methods
    std::cout << "  - translate methods : \n";

    A.translate(Point());
    assert(A.center().x == 0 && A.center().y == 0 && A.area() == 0);

    F.translate(Point(10, -5));
    assert(F.center().x == 34/3 && F.center().y == 35/3 && F.area() == 11/2);

    std::cout << "Success\n\n";

    // Test resize methods
    std::cout << "  - resize methods : \n";

    F.translate(Point(-10, 5));
    
    A.resize(1);
    assert(A.center().x == 0 && A.center().y == 0 && A.area() == 0);

    F.resize(4);
    assert(F.center().x == 34/3 && F.center().y == 35/3 && F.area() == 22);

    B.resize(1);
    assert(B.center().x == 2 && B.center().y == 1 && B.area() == 6);

    C.resize(0);
    assert(C.center().x == 4/3 && C.center().y == 1 && C.area() == 0);

    std::cout << "Success\n\n";

    // Test rotate methods
    std::cout << "  - rotate methods : \n";

    C = Triangle(Point(), Point(4, 0), Point(0, 3));
    F = Triangle(Point(), Point(3, 1), Point(1, 4));

    std::cout << "Success\n\n";

    // Test equals methods
    std::cout << "  - equals methods : \n";

    assert(!A.equals(C));
    assert(A.equals(Triangle(Point(4, 3), Point(4, 3), Point(4, 3))));
    assert(B.equals(G));

    std::cout << "Success\n\n";

    // Test isRightAngled methods
    std::cout << "  - isRighAngled methods : \n";

    assert(!A.isRightAngled());
    assert(!B.isRightAngled());
    assert(C.isRightAngled());
    assert(E.isRightAngled());
    assert(!F.isRightAngled());

    std::cout << "Success\n\n";

    // Test isEquilateral methods
    std::cout << "  - isEquilateral methods : \n";

    assert(!A.isEquilateral());
    assert(!C.isEquilateral());
    assert(D.isEquilateral());
    assert(!F.isEquilateral());

    std::cout << "Success\n\n";

    // Test isIsoceles methods
    std::cout << "  - isIsoceles methods : \n";

    assert(!A.isIsoceles());
    assert(B.isIsoceles());
    assert(!C.isIsoceles());
    assert(E.isIsoceles());
    assert(!F.isIsoceles());
    assert(G.isIsoceles());

    std::cout << "Success\n\n";

    // Test inscribedCircle
    std::cout << "  - inscribedCircle methods : \n";

    assert(A.inscribedCircle().equals(Circle(0, Point())) && A.inscribedCircle().center.x == 0 && A.inscribedCircle().center.y == 0);
    assert(B.inscribedCircle().equals(Circle(1, Point(2, 1))) && B.inscribedCircle().center.x == 2 && B.inscribedCircle().center.y == 1);
    assert(C.inscribedCircle().equals(Circle(1, Point(1, 1))) && C.inscribedCircle().center.x == 1 && C.inscribedCircle().center.y == 1);
    assert(E.inscribedCircle().equals(Circle(1-sqrt(2)/3, Point(1.39, 1.41))) && abs(E.inscribedCircle().center.x-0.2929) == epsilon && abs(E.inscribedCircle().center.y-0.2929) == epsilon);
    assert(abs(F.inscribedCircle().radius-1.01) <= epsilon && abs(E.inscribedCircle().center.x-1.39) == epsilon && abs(E.inscribedCircle().center.y-1.41) == epsilon);

    std::cout << "Success\n\n";

    // Test circumscribedCircle
    std::cout << "  - circumscribedCircle methods : \n";

    assert(A.circumscribedCircle().equals(Circle(0, Point())) && A.circumscribedCircle().center.x == 0 && A.circumscribedCircle().center.y == 0);
    assert(B.circumscribedCircle().equals(Circle(2.5, Point(2, 1.25))) && B.circumscribedCircle().center.x == 0 && B.circumscribedCircle().center.y == 0);
    assert(C.circumscribedCircle().equals(Circle(2.5, Point(2, 1.5))) && C.circumscribedCircle().center.x == 0 && C.circumscribedCircle().center.y == 0);
    assert(E.circumscribedCircle().equals(Circle(sqrt(2), Point(1, 1))) && E.circumscribedCircle().center.x == 1 && E.circumscribedCircle().center.y == 1);
    assert(abs(F.circumscribedCircle().radius-2.28) <= epsilon && abs(E.circumscribedCircle().center.x-1.56) == epsilon && abs(E.circumscribedCircle().center.y-1.31) == epsilon);

    std::cout << "Success\n\n";
}