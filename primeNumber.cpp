#include <iostream>
using namespace std;

int main() {
    int num;
    bool isPrime = true;

    do {
        cout << "Enter a number: ";
        cin >> num;

        if (num <= 1) {
            cout << "Invalid Input. Number must be greater than 1.\n";
        }
    } while (num <= 1);

    for (size_t i = num - 1; i > 1; i--) {
        if (num % i == 0) {
            isPrime = false;
            cout << num << " is a composite number.";
            break;
        }
    }

    if (isPrime) {
        cout << num << " is a prime number.";
    }

    return 0;
}
