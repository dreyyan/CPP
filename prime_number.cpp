#include <iostream>
using namespace std;
// CC 202 - Exercise 4
// Write a program that checks whether a number is prime or not
bool is_prime(const int& number) {
    bool isPrime = true;
    for (size_t i = number - 1; i > 1; i--) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    do { // Prompt user to enter a number
        cout << "Enter a number: ";
        cin >> num;

        if (num <= 1) {
            cout << "Invalid Input. Number must be greater than 1.\n";
        }
    } while (num <= 1);
    cout << num << " is " << (is_prime(num) ? "" : "not ") << "a prime number.\n";
    return 0;
}
