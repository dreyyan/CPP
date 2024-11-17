#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string name = "Adrian Tan";
    int age = 19;
    float balance = 3.5;
    bool isStudent = true;

    ostringstream os;
    os << "Name: " << name << endl;
    os << "Age: " << age << endl;
    os << "Balance: " << balance << endl;
    os << "Student?: " << (isStudent ? "Yes" : "No") << endl;

    string output = os.str();
    cout << output;
    return 0;
}
