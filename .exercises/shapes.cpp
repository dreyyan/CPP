#include <iostream>
#include <string>
using namespace std;
// CC 203: Lab Exercise #3
// [#1] Shapes class : inheritance
class Shape {
protected:
    string color;
public:
    Shape(string color) : color(color) {}
    virtual void displayInfo() = 0; // Pure virtual function
};

class Circle : public Shape {
protected:
    double radius;
public:
    Circle(string color, double radius)
        : Shape(color), radius(radius) {}
    void displayInfo() override {
        cout << "Type: Circle\n";
        cout << "Color: " << color << '\n';
        cout << "Radius: " << radius << '\n';
    }
};

class Rectangle : public Shape {
protected:
    double length, width;
public:
    Rectangle(string color, double length, double width)
    : Shape(color), length(length), width(width) {}
    void displayInfo() override {
        cout << "Type: Rectangle\n";
        cout << "Color: " << color << '\n';
        cout << "Length: " << length << '\n';
        cout << "Width: " << width << '\n';
    }
};

int main() {
    Circle circle("Red", 3.5);
    Rectangle rectangle("Blue", 5.5, 4.5);
    circle.displayInfo();
    rectangle.displayInfo();
    return 0;
}
