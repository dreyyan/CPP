#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string employeeName;
    double hourlyRate;
    int hoursWorked;

public:
    void inputEmployeeDetails() {
        cout << "Enter Name: ";
        getline(cin, employeeName);
        cout << "\nEnter rate/hr.: ";
        cin >> hourlyRate;
        cout << "\nEnter total hrs. Worked: ";
        cin >> hoursWorked;
    }

    void totalSalary() {
        double totalSalary = hourlyRate * hoursWorked;
        cout << "\nYour total salary is: $" << totalSalary << "\n";
    }

    void displayEmployeeDetails() {
        cout << "\nEmployee Created Successfully!";
        cout << "\nEmployee Name: " << employeeName;
        cout << "\nRate/hour: " << hourlyRate;
        cout << "\nTotal Hours Worked: " << hoursWorked << "\n";
    }
};

int main() {
    Employee emp1;
    emp1.inputEmployeeDetails();
    emp1.displayEmployeeDetails();
    emp1.totalSalary();
    return 0;
}
