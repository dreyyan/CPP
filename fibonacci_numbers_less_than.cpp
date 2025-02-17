#include <iostream>
using namespace std;
// Write a program that displays the greatest possible sum of fibonacci numbers less than the specified number
void fibonacci_numbers_less_than(int max_number) {
    int num1 = 1, num2 = 1, sum = 0;
    cout << num1 << endl << num2 << endl;

    do {
        sum = num1 + num2;
        if (sum > max_number) {
            break;
        } else {
            cout << sum << endl;
        }
        num1 = num2;
        num2 = sum;

    } while (sum < max_number);
}

int main() {
    fibonacci_numbers_less_than(5000);
    return 0;
}
