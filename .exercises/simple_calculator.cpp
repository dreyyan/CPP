#include <iostream>
#include <limits>
using namespace std;
// CC 202: Lab Exercise 1
// [#2] Write a program that allows you to perform basic arithmetic operations [+ - * / %] with predefined values
int main() {
    // Declare and initialize variables using predefined values
    int num1 = 4, num2 = 2;
    char operation;
    
    // Display numbers
    cout << "Number 1: " << num1 << "\nNumber 2: " << num2 << '\n';
    
    // Prompt user to input desired operation
    while (true) {
        cout << "Enter operation[+ - * / %]: ";
        cin >> operation;

        // ERROR: Invalid character
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ ERROR | Invalid character operation ]\n";
        } else break;
    }

    // Display result based on operation choice
    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
        break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
        break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
        break;
        case '/':
            if (num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            else
                cout << "Error! Division by zero.";
        break;
        case '%':
            if (num2 != 0)
                cout << num1 << " % " << num2 << " = " << num1 % num2;
            else
                cout << "Error! Modulo by zero.";
        break;
        default:
            cout << "[ ERROR | Invalid operator ]\n";
    }
    return 0;
}