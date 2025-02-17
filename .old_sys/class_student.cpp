#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Student {
private:
    string studentName;
    vector<double> studentGrades;
    int gradesToEnter;
    double grade;
    double sumGrade = 0;
    double average;

public:
    Student(string studentName, vector<double> studentGrades = {})
        : studentName(studentName), studentGrades(studentGrades) {
        cout << "Student added successfully!";
        cout << "\nName: " << studentName;

        // Print Student Grades in Constructor
        cout << "\n| Grades |\nNone";
    }


    void addGrades() {
        cout << "\n# of Grades to Enter: ";
        cin >> gradesToEnter;

        for (int i = 0; i < gradesToEnter; i++) {
            cout << "Enter Grade #" << i + 1 << ": ";
            cin >> grade;
            studentGrades.push_back(grade);
        }

            cout << "Grades Successfully Updated!";

            cout << "\n| Grades |";
            for (int i = 0; i < studentGrades.size(); i++) {
                cout << "\nGrade #" << i + 1 << ": ";
                cout << fixed << setprecision(2) << studentGrades[i] << " ";
            }
    }

    void averageGrade() {
        for (int i = 0; i < studentGrades.size(); i++) {
            sumGrade += studentGrades[i];
        }

        average = sumGrade / studentGrades.size();
        cout << "\nAverage Grade: " << average;
    }

    void displayGrade() {
        cout << "\nName: " << studentName;
        cout << "\n| Grades |";
        for (int i = 0; i < studentGrades.size(); i++) {
            cout << "\nGrade #" << i + 1 << ": ";
            cout << fixed << setprecision(2) << studentGrades[i] << " ";
        }
    }
};

int main() {
    Student student1 = {"Adrian Tan", {}};
    student1.addGrades();
    student1.averageGrade();
    student1.displayGrade();
    return 0;
}