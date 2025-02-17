#include <iostream>
using namespace std;
// CC 202: Lab Exercise 2
// [#3] Write a program that prompts the user to enter 3 individual digits, calculate, and display their sum
int main() {
    int num1, num2, num3; // Declare variables
	
	cout << "Enter 3 digits between 0-9\n";
	
    // Prompts user to enter 1st number
    // Used do-while loops to Ensure User to Enter Digits 0-9
    // Used OR(||) Operator to Set Value Ranges from 0-9
        do {
            cout << "Enter 1st number: ";
            cin >> num1;
            if (num1 < 0 || num1 > 9) {
                cout << "Invalid input. Please enter digits between 0-9.\n";
            }
        } while (num1 < 0 || num1 > 9);

    // Prompts user to enter 2nd number
    // Used do-while loops to Ensure User to Enter Digits 0-9
    // Used OR(||) Operator to Set Value Ranges from 0-9
        do {
            cout << "Enter 2nd number: ";
            cin >> num2;
            if (num2 < 0 || num2 > 9) {
                cout << "Invalid input. Please enter digits between 0-9.\n";
            }
        } while (num2 < 0 || num2 > 9);

    // Prompts user to enter 3rd number
    // Used do-while loops to Ensure User to Enter Digits 0-9
    // Used OR(||) Operator to Set Value Ranges from 0-9
    do {
        cout << "Enter 3rd number: ";
        cin >> num3;
        if (num3 < 0 || num3 > 9) {
            cout << "Invalid input. Please enter digits between 0-9.\n";
        }
        } while (num3 < 0 || num3 > 9);

    // Display results
    cout << num1 << " + " << num2 << " + " << num3 << " = " << num1 + num2 + num3;

    return 0;
    }
