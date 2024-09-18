#include <iostream>
using namespace std;

int main() {
    double celsius, fahrenheit;
    char input;

    cout << "Celsius(c) / Fahrenheit(f): ";
    cin >> input;

    if (input == 'c') {
        cout << "Celsius -> Fahrenheit";
        cout << "\nTemperature in Celsius: ";
        cin >> celsius;

        fahrenheit = 9.0 / 5.0 * celsius + 32.0;

        cout << celsius << "C = " << fahrenheit << "F";
    }

    if (input == 'f') {
        cout << "Fahrenheit -> Celsius";
        cout << "\nTemperature in Fahrenheit: ";
        cin >> fahrenheit;

        celsius = 5.0 / 9.0 * (fahrenheit - 32.0);

        cout << fahrenheit << "F = " << celsius << "C";
    }

    return 0;
}