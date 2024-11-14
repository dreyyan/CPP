// Exercise 3
#include <iostream>
using namespace std;

int main() {
    // Declare Variables
    int num1, num2;
    int threeMultiples, fiveMultiples;

    // Prompt User to Enter Two Integers
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    // Loop: Multiples Count by Range
    while (num1 <= num2) {
        if (num1 % 3 == 0) {
            threeMultiples++;
        } if (num1 % 5 == 0) {
            fiveMultiples++;
        }
        num1++; // Iterate
    }

    // Display Multiples Count
    cout << "Count of multiples of 3: " << threeMultiples << '\n';
    cout << "Count of multiples of 5: " << fiveMultiples;

    return 0;
}