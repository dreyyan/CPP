#include<iostream>
#include<cmath>
using namespace std;
// CC 202 - Exercise 5
int main() {
    // Declare Variables
    double weight, height, bmiValue;

    // Prompt User to Input for Weight(kg) & Height(m)
    cout << "Enter Weight(kg): ";
    cin >> weight;
    cout << "Enter Height(m): ";
    cin >> height;

    // Check if Valid Input
    if (weight < 0 || height < 0) {
        cout << "\nInvalid Input. Weight and Height Must be Positive.";
        return 1;
    }

    // Algorithm to solve for BMI
    bmiValue = weight / (pow(height, 2));

    // Displays the Weight, Height, BMI Value, and BMI Classification
    cout << "Weight: " << weight << "kg";
    cout << "\nHeight: " << height << "m";
    cout << "\nBMI Value: " << bmiValue;
    cout << "\nBMI Classification: ";

    // Algorithm for BMI Classification
    // If & If-Else Statements used to determine the BMI Classification according to the value of 'bmiValue'
    // Classification is displayed accordingly depending on the bmiValue
    // Used AND(&&) Operator for the Classification Ranges

    if (bmiValue < 18.5) {
        cout << "Underweight";
    }

    else if (bmiValue >= 18.5 && bmiValue < 24.9) {
        cout << "Normal Weight";
    }

    else if (bmiValue >= 25 && bmiValue < 29.9) {
        cout << "Overweight";
    }

    else {
        cout << "Obesity";
    }

    return 0;
}