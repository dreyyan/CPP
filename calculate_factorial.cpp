#include <iostream>
#include <limits>
using namespace std;
// Write a program that inputs a number and calculates its factorial
void calculateFactorial() {
    int number, factorial = 1;
    // Prompt user to enter a number
    while (true) {
        cout << "Enter a number: ";
        cin >> number;

        if (cin.fail()) { // ERROR: Type mismatch
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "[ ERROR | Invalid number ]\n";
        } else if (number < 1) { // ERROR: Number is less than 1
            cout << "[ ERROR | Number must be 1 or greater ]\n";
        } else break;
    }
    for (size_t i = number; i > 1; --i) {
        factorial *= i;
        cout << i;
        if (i != 2) cout << " x ";
        else cout << " = ";
    }
    // Display factorial
    cout << factorial;
}

int main() {
    calculateFactorial();
    return 0;
}