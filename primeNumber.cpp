#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter number: ";
    cin >> number;

    for (int i = number - 1; i > 1; i--) {
        if (number % i == 0) {
            cout << number << " is composite. ";
            return 0;
        }
    }

    cout << number << " is prime. ";
    return 0;
}