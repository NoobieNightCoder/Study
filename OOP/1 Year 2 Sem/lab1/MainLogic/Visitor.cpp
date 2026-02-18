#include "Visitor.h"
#include <iostream>
#include <vector>

using namespace std;

/*  GET PERIMETERs   */
void PrintVisitor::getPerimeter(const Circle &c) {
    cout << index++ << ". " << c.getName() << " (Circle)\t|\tPerimeter: " << c.perimeter() << endl;
}
void PrintVisitor::getPerimeter(const Rectangle &r) {
    cout << index++ << ". " << r.getName() << " (Rectangle)\t|\tPerimeter: " << r.perimeter() << endl;
}
void PrintVisitor::getPerimeter(const Triangle &t) {
    cout << index++ << ". " << t.getName() << " (Triangle)\t|\tPerimeter: " << t.perimeter() << endl;
}

/*  GET PARAMETERS   */
void PrintVisitor::getParams(const Circle &c) {
    Point centre = c.getCenter();
    cout << index++ << ". " << c.getName() << " (Circle)\t|\tRadius: "
    << c.getRadius() << "\t|\tCentre: (" << centre.getX() << ";" << centre.getY() << ")" << endl;
}
void PrintVisitor::getParams(const Rectangle &r) {
    vector<Point> vertices(4);
    vertices = r.getVertices();
    cout << index++ << ". " << r.getName() << " (Rectangle)\t|\tVertices: (" << vertices[0].getX() << ";" << vertices[0].getY() << ") ("
    << vertices[1].getX() << ";" << vertices[1].getY() << ") (" << vertices[2].getX() << ";" << vertices[2].getY() << ") ("
    << vertices[3].getX() << ";" << vertices[3].getY() << ")" << endl;
}
void PrintVisitor::getParams(const Triangle &t) {
    vector<Point> vertices(3);
    vertices = t.getVertices();
    cout << index++ << ". " << t.getName() << " (Triangle)\t|\tVertices: (" << vertices[0].getX() << ";" << vertices[0].getY() << ") ("
    << vertices[1].getX() << ";" << vertices[1].getY() << ") (" << vertices[2].getX() << ";" << vertices[2].getY() << ")" << endl;
}