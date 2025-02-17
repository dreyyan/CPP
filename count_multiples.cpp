#include <iostream>
using namespace std;
// Write a program that takes in an integer and counts the multiples from 1 to the specified integer
int main() {
    int number;
    int two_multiples = 0, three_multiples = 0, four_multiples = 0, five_multiples = 0, six_multiples = 0, seven_multiples = 0, eight_multiples = 0,
    nine_multiples = 0, ten_multiples = 0;
    while (true) {
        // Prompt User to Enter Integer
        cout << "Enter an Integer[n > 1]: ";
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cerr << "[ ERROR | Invalid number ]\n";
        } else if (number <= 1) {
            cerr << "[ ERROR | Number must be greater than 1 ]\n";
        } else { break; }
    }

    // Count All Numbers' Multiples
    for (size_t i = 2; i < number; ++i) {
        if (i % 2 == 0) { ++two_multiples; }
        if (i % 3 == 0) { ++three_multiples; }
        if (i % 4 == 0) { ++four_multiples; }
        if (i % 5 == 0) { ++five_multiples; }
        if (i % 6 == 0) { ++six_multiples; }
        if (i % 7 == 0) { ++seven_multiples; }
        if (i % 8 == 0) { ++eight_multiples; }
        if (i % 9 == 0) { ++nine_multiples; }
        if (i % 10 == 0) { ++ten_multiples; }
    }

    // Display All Numbers' Multiples
    cout << "Multiples of:\n";
    cout << "2: " << two_multiples << '\n';
    cout << "3: " << three_multiples << '\n';
    cout << "4: " << four_multiples << '\n';
    cout << "5: " << five_multiples << '\n';
    cout << "6: " << six_multiples << '\n';
    cout << "7: " << seven_multiples << '\n';
    cout << "8: " << eight_multiples << '\n';
    cout << "9: " << nine_multiples << '\n';
    cout << "10: " << ten_multiples << '\n';
    return 0;
}
