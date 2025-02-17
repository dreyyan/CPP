#include <iostream>
using namespace std;
// CC 202: Lab Exercise 2
// [#1] Write a program that prompts the user to input 2 numbers, calculates, and performs arithmetic operations using prompted values
int main() {
    double x, y; // Declare variables

    // Takes input from user
    cout << "Enter x value: ";
    cin >> x;
    cout << "Enter y value: ";
    cin >> y;

    // Display results
    cout << "\nAddition |\n";
    cout << x << " + " << y << " = " << x + y;
    cout << "\nSubtraction |\n";
    cout << x << " - " << y << " = " << x - y;
    cout << "\nMultiplication |\n";
    cout << x << " * " << y << " = " << x * y;
    cout << "\nDivision |\n";
    cout << x << " / " << y << " = " << x / y;

    return 0;
}
