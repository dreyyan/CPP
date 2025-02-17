#include <iostream>
using namespace std;
// CC 202 - Exercise 9B
void display_format(size_t length) {
    for (size_t i = 0; i < length; ++i) {
        cout << '-';
    } cout << '\n';
}
void for_num(int first_number, int second_number) {
    int sumOfEvenNumbers = 0, sumOfOddNumberSquares = 0;
    char firstLetter = 'A';
    display_format(40);

    // [b] Odd Numbers Between the Numbers
    cout << "Odd numbers between " << first_number << "-" << second_number << ": ";
    for (int i = first_number; i < second_number; i++) {
        if (i % 2 != 0) { // If Odd, Display Numbers & Add to Sum of Odd Number Squares
            cout << i << ' ';
            sumOfOddNumberSquares += i * i;
        } else { // If Even, Add Number to Sum of Even Numbers
            sumOfEvenNumbers += i;
        }
    } cout << '\n'; display_format(40);

    // [c] Sum of Even Numbers
    cout << "Sum of All Even Numbers between " << first_number << "-" << second_number << ": " << sumOfEvenNumbers << '\n';
    display_format(40);

    // [d] Squares of Numbers 1-10
    cout << "Squares of Numbers 1-10:\n";
    for (int i = 1; i <= 10; i++) {
        cout << i << ": " << i * i << '\n';
    } display_format(40);

    // [e] Output Sum of Odd Number Squares
    cout << "Sum of Squares of Odd Numbers between " << first_number << "-" << second_number << ": " << sumOfOddNumberSquares << '\n';
    display_format(40);
    
    // [f] Output All Uppercase Letters
    cout << "Letters in the Alphabet(Uppercase):\n";
    for (; firstLetter <= 'Z'; firstLetter++) {
        cout << firstLetter << ' ';
    }
}

int main() {
    int num1, num2;
    while (true) {
        cout << "* 1st number < 2nd number\n"; // Display restriction
        // [a] Prompt User to Input Two Integers
        cout << "Enter 1st & 2nd Number: ";
        cin >> num1 >> num2;

        if (num1 >= num2) {
            cerr << "[ ERROR | First number should be less than second number ]\n";
        } else break;
    }
    
    for_num(num1, num2); // Invoke function
    return 0;
}