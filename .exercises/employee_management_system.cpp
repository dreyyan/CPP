#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
using namespace std;
// CC 203 - Seatwork #1
static unsigned int employee_count = 1;
// BASE CLASS
class Employee {
private: // Explicit call
    // ATTRIBUTES
    unique_ptr<string> name, birthday, contact_number, schedule;
    char gender;
    unsigned int age;
    bool is_available;
public:
    // PARAMETERIZED CONSTRUCTOR
    Employee(
        unique_ptr<string> name,
        char gender,
        unsigned int age,
        unique_ptr<string> birthday,
        unique_ptr<string> contact_number,
        bool is_available)
    : name(move(name)),
    gender(gender), age(age),
    birthday(move(birthday)),
    contact_number(move(contact_number)),
    is_available(1)
    { cout << "Welcome, " << *(this->name) << ".\n"; } // Called when object is created

    // UTILITY FUNCTION
    void display_format(size_t length) {
        for (size_t i = 0; i < length; ++i) {
            cout << '-';
        } cout << '\n';
    }

    // METHODS
    void display_employee_details() {
        cout << setw(7) << ' ' << "[ EMPLOYEE DETAILS ]\n";
        display_format(34);
        cout << setw(10) << ' ' << "Employee #" << employee_count++ << '\n';
        cout << setw(16) << "Name: " << *(this->name) << '\n';
        cout << setw(16) << "Gender: " << this->gender << '\n';
        cout << setw(16) << "Age: " << (this->age) << '\n';
        cout << setw(16) << "Birthday: " << *(this->birthday) << '\n';
        cout << setw(16) << "Contact No.: " << *(this->contact_number) << '\n';
        cout << setw(16) << "Available?: " << (this->is_available ? "Yes" : "No") << '\n';
        display_format(34);
    }

    void display_schedule() {
        cout << "displaying schedule...\n";
    }

    void display_employee_menu() {
        cout << "displaying employee menu...\n";
    }
};

// DERIVED CLASSES: Day/Night Shift Employees [TBE]
class DayShiftEmployee : public Employee {
public:
};

class NightShiftEmployee : public Employee {
};

int main() {
    // Create an instance of a class(Object)
    unique_ptr<Employee> employee1 = make_unique<Employee>(
        make_unique<string>("Adrian Dominic Tan"),
        'M',
        19,
        make_unique<string>("07/29/2005"),
        make_unique<string>("09502271059"),
        1
        );
    unique_ptr<Employee> employee2 = make_unique<Employee>(
    make_unique<string>("Clayton Caballero"),
    'M',
    19,
    make_unique<string>("12/28/2005"),
    make_unique<string>("09544970119"),
    1
    );
    cout << "\n  [ EMPLOYEE MANAGEMENT SYSTEM ]\n";

    // Invoke methods using objects of created class
    employee1->display_employee_details();
    employee2->display_employee_details();
    getc(stdin);
    return 0;
}