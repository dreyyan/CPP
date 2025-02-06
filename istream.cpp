#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// istringstream - extracting values from a string
int main() {
    string name;
    int age;
    float height;
    bool is_student;
    string to_extract = "Adrian 19 1.54 1";
    istringstream iss(to_extract);

    iss >> name >> age >> height >> is_student;
    cout << "Name: " << name << '\n';
    cout << "Age: " << age << '\n';
    cout << "Height: " << height << '\n';
    cout << "Student: " << (is_student ? "Yes" : "No" ) << '\n';
    return 0;
}
