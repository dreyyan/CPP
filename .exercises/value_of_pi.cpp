// Exercise 10
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double pi = 0;

    // Prompt User to Enter # of Terms
    while (true) {
        cout << "Enter Value of n: ";
        cin >> n;

        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(50, '\n');
            cerr << "[ ERROR | Invalid Number ]\n";
        } else { break; }
    }

    // Solve for the Approximation of the Value of Pi [Leibniz Formula]
    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            pi += (1.0 / (2 * i + 1));
        } else {
            pi -= (1.0 / (2 * i + 1));
        }
    }

    // Multiply Pi by 4 for Correct Approximation
    pi *= 4;

    // Display the Result
    cout << fixed << setprecision(10);
    cout << "Value of Pi: " << pi << '\n';

    return 0;
}
