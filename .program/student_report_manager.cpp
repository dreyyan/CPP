#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void error_message(std::string message) {
    std::cerr << "ERROR: " << message << ".\n";
}

class Student {
    // Attributes
    std::string name;
    int id;
    float grade;
public:
    // Default constructor
    Student() {}

    // Parameterized constructor
    Student(std::string name, int id, float grade)
    : name(name), id(id), grade(grade) {}

    // Getters
    std::string getName() const { return name; }
    int getId() const { return id; }
    float getGrade() const { return grade; }

    // Setters
    void setName(std::string new_name) { name = new_name; }
    void setId(int new_id) { id = new_id; }
    void setGrade(float new_grade) { grade = new_grade; }

    // Methods

};

class StudentList {
std::vector<Student*> student_list;
public:
    // Default constructor
    StudentList() {}

    // Methods
    void addStudent(Student* student) {
        // Check if student already exists in the list
        auto it = std::find_if(student_list.begin(), student_list.end(),
        [student](Student* s) { return s->getId() == student->getId(); });

        // ERROR: Already existing student
        if (it != student_list.end()) {
            error_message("Student already exists");
            return;
        } else student_list.push_back(student); // else, add student to the list
        std::cout << "* '" << student->getName() << "' added to the list!\n";
    }

    void removeStudent(int student_id) {
        // Check if student exists in the list using student ID
        auto it = std::find_if(student_list.begin(), student_list.end(),
        [student_id](Student* student) { return student->getId() == student_id; });

        // ERROR: Already existing student
        if (it == student_list.end()) {
            error_message("Student does not exist");
            return;
        } else std::cout << "* '" << (*it)->getName() << "' removed from the list...\n";
        student_list.erase(it); // else, add student to the list
        delete *it; // Free allocated memory
    }

    void displayStudentList() const {
        std::cout << "[ STUDENT LIST ]\n";
        for (int i = 0; i < student_list.size(); ++i) {
            std::cout << i + 1 << ". " << student_list[i]->getName() << '\n';
        }
    }
};

int main() {
    StudentList section1;
    section1.addStudent(new Student("Jeffrey Williams", 101, 96.9));
    section1.addStudent(new Student("Jeffrey Williams", 101, 96.9));
    section1.removeStudent(102);
    section1.removeStudent(101);
    section1.addStudent(new Student("Adrian Dominic Tan", 102, 94.3));
    section1.addStudent(new Student("Khryss Nicole Bermejo", 103, 98.1));
    section1.displayStudentList();
    return 0;
}