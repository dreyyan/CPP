#include <iostream>
using namespace std;

void fibonacciNumbersLessThan30000() {
    int num1 = 1, num2 = 1, sum = 0;
    cout << num1 << endl << num2 << endl;

    do {
        sum = num1 + num2;
        if (sum > 30000) {
            break;
        } else {
            cout << sum << endl;
        }
        num1 = num2;
        num2 = sum;

    } while (sum < 30000);
}