#include <iostream>
#include <string>

class Student {
public:
	Student(std::string cName = "", int cAge = 0, int cGrade = 0)
	: name(cName), age(cAge), grade(cGrade) {
		std::cout << "Welcome, " << name << ".\n";
		std::cout << "Your age is " << age << "\n";
		std::cout << "Current Grade: " << grade << "\n";
}
		~Student() {
		std::cout << "Goodbye, " << name << ".";
}
	
	void setDetails() {
		std::cout << "Enter your name: ";
		std::cin.ignore();
		getline(std::cin, name);
		std::cout << "Enter your age: ";
		std::cin >> age;
		std::cout << "Enter grade: ";
		std::cin >> grade;
	}	
	
private:
	std::string name;
	int age;
	int grade;
};

int main() {
	Student student1("Adrian Dominic Tan", 19, 98);

	return 0;
}
