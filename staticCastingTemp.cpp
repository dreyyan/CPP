// Exercise 3
#include<iostream>
using namespace std;

int main() {
    // Declare Variables
    int t_in_fah, t_in_cel;
    double precise_t_in_cel = static_cast<double>(t_in_cel); // Explicit Static Casting for Temperature(in Celsius)

    // Prompt User for Temperature(in Fahrenheit) as Input
    cout << "Enter a temperature in Fahrenheit: ";
    cin >> t_in_fah;

    // Display Output
    precise_t_in_cel = static_cast<double>(t_in_fah - 32) * 5.0 / 9.0; // Explicit Static Casting for Temperature(in Fahrenheit)
    cout << t_in_fah << "*F = " << precise_t_in_cel << "*C" << endl;
    return 0;
}





















