// Exercise 9B
#include <iostream>
using namespace std;

int main() {
    // Declare Variables
    int firstNum, secondNum = 0, sumOfEvenNumbers = 0, sumOfOddNumberSquares = 0;

    cout << "Restriction: 1st number < 2nd number" << endl; // Display Restriction
    // [a] Prompt User to Input Two Integers
    cout << "Enter 1st Number: ";
    cin >> firstNum;
    cout << "Enter 2nd Number: ";
    cin >> secondNum;

    for (int i = 0;;) {
        if (firstNum >= secondNum) {
            // Error Handling: First Number must be Lesser Than Second Number
            cout << "Error. 2nd number is less than 1st number." << endl;
            cout << "Enter 2nd Number: ";
            cin >> secondNum;
        } else { // Exit Infinite Loop
            break;
        }
    }

    cout << "------------------------------------\n";

    // [b] Odd Numbers Between the Numbers
    cout << "Odd Numbers between " << firstNum << "-" << secondNum << ": ";
    for (size_t i = firstNum; i < secondNum; i++) {
        if (i % 2 != 0) { // If Odd, Display Numbers & Add to Sum of Even Numbers
            cout << i << ' ';
            sumOfOddNumberSquares += i * i;
        } else { // If Even, Add Number to Sum of Even Numbers
            sumOfEvenNumbers += i;
        }
    }

    cout << "\n------------------------------------\n";

    // [c] Sum of Even Numbers
    cout << "Sum of All Even Numbers between " << firstNum << "-" << secondNum << ": " << sumOfEvenNumbers;
    cout << "\n------------------------------------";


    // [d] Squares of Numbers 1-10
    cout << "\nSquares of Numbers 1-10:\n";
    for (size_t i = 1; i <= 10; i++) {
        cout << i << ": " << i * i << endl;
    }

    cout << "------------------------------------";

    // [e] Output Sum of Odd Number Squares
    cout << "\nSum of Squares of Odd Numbers between " << firstNum << "-" << secondNum << ": " <<  sumOfOddNumberSquares;
    cout << "\n------------------------------------\n";

    cout << "Letters in the Alphabet(Uppercase):\n";
    // [f] Output All Uppercase Letters
    for (char firstLetter = 'A'; firstLetter <= 'Z'; firstLetter++) {
        cout << firstLetter << ' ';
    }
    return 0;
}