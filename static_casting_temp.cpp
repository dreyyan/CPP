#include<iostream>
using namespace std;
// CC 202 - Exercise 3
int main() {
    int t_in_fah;
    double precise_t_in_cel;

    // Prompt user for temperature(in fahrenheit) as input
    cout << "Enter a temperature in Fahrenheit: ";
    cin >> t_in_fah;

    // Display Output
    precise_t_in_cel = (t_in_fah - 32) * 5.0 / 9.0; // Explicit static casting for temperature(in fahrenheit)
    cout << t_in_fah << "*F = " << precise_t_in_cel << "*C" << endl; // Display temperature
    return 0;
}





















