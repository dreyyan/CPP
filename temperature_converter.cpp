#include <iostream>
using namespace std;
// Write a Program that Converts a Temperature[C/F] to its Counterpart
int main() {
    int choice;
    double celsius = 0.0, fahrenheit = 0.0;

    while (true) {
        // Prompt User to Enter the Unit of Temperature to Enter
        cout << "Convert:\n";
        cout << "[1] | Celsius(C) -> Fahrenheit(F)\n";
        cout << "[2] | Fahrenheit(F) -> Celsius(C)\n";
        cout << ">> ";
        cin >> choice;
        // If Valid Choice, Exit Loop
        if (choice == 1 || choice == 2) break;
        // Display Error Message if Invalid Choice
        cerr << "[ ERROR | Invalid Choice ]\n";
        cin.clear();
        cin.ignore();
    }

    // Prompt User to Enter Solve for The Temperature
    if (choice == 1) { // If Input is Celsius
        cout << "Temp. in C: ";
        cin >> celsius;
        fahrenheit = celsius * 1.8 + 32; // Solve for Fahrenheit
        cout << celsius << "*C = " << fahrenheit << "*F\n"; // Display Result
    } else { // If Input is Fahrenheit
        cout << "Temp. in F: ";
        cin >> fahrenheit;
        celsius = (fahrenheit - 32) * 5 / 9; // Solve for Celsius
        cout << fahrenheit << "*F = " << celsius << "*C\n"; // Display Result
    }
    return 0;
}
