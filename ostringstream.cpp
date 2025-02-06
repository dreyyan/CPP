#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// ostringstream - outputting values into a single string
int main() {
    string name = "Adrian Dominic L. Tan";
    int age = 19;
    float height = 1.54;
    bool is_student = true;

    ostringstream oss;
    oss << "Name: " << name << '\n';
    oss << "Age: " << age << '\n';
    oss << "Height: " << height << '\n';
    oss << "Student: " << (is_student ? "Yes" : "No");

    string result = oss.str(); // Convert Object to String
    cout << result;
    return 0;
}
