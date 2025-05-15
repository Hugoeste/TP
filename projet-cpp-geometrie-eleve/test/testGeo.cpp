#define _USE_MATH_DEFINES

#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <assert.h>
#include <iostream>
#include <cmath>

// Epsilon for the precision of calculs 
double epsilon = 0.0001;

void testPoint() {
    std::cout << "Start Test for Points class : \n\n";

    // Define point for tests
    Point A = Point();
    Point B = Point(12,15);
    Point C = Point(2, 5);

    // Test distance methods
    std::cout << "  - distance methods : \n";

    assert(B.distance(A) - B.distance() <= epsilon && 3*sqrt(41) - B.distance() <= epsilon  && B.distance() - 3*sqrt(41) <= epsilon);
    assert(B.distance(C) - C.distance(B) <= epsilon);
    assert(10*sqrt(2) - B.distance(C) <= epsilon && B.distance(C) - 10*sqrt(2) <= epsilon);

    std::cout << "Success\n\n";
}
/*
void testCircle() {
    std::cout << "\n\nStart Test for Circle class : \n\n";

    //Define circle for tests
    Circle A = Circle(2, Point());
    Circle B = Circle(0, Point(12, 0));
    Circle C = Circle(2, Point(15, 7));
    Circle D = Circle(1, Point());
    Circle E = Circle(-2, Point());
    Circle F = Circle(2.5, Point(12,17));

    // Test circumference methods
    std::cout << "  - circumference methods : \n";

    assert(abs(A.circumference() - C.circumference()) <= epsilon && abs(A.circumference() - E.circumference()) <= epsilon && abs(A.circumference()-4*M_PI) <= epsilon);
    assert(abs(B.circumference()) <= epsilon);

    std::cout << "Success\n\n";

    // Test area methods
    std::cout << "  - area methods : \n";

    assert(abs(A.area() - C.area()) <= epsilon && abs(A.area() - E.area()) <= epsilon && abs(A.area()-4*M_PI) <= epsilon);
    assert(abs(B.area()) <= epsilon);

    std::cout << "Success\n\n";

    // Test translate methods
    std::cout << "  - translate methods : \n";

    A.translate(Point(12, 15));
    assert(A.center.x == 12 && A.center.y == 15 && A.radius == 2);

    B.translate(Point(-12, 0));
    assert(B.center.x == 0 && B.center.y == 0 && B.radius == 0);

    F.translate(Point());
    assert(F.center.x == 12 && F.center.y == 17 && F.radius == 2.5);

    std::cout << "Success\n\n";

    // Test equals methods (Faux car tes semblables)
    std::cout << "  - equals methods : \n";

    assert(A.equals(C));
    assert(!A.equals(B));
    assert(A.equals(E));

    std::cout << "Success\n\n";

    // Test resize methods
    std::cout << "  - resize methods : \n";

    A.resize(0.5);
    assert(A.equals(D) && A.center.x == 12 && A.center.y == 15);

    A.resize(-1);
    assert(A.equals(D) && A.center.x == 12 && A.center.y == 15);
    
    A.resize(1);
    assert(A.equals(D) && A.center.x == 12 && A.center.y == 15);
    
    B.resize(50);
    assert(B.equals(Circle(0, Point())) && B.center.x == 0 && B.center.y == 0);

    D.resize(2.5);
    assert(D.equals(F) && D.center.x == 0 && D.center.y == 0);

    C.resize(0);
    assert(C.equals(Circle(0, Point(15, 7))) && C.center.x == 15 && C.center.y == 7);

    std::cout << "Success\n\n";
}
*/
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
    assert(abs(B.A.x - P.x) <= epsilon && B.A.y <= epsilon P.y && B.C.x <= epsilon R.x && B.C.y <= epsilon R.y);
    
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
    assert(A.center().x == center.x && A.center().y == center.y && A.side() == 0);
    
    center = B.center();
    B.resize(2);
    std::cout << B.A.x << " \n" << B.A.y << " \n" << B.C.x << "\n" << B.C.y << "\n" << B.side() << "\n";
    assert(B.center().x == center.x && B.center().y == center.y && B.side() == 2*sqrt(90));

    center = D.center();
    D.resize(1);
    assert(D.center().x == center.x && D.center().y == center.y && D.side() == 10);

    center = D.center();
    D.resize(0);
    assert(D.center().x == center.x && D.center().y == center.y && D.side() == 0);

    center = C.center();
    C.resize(-1);
    assert(C.center().x == center.x && C.center().y == center.y && C.side() == 0.1);

    std::cout << "Success\n\n";

    // Test rotate methods
    std::cout << "  - rotate methods : \n";

    A = Square(Point(), Point(10,10));
    B = Square(Point(-2, 5), Point(12, 5));
    C = Square(Point(), Point());

    A.rotate(45);
    assert(A.A.x == 5 && abs(A.A.y+2.071) <= epsilon && A.C.x == 5 && abs(A.C.y-12.071) <= epsilon && A.center().x == 5 && A.center().y == 5);

    B.rotate(90);
    assert(B.A.x == 5 && B.A.y == -2 && B.C.x == 5 && B.C.y == 12 && B.center().x == 5 && B.center().y == 5);
    
    C.rotate(1);
    assert(C.A.x == 0 && C.A.y == 0 && C.C.x == 0 && C.C.y == 0 && C.center().x == 0 && C.center().y == 0);

    B.rotate(0);
    assert(B.A.x == 5 && B.A.y == -2 && B.C.x == 5 && B.C.y == 12 && B.center().x == 5 && B.center().y == 5);
    
    B.rotate(360);
    assert(B.A.x == 5 && B.A.y == -2 && B.C.x == 5 && B.C.y == 12 && B.center().x == 5 && B.center().y == 5);

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

void testTriangle() {
    std::cout << "Start Test for Points class : \n\n";

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

    assert(A.perimeter() == 0);
    assert(B.perimeter() == G.perimeter() && B.perimeter() == 12);
    assert(C.perimeter() == 12);
    assert(D.perimeter() == 6);
    assert(E.perimeter() == 4+2*sqrt(2));
    assert(F.perimeter()-sqrt(10)+sqrt(13)+sqrt(17) <= epsilon);

    std::cout << "Success\n\n";

    // Test area methods
    std::cout << "  - area methods : \n";

    assert(A.area() == 0);
    assert(B.area() == G.area() && B.area() == 6);
    assert(C.area() == 6);
    assert(D.area() == sqrt(3));
    assert(E.area() == 2);
    assert(F.area() == 11/2);

    std::cout << "Success\n\n";

    // Test center methods
    std::cout << "  - center methods : \n";

    assert(A.center().x == 0 && A.center().y == 0);
    assert(B.center().x == 2 && B.center().y == 1);
    assert(C.center().x == 4/3 && C.center().y == 1);
    assert(D.center().x == 1 && D.center().y == sqrt(3)/3);
    assert(E.center().x == 2/3 && E.center().y == 2/3);
    assert(F.center().x == 4/3 && F.center().y == 5/3);

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


int main() {
    testPoint();
   // testCircle();
    testSquare();
    testTriangle();

    return 0;
}