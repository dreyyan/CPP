#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 1;
    double b = 5;
    double c = 6;
    double positiveQuadEquation, negativeQuadEquation;

    positiveQuadEquation = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    negativeQuadEquation = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

    cout << "x1 = " << positiveQuadEquation;
    cout << "\nx2 = " << negativeQuadEquation;
    return 0;
}