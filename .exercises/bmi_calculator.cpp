#include <iostream>
#include <cmath>
using namespace std;
// CC 202: Lab Exercise 1
// [#4] Write a program that calculates the BMI(Body Mass Index) using predefined weight(kg) and height(m) values
int main() {
    // Declare & initialize the variables
    double BMI;
    double weight = 55;
    double height = 1.64;

    // Algorithm to solve for BMI
    // Used '#include <cmath>' to use pow(variable, raised by) function to calculate the height^2
    BMI = weight / (pow(height, 2));

    // Outputs the BMI
    cout << "Weight: " << weight << "kg\n";
    cout << "Height: " << height << "m\n";
    cout << "BMI: " << BMI;
    return 0;
}
