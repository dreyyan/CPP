#include <iostream>
#include <string>
using namespace std;
// CC 203: Lab Exercise #2
// [#1] Student class
class Student {
    /* ATTRIBUTES */
    string name;
    int age;
    double gpa;
public:
    /* CONSTRUCTOR */
    Student() {} // Default Constructor
    /* METHODS */
    // Set student details
    void setData(string new_name, int new_age, double new_gpa) {
        name = new_name;
        age = new_age;
        gpa = new_gpa;
    }

    // Display student information
    void displayInfo() {
        cout << "[ STUDENT INFORMATION ]\n";
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "GPA: " << gpa << '\n';
    }
};

int main() {
    Student student; // Instantiate 'Student' object
    student.setData("Adrian", 19, 1.50); // Set data
    student.displayInfo(); // Display information
    return 0;
}
