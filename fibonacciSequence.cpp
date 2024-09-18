#include <iostream>
using namespace std;

void fibonacciSequence() {
    int terms, wholeSum = 2;
    int num1 = 1, num2 = 1, sum = 0;

    cout << "Enter # of Terms(min.3): ";
    cin >> terms;

    cout << num1 << " + " << num2 << " + ";
    for (int i = 3; i < terms + 1; i++) {
        sum = num1 + num2;
        cout << sum;
        wholeSum += sum;


        if (i == terms) {
            cout << " = ";
            cout << wholeSum;
        }
        else {
            cout  << " + ";
        }

        num2 = num1;
        num1 = sum;
    }

}

int main() {
    fibonacciSequence();
    return 0;
}