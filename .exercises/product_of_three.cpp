#include <iostream>
using namespace std;
// CC 202: Lab Exercise 2
// [#4] Write a program that prompts the user to enter 3 numbers, calculates, and displays the product
int main() {
    float num1, num2, num3; // Declare variables

    // Takes input from user
    cout << "Enter 1st Number: ";
    cin >> num1;
    cout << "Enter 2nd Number: ";
    cin >> num2;
    cout << "Enter 3rd Number: ";
    cin >> num3;

    // Display result
    cout << num1 << " * " << num2 << " * " << num3 << " = " << num1 * num2 * num3;

    return 0;
    }
