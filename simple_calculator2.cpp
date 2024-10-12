// Exercise 4
#include<iostream>
using namespace std;

int main() {
    // Declare the variables
    int num1, num2;
    char operatorChoice;

    // Prompts the User to Input 2 Numbers & an Operator
    cout << "Enter Value for 1st Number: ";
    cin >> num1;
    cout << "\nEnter Value for 2nd Number: ";
    cin >> num2;
    cout << "\nEnter Operator[+ - * / %]: ";
    cin >> operatorChoice;

    // Displays the Result According to Operator
    // If & If-Else Statements used to determine the choice of operator stored in the variable 'operatorChoice'
    // Solved & Displayed accordingly depending on the operatorChoice

    if (operatorChoice == '+') {
        cout << num1 << " + " << num2 << " = " << num1 + num2;
    }

    else if (operatorChoice == '-') {
        cout << num1 << " - " << num2 << " = " << num1 - num2;
    }

    else if (operatorChoice == '*') {
        cout << num1 << " * " << num2 << " = " << num1 * num2;
    }

    else if (operatorChoice == '/') {
        // Nested If Statement used to Prompt an Error if Division by Zero is Calculated, which is determined if num2 is not equal(!=) to 0
        if (num2 != 0) {
            cout << num1 << " / " << num2 << " = " << num1 / num2;
        }
        else {
            cout << "\nDivision by 0 is Not Allowed.";
        }
    }

    else if (operatorChoice == '%') {
        // Nested If Statement used to Prompt an Error if Modulus by Zero is Calculated, which is determined if num2 is not equal(!=) to 0
        if (num2 != 0) {
            cout << num1 << " % " << num2 << " = " << num1 % num2;
        }
        else {
            cout << "\nModulus by 0 is Not Allowed.";
        }
    }
    else {
        cout << "\nInvalid Operator.";
    }
    return 0;
}