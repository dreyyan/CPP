// Exercise 9A
#include <iostream>
using namespace std;

int main() {
    // Declare Variables
    int firstNum, secondNum = 0, counter, sumOfEvenNumbers = 0, sumOfOddNumberSquares = 0, squareCounter = 1;
    char firstLetter = 'A';

    cout << "Restriction: 1st number < 2nd number" << endl; // Display Restriction
    // [a] Prompt User to Input Two Integers
    cout << "Enter 1st Number: ";
    cin >> firstNum;
    cout << "Enter 2nd Number: ";
    cin >> secondNum;

    // Error Loop
    while (firstNum >= secondNum) {
        // Error Handling: First Number must be Lesser Than Second Number
        cout << "Error. 2nd number is less than 1st number." << endl;
        cout << "Enter 2nd Number: ";
        cin >> secondNum;
    }

    counter = firstNum; // Set Counter

    cout << "------------------------------------\n";

    // [b] Odd Numbers Between the Numbers
    cout << "Odd Numbers between " << firstNum << "-" << secondNum << ": ";
    while(counter < secondNum) {
        if (counter % 2 != 0) { // If Odd, Display Numbers & Add to Sum of Even Numbers
            cout << counter << ' ';
            sumOfOddNumberSquares += counter * counter;
        } else { // If Even, Add Number to Sum of Even Numbers
            sumOfEvenNumbers += counter;
        }
        counter++;
    }

    cout << "\n------------------------------------\n";

    // [c] Sum of Even Numbers
    cout << "Sum of All Even Numbers between " << firstNum << "-" << secondNum << ": " << sumOfEvenNumbers;

    cout << "\n------------------------------------";

    // [d] Squares of Numbers 1-10
    cout << "\nSquares of Numbers 1-10:\n";
    while (squareCounter <= 10) {
        cout << squareCounter << ": " << squareCounter * squareCounter << endl;
        squareCounter++;
    }

    cout << "------------------------------------";

    // [e] Output Sum of Odd Number Squares
    cout << "\nSum of Squares of Odd Numbers between " << firstNum << "-" << secondNum << ": " <<  sumOfOddNumberSquares;

    cout << "\n------------------------------------\n";

    cout << "Letters in the Alphabet(Uppercase):\n";
    // [f] Output All Uppercase Letters
    while (firstLetter <= 'Z') {
        cout << firstLetter << ' ';
        firstLetter++;
    }
    return 0;
}