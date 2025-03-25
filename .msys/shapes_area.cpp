#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual void area() = 0;

};

class Circle : public Shape {
private:
    double radius;
    double areaOfCircle;

public:
    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    void area() override {
        areaOfCircle = M_PI * pow(radius, 2);
        cout << "Area of Circle: " << areaOfCircle;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
    double areaOfRectangle;

public:
    void setWidth(double w) {
        width = w;
    }

    void setLength(double l) {
        length = l;
    }

    double getWidth() const {
        return width;
    }

    double getLength() const {
        return length;
    }

    void area() override {
        areaOfRectangle = length * width;
        cout << "Area of Rectangle: " << areaOfRectangle;
    }
};

int main() {
    Rectangle *rectangle1 = new Rectangle();
    rectangle1->setWidth(10.5);
    rectangle1->setLength(5.5);
    rectangle1->area();
    delete rectangle1;
    return 0;
}
