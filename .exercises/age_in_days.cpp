#include <iostream>
using namespace std;
// CC 202: Lab Exercise 2
// [#2] Write a program that calculates a person's age in days based on their age in years
int main() {
    int age; // Declare variables

    // Takes input from user
    cout << "Enter your age(yrs.): ";
    cin >> age;

    // Algorithm to convert age in (years -> days)
    // Used '*=', which is a shortcut of 'age = age * 365;'
    age *= 365;

    // Display result
    cout << "You are " << age << " days old!";
    
    return 0;
}
