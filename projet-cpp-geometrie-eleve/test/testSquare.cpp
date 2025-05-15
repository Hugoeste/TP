#define _USE_MATH_DEFINES

#include "point.hpp"
#include "shapes.hpp"
#include "include/test.hpp"
#include "include/compareDouble.hpp"
#include <assert.h>
#include <iostream>
#include <cmath>

void testSquare() {
    std::cout << "Start Test for Square class : \n\n";

    // Define square for tests
    Square A = Square(Point(), Point());
    Square B = Square(Point(12, 6), Point());
    Square C = Square(Point(-0.1, -0.1), Point());
    Square D = Square(Point(-5, 5), Point(5, -5));
    Square E = Square(Point(12, 15), Point(12, 15));

    Point center, P, R;
    double side;

    // Test side methods
    std::cout << "  - side methods : \n";

    assert(abs(A.side()) <= epsilon && abs(E.side()) <= epsilon);
    assert(abs(B.side() - sqrt(90)) <= epsilon);
    assert(abs(D.side() - 100*C.side()) <= epsilon && abs(D.side()-10) <= epsilon);

    std::cout << "Success\n\n";

    // Test perimeter methods
    std::cout << "  - perimeter methods : \n";

    assert(abs(A.perimeter()) <= epsilon && abs(E.perimeter()) <= epsilon);
    assert(abs(B.perimeter() - 4*sqrt(90)) <= epsilon);
    assert(abs(D.perimeter() - 100*C.perimeter()) <= epsilon && (D.perimeter() - 40) <= epsilon);

    std::cout << "Success\n\n";

    // Test area methods
    std::cout << "  - area methods : \n";

    assert(abs(A.area()) <= epsilon && abs(E.area()) <= epsilon);
    assert(abs(B.area() - 90) <= epsilon);
    assert(abs(D.area()-10000*C.area()) <= epsilon && abs(D.area() - 100) <= epsilon);

    std::cout << "Success\n\n";

    // Test center methods
    std::cout << "  - center methods : \n";

    assert(abs(A.center().x) <= epsilon && abs(A.center().y) <= epsilon);
    assert(abs(E.center().x-12) <= epsilon && abs(E.center().y-15) <= epsilon);
    assert(abs(B.center().x-6) <= epsilon && abs(B.center().y-3) <= epsilon);
    assert(abs(C.center().x+0.05) <= epsilon && abs(C.center().y+0.05) <= epsilon);
    assert(abs(D.center().x) <= epsilon && abs(D.center().y) <= epsilon);

    std::cout << "Success\n\n";

    // Test translate methods
    std::cout << "  - translate methods : \n";

    P = A.A;
    R = A.C;
    A.translate(Point(12,10));
    assert(abs(A.A.x - P.x+12) <= epsilon && abs(A.A.y - P.y+10) <= epsilon  && abs(A.C.x - R.x+12) <= epsilon && abs(A.C.y - R.y+10) <= epsilon);

    P = B.A;
    R = B.C;
    B.translate(Point());    
    assert(abs(B.A.x - P.x) <= epsilon && abs(B.A.y - P.y) <= epsilon && abs(B.C.x - R.x) <= epsilon && abs(B.C.y - R.y) <= epsilon);
    
    P = D.A;
    R = D.C;
    D.translate(Point(5, -5));
    assert(abs(D.A.x - P.x+5) <= epsilon && abs(D.A.y - P.y-5) <= epsilon && abs(D.C.x - R.x+5) <= epsilon && abs(D.C.y - R.y-5) <= epsilon);

    std::cout << "Success\n\n";
    
    // Test equals methods
    std::cout << "  - equals methods : \n";

    assert(A.equals(E));
    assert(!C.equals(D));
    
    std::cout << "Success\n\n";

    // Test resize methods
    std::cout << "  - resize methods : \n";

    center = A.center();
    A.resize(10000);
    std::cout << A.center().x << " \n" << A.center().y << " \n" << center.x << "\n" << center.y << "\n" << A.side() << "\n";
    assert(abs(A.center().x - center.x) <= epsilon && abs(A.center().y - center.y) <= epsilon  && abs(A.side() - 0) <= epsilon);
    
    center = B.center();
    B.resize(2);
    std::cout << B.A.x << " \n" << B.A.y << " \n" << B.C.x << "\n" << B.C.y << "\n" << B.side() << "\n";
    assert(abs(B.center().x - center.x) <= epsilon && abs(B.center().y - center.y) <= epsilon  && abs(B.side() - 2*sqrt(90)) <= epsilon);

    center = D.center();
    D.resize(1);
    assert(abs(D.center().x - center.x) <= epsilon && abs(D.center().y - center.y) <= epsilon  && abs(D.side() - 10) <= epsilon);

    center = D.center();
    D.resize(0);
    assert(abs(D.center().x - center.x) <= epsilon && abs(D.center().y - center.y) <= epsilon  && abs(D.side() - 0) <= epsilon);

    center = C.center();
    C.resize(-1);
    assert(abs(C.center().x - center.x) <= epsilon && abs(C.center().y - center.y) <= epsilon  && abs(C.side() - 0.1) <= epsilon);

    std::cout << "Success\n\n";

    // Test rotate methods
    std::cout << "  - rotate methods : \n";

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

    // Test inscribedCircle methods
    std::cout << "  - inscribedCircle methods : \n";

    assert(C.inscribedCircle().equals(Circle(0, Point())) && C.inscribedCircle().center.x == 0 && C.inscribedCircle().center.y == 0);
    assert(B.inscribedCircle().equals(Circle((7*sqrt(2))/2, Point(5, 5))) && B.inscribedCircle().center.x == 5 && B.inscribedCircle().center.y == 5);

    std::cout << "Success\n\n";

    // Test circumscribedCircle methods
    std::cout << "  - circumscribedCircle methods : \n";

    assert(C.circumscribedCircle().equals(Circle(0, Point())) && C.circumscribedCircle().center.x == 0 && C.circumscribedCircle().center.y == 0);
    assert(B.circumscribedCircle().equals(Circle(7, Point(5, 5))) && B.circumscribedCircle().center.x == 5 && B.circumscribedCircle().center.y == 5);

    std::cout << "Success\n\n";
}