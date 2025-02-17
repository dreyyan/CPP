#include <iostream>
using namespace std;
// CC 202: Lab Exercise 1
// [#3] Write a program that calculates the simple interest using predefined values
int main() {
    // Declare & initialize variables with predefined values
    double simpleInterest;
    double principalAmount = 2400.5;
    double rateOfInterest = 4;
    double timePeriod = 2;

    // Calculate simple interest
    simpleInterest = (principalAmount * rateOfInterest * timePeriod) / 100;

    // Display the values and result
    cout << "Principal Amount: $" << principalAmount << '\n';
    cout << "Rate of Interest: " << rateOfInterest << "%\n";
    cout << "Time Period: " << timePeriod << '\n';
    cout << "Simple Interest: $" << simpleInterest;
    return 0;
}
