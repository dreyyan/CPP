#include <iostream>
using namespace std;

int calculateFactorial(int number) {
    if (number == 1) {
        return 1;
    }
    int factorial = 1;
    factorial *= number;
    return number * calculateFactorial(number - 1);
}

int main() {
    cout << calculateFactorial(5);
    return 0;
}