#include <iostream>
#include <string>
using namespace std;

struct Student {
    string* namePtr;
    int* agePtr;
    double* gradePtr;

    Student() {
        namePtr = new string;
        agePtr = new int;
        gradePtr = new double;
    }

    ~Student() {
        delete namePtr;
        delete agePtr;
        delete gradePtr;
    }

    void printStudentInfo() {
        cout << "\nName: " << *namePtr;
        cout << "\nAge: " << *agePtr;
        cout << "\nGrade: " << *gradePtr;
    }
};

int main() {
    Student* student1 = new Student();

    *student1->namePtr = "Adrian Tan";
    *student1->agePtr = 19;
    *student1->gradePtr = 4.5;

    student1->printStudentInfo();

    delete student1;
    return 0;
}
