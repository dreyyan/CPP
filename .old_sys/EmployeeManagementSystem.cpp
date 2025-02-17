#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    float salary;

public:
    Employee(string name, int id, float salary)
        : name(name), id(id), salary(salary) {}

    virtual void display() = 0;

    string getName() const {
        return name;
    }
    int getId() const {
        return id;
    }
    float getSalary() const {
        return salary;
    }
};

class FullTimeEmployee : public Employee {
private:
    string benefits;

public:
    FullTimeEmployee(string name, int id, float salary, string benefits = "")
        : Employee(name, id, salary), benefits(benefits) {}

    void display() {
        cout << "Employee Details: \n";
        cout << "Name: " << name;
        cout << "\nID: " << id;
        cout << "\nSalary: " << salary;
        cout << "\nBenefit/s: " << benefits << "\n";
    }

    void setBenefits() {
        cout << "Benefit/s: ";
        cin >> benefits;
        displayBenefits();
    }

    void displayBenefits() {
        cout << "Benefits updated.\n\n";
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;

public:
    PartTimeEmployee(string name, int id, float salary, int hoursWorked = 0)
        : Employee(name, id, salary), hoursWorked(hoursWorked) {}

    void display() {
        cout << "Employee Details: \n";
        cout << "Name: " << name;
        cout << "\nID: " << id;
        cout << "\nSalary: " << salary;
        cout << "\nHours Worked: " << hoursWorked << "\n";
    }

    void setHoursWorked() {
        cout << "How many hours did you work?: ";
        cin >> hoursWorked;
        displayHoursWorked();
    }

    void displayHoursWorked() {
        cout << "Saved successfully.\n\n";
    }
};

void printEmployeeDetails(Employee *showEmployee) {
    showEmployee->display();
}

int main() {
    PartTimeEmployee *employee1 = new PartTimeEmployee("Adrian Dominic Tan", 10001, 325.50);
    FullTimeEmployee *employee2 = new FullTimeEmployee("Khryss Nicole Bermejo", 10002, 350.50);

    Employee *allEmployees[] = {employee1, employee2};

    for (Employee *emp : allEmployees) {
        printEmployeeDetails(emp);
    }

    delete employee1, employee2;

    return 0;
}
