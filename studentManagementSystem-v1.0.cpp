#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Person > Student/Instructor
//

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
};

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
};

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

int main() {
    /*Student* s1 = new Student("Adrian Dominic L. Tan", "117591120149", 'M', "07/29/2005", "adriandominic.tan@wvsu.edu.ph", "Arevalo, Iloilo City", "09502271058");
    Instructor* i1 = new Instructor("Walter Hartwell White", 'M', "09/07/1958", "walterhartwell.white@wvsu.edu.ph", "3828 Piermont Dr, Albuquerque, NM.", "555-1258");*/
    Department* d1 = new Department("CICT");
    Course* c1 = new Course(d1, "BSCS");
    Course *c2 = new Course(d1, "BSIT");
    Course *c3 = new Course(d1, "BSIS");
    Course *c4 = new Course(d1, "BLIS");
    d1->printCourseList();
    return 0;
}