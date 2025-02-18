#include <iomanip>
#include <iostream>
using namespace std;
// CC 203: Exercise 1
// [#1] Write a program that performs the following:
// 1. Declare an array 'alpha' of 50 components of type 'double'
// 2. Initialize the first 25 elements of the array equal to the square of the index variable
// 3. Initialize the last 25 elements of the array equal to thrice the index variable
// 4. Output the array up to 10 elements per line
int main() {
    // 1. Declare an array 'alpha' of 50 components of type 'double'
    double alpha[50];

    // 2. Initialize the first 25 elements of the array equal to the square of the index variable
    for (int i = 0; i < 25; ++i) {
        alpha[i] = i * i;
    }

    // 3. Initialize the last 25 elements of the array equal to thrice the index variable
    for (int j = 25; j < 50; ++j) {
        alpha[j] = 3 * j;
    }

    // 4. Output the array up to 10 elements per line
    for (int k = 0; k < 50; ++k) {
        if (k != 0 && k % 10 == 0) { // Conditional statement for printing ranges
            cout << setw(2) << '|' << setw(4) << k - 10 << " - " << k - 1; // [Opt.] Print ranges for readability
            cout << '\n';
        }
        cout << setw(4) << alpha[k] << ' '; // Display elements iteratively
    } cout << setw(2) << '|' << setw(2) << ' ' << "40 - 49\n"; // [Opt.] Print last range
    return 0;
}
