#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

// TO IMPROVE:
// class CourseManager;
// studentList;
// instructorList;
// case 3 & 4

// Person > Student/Instructor
// Department
// Course
// Course Manager

// Base Class
class Person {
protected:
    string name, dateOfBirth, email, address, contactNumber;
    char gender;
public:
    Person(string personName, char personGender, string personDateOfBirth, string personEmail, string personAddress, string personContactNumber)
        : name(personName), gender(personGender), dateOfBirth(personDateOfBirth), email(personEmail), address(personAddress), contactNumber(personContactNumber) {}
};

// Derived Class
class Student : public Person {
protected:
    string id;
public:
    Student(string studentName, string studentId, char studentGender, string studentDateOfBirth, string studentEmail, string studentAddress, string studentContactNumber)
        : Person(studentName, studentGender, studentDateOfBirth, studentEmail, studentAddress, studentContactNumber), id(studentId) {
        cout << "\n>>>> Student Added";
        cout << "\n--------------------------------------------";
        cout << "\nSTUDENT INFORMATION |";
        cout << "\nFull Name: " << name;
        cout << "\nID: " << id;
        cout << "\nGender(M/F): " << gender;
        cout << "\nDate of Birth(MM/DD/YYYY): " << dateOfBirth;
        cout << "\nEmail Address: " << email;
        cout << "\nAddress: " << address;
        cout << "\nContact No.: " << contactNumber;
        cout << "\n--------------------------------------------";
    }

    void displayInfo() {
        cout << "\n--------------------------------------------";
        cout << "\nSTUDENT INFORMATION |";
        cout << "\nFull Name: " << name;
        cout << "\nID: " << id;
        cout << "\nGender(M/F): " << gender;
        cout << "\nDate of Birth(MM/DD/YYYY): " << dateOfBirth;
        cout << "\nEmail Address: " << email;
        cout << "\nAddress: " << address;
        cout << "\nContact No.: " << contactNumber;
        cout << "\n--------------------------------------------";
    }
};

list<Student> studentList;

// Derived Class
class Instructor : public Person {
protected:

public:
    Instructor(string instructorName, char instructorGender, string instructorDateOfBirth, string instructorEmail, string instructorAddress, string instructorContactNumber)
    : Person(instructorName, instructorGender, instructorDateOfBirth, instructorEmail, instructorAddress, instructorContactNumber) {
        cout << "\n>>>> Instructor Added";
        cout << "\n--------------------------------------------";
        cout << "\nINSTRUCTOR INFORMATION |";
        cout << "\nFull Name: " << name;
        cout << "\nGender(M/F): " << gender;
        cout << "\nDate of Birth(MM/DD/YYYY): " << dateOfBirth;
        cout << "\nEmail Address: " << email;
        cout << "\nAddress: " << address;
        cout << "\nContact No.: " << contactNumber;
        cout << "\n--------------------------------------------";
    }

    void displayInfo() {
        cout << "\n--------------------------------------------";
        cout << "\nINSTRUCTOR INFORMATION |";
        cout << "\nFull Name: " << name;
        cout << "\nGender(M/F): " << gender;
        cout << "\nDate of Birth(MM/DD/YYYY): " << dateOfBirth;
        cout << "\nEmail Address: " << email;
        cout << "\nAddress: " << address;
        cout << "\nContact No.: " << contactNumber;
        cout << "\n--------------------------------------------";
    }

};

list<Instructor> instructorList;

class Department {
protected:
    string departmentName;
    vector<string> courseList;
public:
    Department(string departmentName)
        : departmentName(departmentName) {
        cout << "\n>>>> Department Created";
        cout << "\nDepartment: " << departmentName;
    }

    void addCourse(const string& courseName) {
        courseList.push_back(courseName);
    }

    void printCourseList() {
        cout << "\nCourses in " << departmentName << " Department:\n";
        for (int i = 0; i < courseList.size(); i++) {
            cout << i + 1 << ". " << courseList[i] << "\n";
        }
    }
};

class Course {
protected:
    string courseName;
    Department* department;
public:
    Course(Department* department, string courseName)
        : department(department), courseName(courseName) {
        department->addCourse(courseName);
        cout << "\n>>> Course Created";
            cout << "\nCourse: " << courseName;
    }
};

class CourseManager {
protected:

public:
};

void loopMenu() {
    int choice;

    cout << "\n| STUDENT MANAGEMENT SYSTEM |";
    cout << "\n[1] | Add Student";
    cout << "\n[2] | Add Instructor";
    cout << "\n[3] | Add Department";
    cout << "\n[4] | Add Course";
    cout << "\n[5] | Exit";
    cout << "\nEnter Number: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string name, id, dateOfBirth, email, address, contactNumber;
            char gender;

            cin.ignore();
            cout << "\nSTUDENT INFORMATION |";
            cout << "\nFull Name: ";
            getline(cin, name);
            cout << "\nID: " << id;
            getline(cin, id);
            cout << "\nGender(M/F): ";
            cin >> gender;
            cin.ignore();
            cout << "\nDate of Birth(MM/DD/YYYY): ";
            getline(cin, dateOfBirth);
            cout << "\nEmail Address: ";
            getline(cin, email);
            cout << "\nAddress: ";
            getline(cin, address);
            cout << "\nContact No.: ";
            getline(cin, contactNumber);

            Student student(name, id, gender, dateOfBirth, email, address, contactNumber);
            ::studentList.push_back(student);
            student.displayInfo();
            break;
        }
        case 2: {
            string name, dateOfBirth, email, address, contactNumber;
            char gender;

            cin.ignore();
            cout << "\nINSTRUCTOR INFORMATION |";
            cout << "\nFull Name: ";
            getline(cin, name);
            cout << "\nGender(M/F): ";
            cin >> gender;
            cin.ignore();
            cout << "\nDate of Birth(MM/DD/YYYY): ";
            getline(cin, dateOfBirth);
            cout << "\nEmail Address: ";
            getline(cin, email);
            cout << "\nAddress: ";
            getline(cin, address);
            cout << "\nContact No.: ";
            getline(cin, contactNumber);

            Instructor instructor(name, gender, dateOfBirth, email, address, contactNumber);
            ::instructorList.push_back(instructor);
            break;
        }

        case 3: {

        }

        case 4: {

        }

        case 5:
            cout << "\nProgram exited successfully.";
            return;
        break;
    }
}

int main() {
    loopMenu();
    Department* d1 = new Department("CICT");
    Course* c1 = new Course(d1, "BSCS");
    Course* c2 = new Course(d1, "BSIT");
    Course* c3 = new Course(d1, "BSIS");
    Course* c4 = new Course(d1, "BLIS");
    d1->printCourseList();
    return 0;
}
