#include <cmath>
#include <iostream>
#include <limits>
using namespace std;
// Write a program that solves a quadratic equation using a, b, and c values
void solve_quadratic_equation(double& a, double& b, double& c) {
    double positiveQuadEquation, negativeQuadEquation;

    // Solve quadratic equation
    positiveQuadEquation = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    negativeQuadEquation = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

    // Display results
    cout << "x1 = " << positiveQuadEquation << '\n';
    cout << "x2 = " << negativeQuadEquation;
}

int main() {
    double a, b, c;

    while (true) {
        // Prompt user to enter values for a, b, c
        cout << "Enter values for a, b, c: ";
        cin >> a >> b >> c;

        // ERROR: Type mismatch
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "[ ERROR | Invalid number/s ]\n";
        } else break;
    }
    solve_quadratic_equation(a, b, c);
    return 0;
}