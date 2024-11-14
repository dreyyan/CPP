// Exercise 4
#include <iostream>
using namespace std;

int main() {
    // Declare Variables
    int num;

    // Prompt User to Enter Positive Integer
    cout << "Enter a positive integer: ";
    cin >> num;

    // Loop: Prime Checker
    for (int i = num - 1; i >= 0; i--) {
        // Input Handling: 1
        if (num == 1) {
            cout << "1 is neither prime nor composite.";
            break;
        }
        // Input Handling: 2
        if (num == 2) {
            cout << num << " is prime.";
            break;
        }
        // Input Handling: Composite
        if (num % i == 0) {
            cout << num << " is composite.";
            break;
        }
        // Input Handling: Prime
        if (i == 2) {
            cout << num << " is prime.";
            break;
        }
    }
    return 0;
}