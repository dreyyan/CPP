#include <iostream>
using namespace std;

swapPtr(double* numPtr1, double* numPtr2) {
    double temp;
    temp = *numPtr2;
    *numPtr2 = *numPtr1;
    *numPtr1 = temp;

    cout << "\nAfter Swap: ";
    cout << "\n#1: " << *numPtr1;
    cout << "\n#2: " << *numPtr2;
}

int main() {
    double num1 = 1, num2 = 2;
    cout << "Before Swap: ";
    cout << "\n#1: " << num1;
    cout << "\n#2: " << num2;
    swapPtr(&num1, &num2);
    return 0;
}