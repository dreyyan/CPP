#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// Write a program that calculates the GCD(Greatest Common Divisor) and LCM(Least Common Multiple)
int calculate_GCD(int a, int b) { // Formula: Euclidean Algorithm
    int GCD, remainder;
    // While b != 0, a % b, a=b & b=r, GCD = a
    while (b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int calculate_LCM(int a, int b) {
    return (a / calculate_GCD(a, b)) * b;
}

int calculate_LCM_series(const vector<int>& numbers) {
    int result = numbers[0]; // Start with the first element
    for (size_t i = 1; i < numbers.size(); i++) {
        result = calculate_LCM(result, numbers[i]); // Update LCM iteratively
    }
    return result;
}

int main() {
    int choice;
    while (true) {
        // Ask user to solve for GCD or LCM
        cout << "Solve for...\n";
        cout << "[1] | GCD\n";
        cout << "[2] | LCM\n";
        cout << ">> ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cerr << "[ ERROR | Invalid input ]\n";
        } else if (choice == 1 || choice == 2) break;
    }

    if (choice == 1) {
        int a, b;
        // Prompt user to enter two numbers
        cout << "Enter 1st & 2nd Number: ";
        cin >> a >> b;
        cout << "GCD = " << calculate_GCD(a, b); // Calculate GCD
    } else {
        int number;
        vector<int> numbers;
        cout << "Enter numbers[-1 to stop]: ";
        while (true) {
            // Prompt user to enter a series of numbers
            cin >> number;
            if (number == -1) break; // Flag-controlled
            numbers.push_back(number);
        }
        cout << "LCM = " << calculate_LCM_series(numbers);
    }
    return 0;
}