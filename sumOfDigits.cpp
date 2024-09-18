#include <iostream>
#include <string>
using namespace std;

int main() {
    string digits;
    int sumOfDigits = 0;

    cout << "Enter digits: ";
    cin >> digits;

    for (int i = 0; i < digits.length(); i++) {
        sumOfDigits += (digits[i] - '0');
    }

    cout << "Sum of digits: " << sumOfDigits;
    return 0;
}
