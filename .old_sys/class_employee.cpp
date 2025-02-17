#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string employeeName;
    string employeeID;
    double balance;

public:
    Employee(string name, string id, double bal = 0)
        : employeeName(name), employeeID(id), balance(bal) {}

    virtual void changePay(double newPay) = 0;
    virtual double payEmployee() const = 0;
    virtual void displayEmployeeInfo() const = 0;
};

class FullTimeEmployee : public Employee {
private:
    double currentPay;

public:
    FullTimeEmployee(string employeeName, string employeeID, double balance = 0, double pay = 0)
        : Employee(employeeName, employeeID, balance), currentPay(pay) {
        cout << "\nNew Full Time Employee >> ";
        cout << "\nEmployee Name: " << employeeName;
        cout << "\nID: " << employeeID;
        cout << "\nInitial Balance: $" << balance;
    }

    void changePay(double newPay) override {
        cout << "\nCurrent Pay: $" << currentPay;
        cout << "\nNew Pay: $" << newPay;
    }

    double payEmployee() const override {
        double totalPay = balance + currentPay;
        cout << "\nPay Successful >>";
        cout << "\nNew Balance: $" << balance;
        return totalPay;
    }

    void displayEmployeeInfo() const override {
        cout << "\nEmployee Info |";
        cout << "\nEmployee Name: " << employeeName;
        cout << "\nID" << employeeID;
        cout << "\nCurrent Balance: " << balance;
        cout << "\nCurrent Pay: " << currentPay;
    }
};


int main() {
    FullTimeEmployee fte1("Adrian Tan", "117591120149", 100.50, 1200.00);
    fte1.displayEmployeeInfo();
    fte1.changePay(1300.00);
    fte1.payEmployee();

    return 0;
}