#include <iostream>
#include <string>

class Rectangle {
public:
	
	Rectangle() {}
	
	void setDimension() {
		std::cout << "Set Length: ";
		std::cin >> length;
		std::cout << "Set Width: ";
		std::cin >> width;
	}
	
	double areaRectangle() {
		double area = length * width;
		std::cout << "Area: " << area;
		return area;
	}
	
private:
	double length;
	double width;
};

int main() {

	Rectangle rectangle1;
	
	rectangle1.setDimension();
	rectangle1.areaRectangle();


	return 0;
}
