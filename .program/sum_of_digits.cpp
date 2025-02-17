#include <iostream>
#include <string>
using namespace std;
// Write a program that takes an integer input and displays the sum of its digits
int main() {
    string number;
    int sum_of_digits = 0;
    // Prompt User to Enter Digit
    while (true) {
        cout << "Enter an Integer: ";
        getline(cin, number);

        if (number == " ") {
            cerr << "[ ERROR | Blank Input ]\n";
        } else { break; }
    }

    // Get the Sum of Digits
    for (size_t i = 0; i < number.length(); ++i) {
        sum_of_digits += static_cast<int>(number[i]) - '0';
    }

    // Display Sum of Digits
    cout << "Sum of Digits = " << sum_of_digits << '\n';

    return 0;
}
