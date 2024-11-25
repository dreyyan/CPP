#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    // Declare Variables
    int sum = 0;
    string num;

    // Prompt User to Enter an Integer
    cout << "Enter an integer: ";
    getline(cin, num);

    cout << "Individual digits: ";
    // Looping
    for (size_t i = 0; i < num.length(); i++) {
        // Ignores Non-Digits
        if (!isdigit(num[i])) {
            continue;
        }
        cout << num[i] - '0' << ' '; // Display Individual Digits
        sum += num[i] - '0'; // Calculate Sum
    }
    cout << "\nSum of the digits: " << sum; // Display Sum

    return 0;
}
