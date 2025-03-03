#include <iostream>
#include <limits>
#include <string>
using namespace std;
// CC 203 - Seatwork #2
class Student {
    string name;
    int age;
    float grade;
public:
    Student(string name, int age, float grade)
        : name("N/A"), age(0), grade(0.00) {}

    void setStudentInfo() {
        cout << "Setting student info...\n";
        string input_name;
        int input_age;
        float input_grade;

        while (true) {
            cout << "Enter Name: ";
            getline(cin, input_name);

            if (input_name == " ") {
                cout << "[ ERROR | Name cannot be blank ]\n";
            } else break;
        }

            cout << "Enter Age: ";
            cin >> input_age;

        while (true) {
            cout << "Enter grade: ";
            cin >> input_grade;

            if (cin.fail() || grade < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid grade ]\n";
            } else break;
        }

        name = input_name;
        age = input_age;
        grade = input_grade;
    }

    void displayStudentInfo() {
        cout << "[ STUDENT INFORMATION ]\n";
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "Grade: " << grade << '\n';
    }
};

int main() {
    Student student1("", 0, 0.00);
    student1.displayStudentInfo();
    student1.setStudentInfo();
    student1.displayStudentInfo();
    return 0;
}
