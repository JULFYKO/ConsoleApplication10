#include <iostream>
using std::cout;
using std::endl;
class Circle {
protected:
    double radius;

public:
    Circle(double r = 1.0) : radius(r) {}
    double square() const {
        return 3.14159 * radius * radius;
    }
    double length() const {
        return 2 * 3.14159 * radius;
    }
    void setRadius(double r) {
        radius = r;
    }
    double getRadius() const {
        return radius;
    }
};

class Square {
protected:
    double side;

public:
    Square(double s = 1.0) : side(s) {}

    double square() const {
        return side * side;
    }
    double length() const {
        return 4 * side;
    }
    void setSide(double s) {
        side = s;
    }
    double getSide() const {
        return side;
    }
};

class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(double r) : Circle(r), Square(r * 1.414) {}

    void setRadius(double r) {
        Circle::setRadius(r);
        Square::setSide(r * 1.414);
    }

    void setSide(double s) {
        Square::setSide(s);
        Circle::setRadius(s / 1.414);
    }

    double totalLength() const {
        return Circle::length() + Square::length();
    }

    double areaDifference() const {
        return Square::square() - Circle::square();
    }
};

int main() {
    CircleInSquare shape(5.0);

    cout << "Radius: " << shape.getRadius() << endl;
    cout << "Side: " << shape.getSide() << endl;
    cout << "Circle Area: " << shape.Circle::square() << endl;
    cout << "Square Area: " << shape.Square::square() << endl;
    cout << "Total Length: " << shape.totalLength() << endl;
    cout << "Area Difference: " << shape.areaDifference() << endl;

    shape.setRadius(7.0);
    cout << "\nradius = 7.0:" << endl;
    cout << "Radius: " << shape.getRadius() << endl;
    cout << "Side: " << shape.getSide() << endl;

    shape.setSide(10.0);
    cout << "\nside = 10.0:" << endl;
    cout << "Radius: " << shape.getRadius() << endl;
    cout << "Side: " << shape.getSide() << endl;

    return 0;
}
