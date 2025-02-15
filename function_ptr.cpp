#include <iostream>
using namespace std;

void inputNumber(double *pNum1, double *pNum2) {
    cout << "Enter 1st Number: ";
    cin >> *pNum1;
    cout << "Enter 2nd Number: ";
    cin >> *pNum2;
    
    cout << "#1: " << *pNum1;
    cout << "\n#2: " << *pNum2;
}

double sum(double *pNum1, double *pNum2) {
    return *pNum1 + *pNum2;
}

int main() {
    double num1, num2;
    void(*inputPtr)(double*, double*) = inputNumber;
    inputPtr(&num1, &num2);
    double(*sumPtr)(double*, double*) = sum;
    cout << "\nSum = " << sumPtr(&num1, &num2);
    return 0;
}
