#include <iostream>
#include <string>
using namespace std;
// CC 203: Lab Exercise #3
// [#2] Person class : inheritance
class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {} // Default Constructor
    virtual void displayInfo() = 0; // Pure virtual function
};

class Student : public Person {
protected:
    string studentID;
    double grades[3];
public:
    Student(string name, int age, string studentID, double grades[])
        : Person(name, age), studentID(studentID) {
        for (int i = 0; i < 3; i++) { this->grades[i] = grades[i]; }
        }

    double calculateAverage() {
        double average;
        double sum = 0;

        for (int i = 0; i < 3; ++i) {
            sum += grades[i];
        }

        average = sum / 3;
        return average;
    }

    void displayInfo() override {
        cout << "[ STUDENT INFORMATION ]\n";
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "ID: " << studentID << '\n';
        cout << "Average: " << calculateAverage() << '\n';
    }
};

class Teacher : public Person {
protected:
    string teacherID, subject;
public:
    Teacher(string name, int age, string teacherID, string subject)
        : Person(name, age), teacherID(teacherID), subject(subject) {}
    void displayInfo() override {
        cout << "[ TEACHER INFORMATION ]\n";
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "ID: " << teacherID << '\n';
        cout << "Subject: " << subject << '\n';
    }
};

int main() {
    double grades[] = {2.5, 3.5, 1.5};
    Teacher teacher("Mr. Stevensons", 31, "123498756", "English");
    Student student("Willis Wallace", 19, "123498756", grades);
    student.displayInfo();
    teacher.displayInfo();
    return 0;
}
