#include <iostream>
using namespace std;
// CC 202 - Exercise 9C
void display_format(size_t length) {
    for (size_t i = 0; i < length; ++i) {
        cout << '-';
    } cout << '\n';
}

void do_while_num(int first_number, int second_number) {
    int sumOfEvenNumbers = 0, sumOfOddNumberSquares = 0, counter = first_number, squareCounter = 1;
    char firstLetter = 'A';
    display_format(40);

    // [b] Odd Numbers Between the Numbers
    cout << "Odd numbers between " << first_number << "-" << second_number << ": ";
    do {
        if (counter % 2 != 0) {
            cout << counter << ' ';
            sumOfOddNumberSquares += counter * counter;
        } else {
            sumOfEvenNumbers += counter;
        }
        counter++;
    } while (counter < second_number);
    cout << '\n'; display_format(40);

    // [c] Sum of Even Numbers
    cout << "Sum of All Even Numbers between " << first_number << "-" << second_number << ": " << sumOfEvenNumbers << '\n';
    display_format(40);

    // [d] Squares of Numbers 1-10
    cout << "Squares of Numbers 1-10:\n";
    do {
        cout << squareCounter << ": " << squareCounter * squareCounter << '\n';
        squareCounter++;
    } while (squareCounter <= 10);
    display_format(40);

    // [e] Output Sum of Odd Number Squares
    cout << "Sum of Squares of Odd Numbers between " << first_number << "-" << second_number << ": " << sumOfOddNumberSquares << '\n';
    display_format(40);

    // [f] Output All Uppercase Letters
    cout << "Letters in the Alphabet(Uppercase):\n";
    do {
        cout << firstLetter << ' ';
        firstLetter++;
    } while (firstLetter <= 'Z');
}

int main() {
    int num1, num2;
    while (true) {
        cout << "* 1st number < 2nd number\n"; // Display restriction
        cout << "Enter 1st & 2nd Number: ";
        cin >> num1 >> num2;

        if (num1 >= num2) {
            cerr << "[ ERROR | First number should be less than second number ]\n";
        } else break;
    }

    do_while_num(num1, num2);
    return 0;
}