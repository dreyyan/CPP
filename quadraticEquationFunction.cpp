// Exercise 7
#include<iostream>
#include<cmath>
using namespace std;

class QuadraticEquation {
private:
    // Declare Private Variables a, b, and c
    double a, b, c;

public:
    // Function to Solve Quadratic Equation by Input Values of a, b, and c
    void solveQuadraticEquation() {
        cout << "\n| Quadratic Equation Calculator |";
        // Loop to Check if 'a' is Non-zero
        do {
            cout << "\nEnter Value for 'a': ";
            cin >> a;

            if (a == 0) {
                cout << "\nInvalid Input for 'a'. Please Enter a Non-zero Value.";
            }
        } while (a == 0);

        cout << "\nEnter Value for 'b': ";
        cin >> b;
        cout << "\nEnter Value for 'c': ";
        cin >> c;

        numberOfSolutions(); // Check Number of Solutions
        inputChoice(); // Check Choice
    }

    // Function to Determine the Number of Solutions Using Values of a, b, and c
    void numberOfSolutions() {
        // Algorithm to Solve for Discriminant
        double discriminant = (pow(b, 2)) - (4 * a * c);

        // Check Value of Discriminant
        if (discriminant > 0) {
            // 2 Diffrent Solutions [Solve for x1 & x2]
            double x1, x2;
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);

            // Display x1 and x2
            cout << "\nTwo(2) Solutions:";
            cout << "\n+x = " << x1;
            cout << "\n-x = " << x2;
        }

        else if (discriminant < 0) {
            // No Real Solution [Imaginary Solution]
            cout << "\nNo Real Solution";
        }

        else { // discriminant == 0
            // 1 Solution [Solve for x]
            double x = -b / (2 * a);
            cout << "\nOne(1) Solution:";
            cout << "\nx = " << x;
        }
    }

    // Function to Solve Another Equation or Exit Program
    void inputChoice() {
        int choice;

        // Prompt User for Choice
        cout << "\n\nWould You Like to Solve Another Equation?";
        cout << "\n[1 - Yes | 0 - No]: ";
        cin >> choice;

        // 1 - Solve Another Equation (Recursion)
        if (choice == 1) {
            solveQuadraticEquation();
        }

        // 0 - Exit Program
        else {
            cout << "\nProgram Exited Successfully.";
        }
    }
};

int main() {
    QuadraticEquation equation;
    equation.solveQuadraticEquation(); // Start Program
    return 0;
}